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

#include "ros_transform_stamped.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSTransformStamped::ROSTransformStamped(std::string name, ROSNode& node,
    std::string topic, unsigned int queueSize) :
  ROSPublisher(name, node,
    node.getHandle().advertise<geometry_msgs::TransformStamped>(topic,
      queueSize)),
  sequence(0) {
}

ROSTransformStamped::~ROSTransformStamped() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSTransformStamped::publish(double time, std::string frame, std::string
    childFrame, const LVecBase3f& translation, const LQuaternionf& rotation) {
  geometry_msgs::TransformStamped message;

  message.header.seq = sequence;
  message.header.stamp = ros::Time(time);
  message.header.frame_id = frame;
  message.child_frame_id = childFrame;
  message.transform.translation.x = translation[0];
  message.transform.translation.y = translation[1];
  message.transform.translation.z = translation[2];
  message.transform.rotation.x = rotation[1];
  message.transform.rotation.y = rotation[2];
  message.transform.rotation.z = rotation[3];
  message.transform.rotation.w = rotation[0];

  ROSPublisher::publish(message);

  ++sequence;
}
