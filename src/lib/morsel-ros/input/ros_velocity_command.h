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

#ifndef ROS_VELOCITY_COMMAND_H
#define ROS_VELOCITY_COMMAND_H

/** @file ros_velocity_command.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <geometry_msgs/Twist.h>

#include "morsel-ros/node/ros_subscriber.h"

class ROSVelocityCommand :
  public ROSSubscriber {
PUBLISHED:
  /** Constructors
    */
  ROSVelocityCommand(std::string name, ROSNode& node, PyObject* actuator,
    std::string topic = "/cmd_vel", unsigned int queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSVelocityCommand();
protected:
  PyObject* actuator;

#ifndef CPPPARSER
  void callback(const geometry_msgs::Twist::ConstPtr& message);
#endif
};

#endif
