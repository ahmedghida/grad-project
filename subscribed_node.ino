#include <ros.h>
#include <std_msgs/String.h>

// Set the baud rate for the serial communication
#define BAUD_RATE 57600

// Create a ROS node handle
ros::NodeHandle nh;

// Callback function to handle received messages
void messageCallback(const std_msgs::String& msg) {
  // Print the received message to the serial monitor
  Serial.println(msg.data);
}

// Create a subscriber object
ros::Subscriber<std_msgs::String> subscriber("topic_name", &messageCallback);

void setup() {
  // Initialize the serial communication
  Serial.begin(BAUD_RATE);
  
  // Initialize the ROS node
  nh.initNode();
  
  // Subscribe to the topic
  nh.subscribe(subscriber);
}

void loop() {
  // Handle any incoming ROS messages
  nh.spinOnce();
  
  // Add your other code logic here if needed
}
