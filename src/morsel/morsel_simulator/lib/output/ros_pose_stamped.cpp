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

#include "ros_pose_stamped.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSPoseStamped::ROSPoseStamped(std::string name, ROSNode& node, std::string
    topic, unsigned int queueSize) :
  ROSPublisher(name, node,
    node.getHandle().advertise<geometry_msgs::PoseStamped>(topic, queueSize)),
  sequence(0) {
}

ROSPoseStamped::~ROSPoseStamped() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSPoseStamped::publish(double time, std::string frame, const LVecBase3f&
    position, const LQuaternionf& orientation) {
  geometry_msgs::PoseStamped message;

  message.header.seq = sequence;
  message.header.stamp = ros::Time(time);
  message.header.frame_id = frame;
  message.pose.position.x = position[0];
  message.pose.position.y = position[1];
  message.pose.position.z = position[2];
  message.pose.orientation.x = orientation[1];
  message.pose.orientation.y = orientation[2];
  message.pose.orientation.z = orientation[3];
  message.pose.orientation.w = orientation[0];

  ROSPublisher::publish(message);

  ++sequence;
}
