// NODO PER CALCOLARE LA POSIZIONE DEL ROBOT CON LA TECNICA DI FILTRAGGIO A MEDIA MOBILE A PARTIRE DAI DATI FORNITI DALLE UWB

#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Pose.h"
#include "tf/tfMessage.h"
#include "tf/transform_broadcaster.h"
#include "math.h"
#include <cmath>
#include <vector> 
#include "tf/transform_listener.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf/transform_datatypes.h>
#include <iostream>
#include <algorithm>


double var=0;
double it=0;
double count=1;

double xodom;
double yodom;
double zodom;
double thetaodom;  

double mean0x;
double mean0y;

double premeanx;
double premeany;

double xbody;
double ybody;
double zbody;
double thetabody;

double k=5; 
 // creazione di due array di 5 campioni
double array_x[5];
double array_y[5];

double sum_x;
double sum_y;

double angle;
double angle_body;


geometry_msgs::Point uwb0; //variabile per tag0 posizionata anteriormente 
geometry_msgs::Point orien; //variabile per orientazione fornita dalla STM
geometry_msgs::Point tag_mean; //variabile per posizione filtrata con filtro a media mobile
geometry_msgs::Point tag_matlab0; //variabile per la posizione fltrata della tag0 da utilizzare in ambiente Matlab

 // coordinate del sistema di riferimento map in sistema di riferimento ancore 
double map_x = 2.05;
double map_y = 1.73;
double map_z = 0.0;

void tagpose0_Callback(const geometry_msgs::Point::ConstPtr& tag0)
{
      uwb0.x=(tag0->x)/1000; //posa in [m]
      uwb0.y=(tag0->y)/1000;
      uwb0.z=(tag0->z)/1000; 
}


void orientation_Callback(const geometry_msgs::Point::ConstPtr& orientation)
{
      orien.x=(orientation->x); //orientazione in [rad]
      orien.y=(orientation->y);
      orien.z=(orientation->z); 
}


