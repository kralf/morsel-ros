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

#ifndef MORSEL_ROS_JOYSTICK_H
#define MORSEL_ROS_JOYSTICK_H

/** @file ros_joystick.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <sensor_msgs/Joy.h>

#include "node/ros_subscriber.h"

class ROSJoystick :
  public ROSSubscriber {
PUBLISHED:
  /** Constructors
    */
  ROSJoystick(std::string name, ROSNode& node, PyObject* receiver,
    std::string topic = "/joy", unsigned int queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSJoystick();
protected:
#ifndef CPPPARSER
  void callback(const sensor_msgs::Joy::ConstPtr& message);
#endif
};

#endif
