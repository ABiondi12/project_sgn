//NODO CHE A PARTIRE DAL MESSAGGIO IN FORMATO "PoseWithCovarianceStamped" (FORNITO DAL TOPIC amcl_pose) PUBBLICA LA POSIZIONE DEL ROBOT IN FORMATO "Point"

#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/Point.h"
#include "tf/tfMessage.h"
#include "tf/transform_broadcaster.h"
#include "math.h"
#include "tf/transform_listener.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf/transform_datatypes.h>
#include <iostream>


geometry_msgs::PoseWithCovarianceStamped amcl; //variabile per la posizione fornita dal nodo amcl
geometry_msgs::Point robot_pose; //variabile tipo Point per la posizione del robot  

//callback per l'acquisizione della posizione del robot dal topic amcl_pose
void amcl_Callback(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
      amcl.pose.pose.position.x=(msg->pose.pose.position.x);
      amcl.pose.pose.position.y=(msg->pose.pose.position.y);
      amcl.pose.pose.orientation.x=(msg->pose.pose.orientation.x);
      amcl.pose.pose.orientation.y=(msg->pose.pose.orientation.y);
      amcl.pose.pose.orientation.z=(msg->pose.pose.orientation.z);
      amcl.pose.pose.orientation.w=(msg->pose.pose.orientation.w);
}



int main(int argc, char **argv)
{
//inizialiazzazione nodo 
ros::init(argc, argv, "amcl2robot_pose");
ros::NodeHandle n;

 //sottoscrizione al topic "amcl_pose" 
ros::Subscriber sub_goal = n.subscribe("/amcl_pose", 1000, amcl_Callback);

 //pubblicazione al topic "robot_pose" 
ros::Publisher pub = n.advertise< geometry_msgs::Point>("/robot_pose", 1000);
  
 //frequenza di pubblicazione del nodo
ros::Rate loop_rate(10);


   while (ros::ok())
   {     
 //trasformazione da quaternioni ad angoli RPY
double roll, pitch, yaw;
tf::Quaternion ql(amcl.pose.pose.orientation.x, amcl.pose.pose.orientation.y, amcl.pose.pose.orientation.z, amcl.pose.pose.orientation.w);
tf::Matrix3x3 m(ql);
m.getRPY(roll, pitch, yaw);

 //definizione posizione del robot
robot_pose.x=amcl.pose.pose.position.x;
robot_pose.y=amcl.pose.pose.position.y;
robot_pose.z=yaw;

pub.publish(robot_pose); //pubblicazione sul topic robot_pose
     
      ros::spinOnce();
      
      loop_rate.sleep();
      
   }

   return 0;
}
