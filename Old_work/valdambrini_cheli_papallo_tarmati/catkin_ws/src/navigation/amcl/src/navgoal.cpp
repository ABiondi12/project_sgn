//nodo per mandare waypoint a Matlab tramite Rviz per il controllo. L'utente tramite il tasto "2D nav goal" puo' selezionare sulla mappa il punto che vuole far raggiungere al robot 

#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseStamped.h"
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



//inizializzazione variabili
geometry_msgs::PoseStamped goal; 
geometry_msgs::Point waypoint; 


//callback per l'acquisizione del waypoint dal topic move_base_simple/goal
void goal_Callback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
      goal.pose.position.x=(msg->pose.position.x);
      goal.pose.position.y=(msg->pose.position.y);
      goal.pose.orientation.x=(msg->pose.orientation.x);
      goal.pose.orientation.y=(msg->pose.orientation.y);
      goal.pose.orientation.z=(msg->pose.orientation.z);
      goal.pose.orientation.w=(msg->pose.orientation.w);
}



int main(int argc, char **argv)
{


//inizialiazzazione nodo 
ros::init(argc, argv, "navgoal");
ros::NodeHandle n;


//sottoscrizione al topic "move_base_simple/goal" pubblicato da Rviz
//questo topic contiene le coordinate del punto che l'utente vuole far raggiungere al robot
ros::Subscriber sub_goal = n.subscribe("/move_base_simple/goal", 1000, goal_Callback);

//pubblicazione sul topic "waypoint_publisher" 
//matlab accede a questo topic e utilizza l'informazione del punto da raggiungere per il controllo
ros::Publisher pub = n.advertise< geometry_msgs::Point>("/waypoint_publisher", 1000);
  


   while (ros::ok())
   {
//creazione quaterione del waypoint      
tf::Quaternion ql(goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w);
tf::Matrix3x3 m(ql);
double roll, pitch, yaw; //estrazione angoli di roll, pitch e yaw dal quaternione
m.getRPY(roll, pitch, yaw);

//il topic "waypoint_publisher" contiene un messaggio di tipo "point" e contiene tre variabili
waypoint.x=goal.pose.position.x; //ascissa waypoint in mappa
waypoint.y=goal.pose.position.y; //ordinata waypoint in mappa
waypoint.z=yaw; //orientamento waypoint in mappa

pub.publish(waypoint); //pubblicazione sul topic "waypoint_publisher"
     
      ros::spinOnce();
      
      
      
   }

   return 0;
}
