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

#include "ros_twist.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSTwist::ROSTwist(std::string name, ROSNode& node, PyObject* receiver,
    std::string topic, unsigned int queueSize) :
  ROSSubscriber(name, node, node.getHandle().subscribe(topic, queueSize,
    &ROSTwist::callback, this), receiver) {
}

ROSTwist::~ROSTwist() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSTwist::callback(const geometry_msgs::Twist::ConstPtr& message) {
  received("(d[ddd][ddd])", ros::Time::now().toSec(), message->linear.x,
    message->linear.y, message->linear.z, message->angular.z*180.0/M_PI,
    message->angular.y*180.0/M_PI, message->angular.x*180.0/M_PI);
}
