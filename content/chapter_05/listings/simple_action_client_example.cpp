#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <flypulator_vs_msgs/AprilTagIBVSAction.h>

int main (int argc, char **argv)
{
    ros::init(argc, argv, "vs_action_client");
    
    // Create the action client
    // "vs_action": name of the action, do not change
    actionlib::SimpleActionClient<flypulator_vs_msgs::AprilTagIBVSAction> ac("vs_action", true);
    
    ac.waitForServer(); // Wait for the action server an infinite time
    
    flypulator_vs_msgs::AprilTagIBVSGoal goal; // Create goal
    
    // Marker ID
    goal.tag_id = "36h11 id: 18";
    
    // Pose - Position
    goal.pose.position.x = 0.0;
    goal.pose.position.y = 0.0;
    goal.pose.position.z = 1.0;
    
    // Pose - Orinetation (quaternion)
    goal.pose.orinetaion.x = 0.0;
    goal.pose.orinetaion.y = 0.0;
    goal.pose.orinetaion.z = 0.0;
    goal.pose.orinetaion.w = 0.0;
    
    ac.sendGoal(goal); // Send goal to the server
    
    // Waits for the result and shutsdown

    return 0; // Exit
}