int main(int argc, char **argv)
{
 //inizialiazzazione nodo 
ros::init(argc, argv, "tagmean");
ros::NodeHandle n;

 //sottoscrizione al topic "tagpose0" 
ros::Subscriber sub_tag0 = n.subscribe("/tag_pose0", 1000, tagpose0_Callback);

 //sottoscrizione al topic "orientation" 
ros::Subscriber sub_or = n.subscribe("/orientation", 1000, orientation_Callback);

 // pubblicazione sul topic "tag_mean"
ros::Publisher pubmean = n.advertise< geometry_msgs::Point>("/tag_mean", 1000);

 // pubblicazione sul topic "tag_matlab0_mean"
ros::Publisher pubtag = n.advertise< geometry_msgs::Point>("/tag_matlab0_mean", 1000);

 // creazione della trasformata
static tf::TransformBroadcaster br;
tf::Transform transform;

 // frequenza di pubblicazione del nodo
ros::Rate loop_rate(5);


   while (ros::ok())
   {
   
 //variabile var=1 se uwb0 inizia a pubblicare valori        
if (uwb0.x!=0 && uwb0.y!=0 && uwb0.z!=0 && var==0)
{ 
    var=1;   
}


if (var==1) 
{

// ciclo per calcolare la somma di 5 campioni 
for (int i=0; i<k; i++)
{ 
 sum_x=sum_x+array_x[i];
 sum_y=sum_y+array_y[i];
}

mean0x=sum_x/k;
mean0y=sum_y/k;
sum_x=0;
sum_y=0;
    it=it+1; //aggiornamento iterazione durante acquisizione dei valori
   
}


 //posizione del robot ottenuta con una media mobile sui primi 5 campioni a disposizione 
if (it==k+1)
{
// coordinate frame odom
    xodom=mean0x;
    yodom=mean0y;
    zodom= 0;
    thetaodom=-orien.z; // l'orientamento dato dalla STM è in un sistema di riferimento Z-down
    std::cout << "x.odom: " << xodom << ", y.odom: " << yodom << "z.odom " << zodom << "thetaodom: "    << thetaodom <<std::endl;

}
  

 //condizione di non fallimento delle tag e calcolo della posizione del body rispetto a odom
if ((mean0x!=premeanx) && (mean0y!=premeany) && var!=0 && it>=k+2)
{ 
    xbody= mean0x*cos(thetaodom) + mean0y*sin(thetaodom) - cos(thetaodom)*xodom - sin(thetaodom)*yodom;
    ybody= -mean0x*sin(thetaodom) + mean0y*cos(thetaodom) + sin(thetaodom)*xodom - cos(thetaodom)*yodom;
    zbody= 0;
    angle_body= -orien.z-thetaodom;
   
 //correzione dell'angolo per limitarlo in un intervallo di +- 3.14
if (angle_body > 3.1459) 
      { angle_body=angle_body-6.2918; 
       }
      if (angle_body < -3.1459)
      { angle_body=angle_body+6.2918; 
       }
      thetabody=angle_body;
    
    count=1;
}

// condizione di fallimento delle tag e aggiornamento della posizione incrementando di 2 mm
if ((mean0x==premeanx) && (mean0y==premeany) && var!=0 && it>=k+2)   

{
    
    xbody= (mean0x*cos(thetaodom)) + (mean0y*sin(thetaodom)) + (xodom +0.002*count);
    ybody= (-mean0x*sin(thetaodom)) + (mean0y*cos(thetaodom)) + (yodom +0.002*count);
    zbody= 0;
    angle_body= -orien.z-thetaodom;
    
 //correzione dell'angolo per limitarlo in un intervallo di +- 3.14
      if (angle_body > 3.1459) 
      { angle_body=angle_body-6.2918; 
       }
      if (angle_body < -3.1459)
      { angle_body=angle_body+6.2918; 
       }
      thetabody=angle_body;
 //variabile per contare quante volte falliscono le tag
    count=count+1;
}
   
 //pubblicazione trasformata fra odom e base_link
    transform.setOrigin( tf::Vector3(xbody, ybody, zbody) );
    tf::Quaternion q;
    q.setRPY(0, 0, thetabody);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "odom", "base_link_mean"));
    
 //pubblicazione della posizione del robot filtrata sul topic tag_mean
    tag_mean.x=mean0x;
    tag_mean.y=mean0y;
    tag_mean.z=-orien.z;
    pubmean.publish(tag_mean);
      
 // pubblicazione del valore della tag0 sul topic tag_matlab0
      tag_matlab0.x=uwb0.x;
      tag_matlab0.y=uwb0.y;
      tag_matlab0. z=uwb0.z; 
      pubtag.publish(tag_matlab0);


    std::cout << "x.odom: " << xodom << ", y.odom: " << yodom << "z.odom " << zodom << "thetaodom: " << thetaodom <<std::endl;
    std::cout << " orientation " << -orien.z <<std::endl;
    std::cout << "body.x: " << xbody << ", body.y: " << ybody << "body.z: " << zbody << "body.theta: " << thetabody <<std::endl;
    std::cout << "tag_mean.x: " << tag_mean.x << ", tag_mean.y: " << tag_mean.y << "tag_mean.z: " << tag_mean.z <<std::endl;
    
 // scorrimento degli elementi dell'array per fare la media mobile
for (int i=0; i<k; i++)
{ 
if (i==k-1)
{ array_x[i]=uwb0.x;
array_y[i]=uwb0.y; 
}
else 
{ 
array_x[i]=array_x[i+1];
array_y[i]=array_y[i+1];

}
}

 //variabili di appoggio per salvare il valore precedente in uscita dal filtro a media mobile  
premeanx=mean0x;
premeany=mean0y;

      ros::spinOnce();
      
      loop_rate.sleep();
      
   }

   return 0;
 }
