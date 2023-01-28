#include <ros/ros.h>
#include <ros/console.h>

#include <sstream>

#include <kbm_sim/kbm_sim.h>
#include <kbm_sim/Events.h>

#include <unistd.h>

class KBMSimNode
{
  public:
    KBMSimNode(){
      // Get handles
      ros::NodeHandle nhtopics("");
      ros::NodeHandle nhparams("~");

      // Get params
      nhparams.param<std::string>("topic", listener_topic, "/cmd");
      loginfo("--starting--");
      loginfo(listener_topic.c_str());

      // Setup subscriber
      sub = nhtopics.subscribe(listener_topic, 1, &KBMSimNode::callback, this);
    }

  private:
    int rate;
    std::string listener_topic;
    std::string node_name = ros::this_node::getName();
    Sim sims;
    ros::Subscriber sub;
    
    void callback(const kbm_sim::Events::ConstPtr& msg) {
      // extract kb+m 
      sims.move_pointer(msg->mouse_move_x, msg->mouse_move_y);
      sims.press_keys(msg->keys_down);
      sims.release_keys(msg->keys_up);
      sims.mouse_click(msg->mouse_click);
      sims.mouse_release(msg->mouse_release);

    }

    void loginfo(const char* msg){
      ROS_INFO("[%s] %s ", node_name.c_str(), msg);
    }
};

int main(int argc, char **argv){
  ros::init(argc, argv, "kbm_sim_node");
  KBMSimNode kbm_sim;
  ros::spin();
  return 0;
}