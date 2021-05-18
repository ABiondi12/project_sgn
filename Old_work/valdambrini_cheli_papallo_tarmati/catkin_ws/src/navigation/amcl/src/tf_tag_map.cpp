//NODO PER LA PUBBLICAZIONE DI UN MESSAGGIO DI TIPO Point CONTENENTE LE COORDINATE DEL SISTEMA DI RIFERIMENTO MAP NEL SISTEMA DI RIFERIMENTO UWB. L'INFORMAZIONE OTTENUTA È DISPONIBILE SOLAMENTE QUANDO VIENE ACQUISITA LA MAPPA

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


double var=0;
double it=0;
double count=1;

double xmap;
double ymap;
double zmap;
double thetamap;  
//creazione di due array di 50 campioni 
double array_x[50];
double array_y[50];

double k=50;

double sum_x;
double sum_y;

double mean0x;
double mean0y;

geometry_msgs::Point uwb0; //variabile per tag0 posizionata anteriormente 
geometry_msgs::Point orien; //variabile per orientazione fornita dalla STM


void tagpose0_Callback(const geometry_msgs::Point::ConstPtr& tag0)
{
      //dati forniti dalle uwb [mm]
      uwb0.x=(tag0->x); 
      uwb0.y=(tag0->y);
      uwb0.z=(tag0->z); 
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
ros::init(argc, argv, "tf_tag_map");
ros::NodeHandle n;

 //sottoscrizione al topic "tag_pose0" 
ros::Subscriber sub_tag0 = n.subscribe("/tag_pose0", 1000, tagpose0_Callback);

 //sottoscrizione al topic "orientation" 
ros::Subscriber sub_or = n.subscribe("/orientation", 1000, orientation_Callback);

 // pubblicazione sul topic "tf_tag2map"
ros::Publisher pub = n.advertise< geometry_msgs::Point>("/tf_tag2map", 1000);

 // frequenza di pubblicazione del nodo 
ros::Rate loop_rate(10);


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
   
}

//coordinate del sistema di riferimento map ottenute con una media dei primi 50 campioni a disposizione 
if (it==51)
{
//è stato aggiunto al valor medio un fattore di correzione per avere frame map posizionato in     corrispondenza del laser e non della uwb_0
    xmap=mean0x + 0.13*sin(-orien.z) ; 
    ymap=mean0y - 0.13*cos(-orien.z);
    zmap= 0;
    thetamap=-orien.z; // l'orientamento dato dalla STM è in un sistema di riferimento Z-down
    
    std::cout << "x.map: " << xmap << ", y.map: " << ymap << "z.map " << zmap << "theta.map: " << thetamap <<std::endl;
    ROS_INFO ("Il robot può muoversi");
    
    geometry_msgs::Point tf; //variabile per la trasformata da tag a map
      tf.x=xmap;
      tf.y=ymap;
      tf.z=thetamap;

    pub.publish(tf); //pubblicazione sul topic tf
}

// ciclo per salvare nell'array i primi 50 campioni di uwb0 
for (int i=0; i<k; i++)
{ 
if (i==k-1)
{ array_x[i]=uwb0.x;
array_y[i]=uwb0.y; 
}
else { 
array_x[i]=array_x[i+1];
array_y[i]=array_y[i+1];
std::cout << "array_x: " << array_x <<std::endl;
std::cout << "array_y: " << array_y <<std::endl;
}
}


      ros::spinOnce();
      
      loop_rate.sleep();
      
   }

   return 0;
 }
