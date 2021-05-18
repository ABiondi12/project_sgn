//NODO CHE PUBBLICA LA POSIZIONE INIZIALE CALCOLATA COME MEDIA DEI PRIMI 10 CAMPIONI DELLA UWB_0

#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Point.h"
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

 //creazione di due array di 10 campioni 
double array_x[10]; 
double array_y[10];

double k=10;

double sum_x;
double sum_y;

double angle;
double angle_body;


geometry_msgs::Point uwb0; //variabile per tag0 posizionata anteriormente 
geometry_msgs::Point orien; //variabile per orientazione fornita dalla STM

 // coordinate del sistema di riferimento map in sistema di riferimento ancore 
double map_x = 2.05;
double map_y = 1.73;
double map_z = 0.0; //orientamento [rad]

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
ros::init(argc, argv, "initialpose");
ros::NodeHandle n;

//sottoscrizione al topic "tag_pose0" 
ros::Subscriber sub_tag0 = n.subscribe("/tag_pose0", 1000, tagpose0_Callback);

//sottoscrizione al topic "orientation" 
ros::Subscriber sub_or = n.subscribe("/orientation", 1000, orientation_Callback);

// pubblicazione sul topic "initialpose"
ros::Publisher pub = n.advertise< geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1000);



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
// ciclo per sommare gli elementi presenti nell'array
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
    std::cout << "iterazione" << it <<std::endl;
}

 //posa iniziale del robot ottenuta con una media mobile sui primi 10 campioni a disposizione 
if (it==k+1)
{
   // posa espressa nel sistema di riferimento uwb
    xodom=mean0x;
    yodom=mean0y;
    zodom= 0;
    thetaodom=-orien.z; // l'orientamento dato dalla STM è in un sistema di riferimento Z-down
    std::cout << "x.odom: " << xodom << ", y.odom: " << yodom << "z.odom " << zodom << "thetaodom: "    << thetaodom <<std::endl;
     
      
      geometry_msgs::PoseWithCovarianceStamped pose_in;//variabile per initial pose
      pose_in.header.seq = 2;
      pose_in.header.stamp= ros::Time::now();
      pose_in.header.frame_id = "map";
      //utilizzata una matrice di rototraslazione per portare da frame uwb a frame map
  pose_in.pose.pose.position.x = ((cos(map_z))*xodom)+((sin(map_z))*yodom)-((cos(map_z))*(map_x))-((sin(map_z))*(map_y));
      pose_in.pose.pose.position.y = ((-sin(map_z))*xodom)+((cos(map_z))*yodom)+((sin(map_z))*(map_x))-((cos(map_z))*(map_y));
      pose_in.pose.pose.position.z = zodom;
      
      tf2::Quaternion myQuaternion; //inizializzazione quaternione
      angle=thetaodom-map_z;
      
 //correzione dell'angolo per limitarlo in un intervallo di +- 3.14
      if (angle > 3.1459) 
      { angle=angle-6.2918; 
       }
      if (angle < -3.1459)
      { angle=angle+6.2918; 
       }
      
      myQuaternion.setRPY(0.0, 0.0, angle);
      pose_in.pose.pose.orientation = tf2::toMsg(myQuaternion);

// simulazione di una covarianza
pose_in.pose.covariance[0]=0.25;
pose_in.pose.covariance[1]=0;
pose_in.pose.covariance[2]=0;
pose_in.pose.covariance[3]=0;
pose_in.pose.covariance[4]=0;
pose_in.pose.covariance[5]=0;
pose_in.pose.covariance[6]=0;
pose_in.pose.covariance[7]=0;
pose_in.pose.covariance[8]=0;
pose_in.pose.covariance[9]=0;
pose_in.pose.covariance[10]=0;
pose_in.pose.covariance[11]=0;
pose_in.pose.covariance[12]=0;
pose_in.pose.covariance[13]=0;
pose_in.pose.covariance[14]=0;
pose_in.pose.covariance[15]=0;
pose_in.pose.covariance[16]=0.25;
pose_in.pose.covariance[17]=0;
pose_in.pose.covariance[18]=0;
pose_in.pose.covariance[19]=0;
pose_in.pose.covariance[20]=0;
pose_in.pose.covariance[21]=0;
pose_in.pose.covariance[22]=0;
pose_in.pose.covariance[23]=0;
pose_in.pose.covariance[24]=0;
pose_in.pose.covariance[25]=0;
pose_in.pose.covariance[26]=0;
pose_in.pose.covariance[27]=0;
pose_in.pose.covariance[28]=0;
pose_in.pose.covariance[29]=0.25;
pose_in.pose.covariance[30]=0;
pose_in.pose.covariance[31]=0;
pose_in.pose.covariance[32]=0;
pose_in.pose.covariance[33]=0;
pose_in.pose.covariance[34]=0;
pose_in.pose.covariance[35]=0;
    pub.publish(pose_in);
}
   
    
 // scorrimento degli elementi dell'array per fare la media mobile
for (int i=0; i<k; i++)
{ 
if (i==k-1)
{ array_x[i]=uwb0.x;
array_y[i]=uwb0.y; 
}
else { 
array_x[i]=array_x[i+1];
array_y[i]=array_y[i+1];

}
}


      ros::spinOnce();
      
      loop_rate.sleep();
       
   }

   return 0;
 }
