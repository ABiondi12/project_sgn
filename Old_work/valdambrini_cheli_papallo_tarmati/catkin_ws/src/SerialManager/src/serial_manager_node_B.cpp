#include "serial_manager.h"
 

int main(int argc, char **argv)
{

  ros::init(argc, argv, "Serial_Manager");
  ros::NodeHandle n;
  

//ros::Subscriber forward_mean0 = n.subscribe<geometry_msgs::Point>("/tag0_mean", 1, &Mean_forward);
//ros::Subscriber backward_mean1 = n.subscribe<geometry_msgs::Point>("/tag1_mean", 1, &Mean_back);
ros::Subscriber robot_pose = n.subscribe<geometry_msgs::Point>("/robot_pose", 1, &robot_pose_cb);

ros::Subscriber forward_pose_topic = n.subscribe<geometry_msgs::Point>("/tag_pose0", 1, &Pose_cb_forward);
ros::Subscriber backward_pose_topic = n.subscribe<geometry_msgs::Point>("/tag_pose1", 1, &Pose_cb_back);
ros::Subscriber waypoint = n.subscribe<geometry_msgs::Point>("/waypoint_publisher", 1, &waypoint_cb);
ros::Subscriber start_and_stop=n.subscribe<std_msgs::Float64>("/start_and_stop", 1, &start_and_stop_cb);
//ros::Subscriber manual_auto=n.subscribe<std_msgs::Float64>("/manual_or_automatic", 1, manual_or_automatic_cb); //aggiunta riga per impostare controllo manuale o automatico
ros::Publisher heading_angle= n.advertise<geometry_msgs::Point>("/orientation",100); 
  
  n.param<std::string>("/SerialManager/dev", seriale_dev, "/dev/ttyS0");
  n.param<bool>("/SerialManager/stream_pose", stream_pose, true);
  n.param<int>("/SerialManager/pose_el_time", pose_el_time, 500);

  seriale_dev= "/dev/ttyS0";
  int result = serial_init(&serial, seriale_dev.c_str());
   way_x=0;
   way_y=0;
   way_z=0;
   pos_x_f=0;
   pos_y_f=0;
   pos_z_f=0;   
   pos_x_b=0;
   pos_y_b=0;
   pos_z_b=0;
   startstop=0;
   //controllo_manuale_automatico=0;//aggiunte da B  
  // tag_mean0_x=0;
  // tag_mean0_y=0;
  // tag_mean0_z=0;
  // tag_mean1_x=0;
  // tag_mean1_y=0;
  // tag_mean1_z=0; 
   robot_pose_x=0;
   robot_pose_y=0;
   robot_pose_z=0;
   
   
  gettimeofday(&stream_pose_time, NULL);
  ros::Rate loop_rate(100);
  if (result == 1)
  {
      while(ros::ok())
      {
      stream_pose=true;
      new_packet_pose=true;

      
        if(stream_pose && new_packet_pose)
        {

          read_from_serial(&serial);
          h_angle.z=orient_;
          heading_angle.publish(h_angle);

          //cout<<"elapsed time:"<<elapsed_time_pose<<endl;
          //devo inviare la posizione letta
          coda_send_seriale.push(HEADER_A);
          coda_send_seriale.push(HEADER_B);
          coda_send_seriale.push(PAYLOAD_POSE);
          encode_payload(pos_x_f);
          encode_payload(pos_y_f);
          encode_payload(pos_z_f);
          encode_payload(pos_x_b);
          encode_payload(pos_y_b);
          encode_payload(pos_z_b);
          encode_payload(way_x);
          encode_payload(way_y);
          encode_payload(way_z );
          encode_payload(startstop);         
          //encode_payload(tag_mean0_x);
          //encode_payload(tag_mean0_y);
          //encode_payload(tag_mean0_z);
          //encode_payload(tag_mean1_x);
          //encode_payload(tag_mean1_y);
          //encode_payload(tag_mean1_z);
          encode_payload(robot_pose_x);
          encode_payload(robot_pose_y);
          encode_payload(robot_pose_z);
          
          //encode_payload(controllo_manuale_automatico); //aggiunte da B per controllo manuale o automatico. 1->controllo automatico 2->controllo manuale
         

          new_packet_pose = 0;

        write_to_serial(&serial);
        }
        ros::spinOnce();
        loop_rate.sleep();
      }
  }
  return 0;
}
