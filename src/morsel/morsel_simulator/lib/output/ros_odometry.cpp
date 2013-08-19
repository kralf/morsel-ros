/******************************************************************************
 * Copyright (C) 2013 by Ralf Kaestner                                        *
 * ralf.kaestner@gmail.com                                                    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include <ros/ros.h>

#include "ros_odometry.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSOdometry::ROSOdometry(std::string name, ROSNode& node, std::string topic,
    unsigned int queueSize) :
  ROSPublisher(name, node,
    node.getHandle().advertise<nav_msgs::Odometry>(topic, queueSize)),
  sequence(0) {
}

ROSOdometry::~ROSOdometry() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSOdometry::publish(double time, std::string frame, const LVecBase3f&
    position, const LQuaternionf& orientation, const LVecBase3f&
    translationalVelocity, const LVecBase3f& rotationalVelocity) {
  nav_msgs::Odometry message;

  message.header.seq = sequence;
  message.header.stamp = ros::Time(time);
  message.header.frame_id = frame;
  message.pose.pose.position.x = position[0];
  message.pose.pose.position.y = position[1];
  message.pose.pose.position.z = position[2];
  message.pose.pose.orientation.x = orientation[1];
  message.pose.pose.orientation.y = orientation[2];
  message.pose.pose.orientation.z = orientation[3];
  message.pose.pose.orientation.w = orientation[0];
  message.twist.twist.linear.x = translationalVelocity[0];
  message.twist.twist.linear.y = translationalVelocity[1];
  message.twist.twist.linear.z = translationalVelocity[2];
  message.twist.twist.angular.x = rotationalVelocity[2]*M_PI/180.0;
  message.twist.twist.angular.y = rotationalVelocity[1]*M_PI/180.0;
  message.twist.twist.angular.z = rotationalVelocity[0]*M_PI/180.0;

  ROSPublisher::publish(message);

  ++sequence;
}
