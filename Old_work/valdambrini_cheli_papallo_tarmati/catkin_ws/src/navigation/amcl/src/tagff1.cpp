// NODO PER CALCOLARE LA POSIZIONE DEL ROBOT RISPETTO AL FRAME ODOM CON LA TECNICA DEL FADING FILTER A PARTIRE DAI DATI FORNITI DALLE UWB
#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Pose.h"
#include "tf/tfMessage.h"
#include "tf/transform_broadcaster.h"
#include "math.h"
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

double ff_x; 
double ff_y;

double pre_x;
double pre_y;

double xbody;
double ybody;
double zbody;
double thetabody;

 //creazione di due array di 5 campioni 
double array_x[5]; 
double array_y[5];

double k=5;

double sum_x;
double sum_y;

double angle;
double angle_body;
double beta=0.7; //guadagno del Fading Filter


geometry_msgs::Point uwb0; //variabile per tag0 posizionata anteriormente 
geometry_msgs::Point orien; //variabile per orientazione fornita dalla STM
geometry_msgs::Point tag_ff; //variabile per posizione filtrata con Fading Filter
geometry_msgs::Point tag_matlab0; //variabile per la posizione fltrata della tag0 da utilizzare in ambiente Matlab

 // coordinate del sistema di riferimento map in sistema di riferimento ancore 
double map_x = 2.05;
double map_y = 1.73;
double map_z = 0.0;


void tagpose0_Callback(const geometry_msgs::Point::ConstPtr& tag0)
{
//dati forniti dalle uwb [mm]
      uwb0.x=(tag0->x)/1000; 
      uwb0.y=(tag0->y)/1000;
      uwb0.z=(tag0->z)/1000; 
}


void orientation_Callback(const geometry_msgs::Point::ConstPtr& orientation)
{
//orientazione data dalla STM [rad]
      orien.x=(orientation->x); 
      orien.y=(orientation->y);
      orien.z=(orientation->z); 
}


int main(int argc, char **argv)
{
 //inizialiazzazione nodo 
ros::init(argc, argv, "tagff1");
ros::NodeHandle n;

 //sottoscrizione al topic "tag_pose0" 
ros::Subscriber sub_tag0 = n.subscribe("/tag_pose0", 1000, tagpose0_Callback);

 //sottoscrizione al topic "orientation" 
ros::Subscriber sub_or = n.subscribe("/orientation", 1000, orientation_Callback);

 // pubblicazione sul topic "tag_ff1"
ros::Publisher pubff = n.advertise< geometry_msgs::Point>("/tag_ff1", 1000);

 // pubblicazione sul topic "tag_matlab0_ff1"
ros::Publisher pubtag = n.advertise< geometry_msgs::Point>("/tag_matlab0_ff1", 1000);

// inizializzazione della trasformata
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

 //aggiornamento iterazione durante acquisizione dei valori
if (var==1) 
{
    it=it+1;
    
}


if (it==k+1)
{
  //somma dei primi 5 campioni della uwb_0 
for (int i=0; i<k; i++)
{ 
 sum_x=sum_x+array_x[i];
 sum_y=sum_y+array_y[i];
}
ff_x=sum_x/k; 
ff_y=sum_y/k;

  // coordinate frame odom
    xodom=ff_x;
    yodom=ff_y;
    zodom= 0; 
    thetaodom=-orien.z; // l'orientamento dato dalla STM è in un sistema di riferimento Z-down
    
    std::cout << "x.odom: " << xodom << ", y.odom: " << yodom << "z.odom " << zodom << "thetaodom: " << thetaodom <<std::endl;
}   
 

if (it>k+1)
{
//calcolo delle componenti x e y (e delle loro derivate) del robot tramite filtro Fading Filter del 2°ordine
ff_x=pre_x+(1-beta)*(uwb0.x-pre_x); 
ff_y=pre_y+(1-beta)*(uwb0.y-pre_y);
std::cout << "ff_x: " << ff_x <<std::endl;
std::cout << "ff_y: " << ff_y <<std::endl;
}

 //condizione di non fallimento delle tag e calcolo della posizione del body rispetto a odom
if ((ff_x!=pre_x) && (ff_y!=pre_y) && var!=0 && it>=k+2)
{ 
    xbody= ff_x*cos(thetaodom) + ff_y*sin(thetaodom) - cos(thetaodom)*xodom - sin(thetaodom)*yodom;
    ybody= -ff_x*sin(thetaodom) + ff_y*cos(thetaodom) + sin(thetaodom)*xodom - cos(thetaodom)*yodom;
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
if ((ff_x==pre_x) && (ff_y==pre_y) && var!=0 && it>=k+2)   

{
     xbody= ff_x*cos(thetaodom) + ff_y*sin(thetaodom) - cos(thetaodom)*xodom - sin(thetaodom)*yodom +0.002*count;
    ybody= -ff_x*sin(thetaodom) + ff_y*cos(thetaodom) + sin(thetaodom)*xodom - cos(thetaodom)*yodom +0.002*count;
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
 
 
 //pubblicazione trasformata tra odom e base_link
    transform.setOrigin( tf::Vector3(xbody, ybody, zbody) );
    tf::Quaternion q;
    q.setRPY(0, 0, thetabody);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "odom", "base_link_ff1"));
    
 //pubblicazione della posizione del robot filtrata sul topic tag_ff1
    tag_ff.x=ff_x;
    tag_ff.y=ff_y;
    tag_ff.z=-orien.z;
    pubff.publish(tag_ff);
    
 // pubblicazione del valore della tag0 sul topic tag_matlab0_ff1
     tag_matlab0.x=uwb0.x;
     tag_matlab0.y=uwb0.y;
     tag_matlab0.z=uwb0.z; 
     pubtag.publish(tag_matlab0);

    std::cout << "x.odom: " << xodom << ", y.odom: " << yodom << "z.odom " << zodom << "thetaodom: " << thetaodom <<std::endl;
    std::cout << " orientation " << -orien.z <<std::endl;
    std::cout << "body.x: " << xbody << ", body.y: " << ybody << "body.z: " << zbody << "body.theta: " << thetabody <<std::endl;
       
    
 // ciclo per salvare nell'array i primi 5 campioni di uwb0 
if (it<k+3)
{ 
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
}
 //variabili di appoggio per salvare il valore precedente in uscita dal Fading Filter 
pre_x=ff_x;
pre_y=ff_y;

      ros::spinOnce();
      
      loop_rate.sleep();
      
   }

   return 0;
 }
