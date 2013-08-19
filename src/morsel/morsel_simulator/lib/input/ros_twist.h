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

#ifndef MORSEL_ROS_TWIST_H
#define MORSEL_ROS_TWIST_H

/** @file ros_twist.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <geometry_msgs/Twist.h>

#include "node/ros_subscriber.h"

class ROSTwist :
  public ROSSubscriber {
PUBLISHED:
  /** Constructors
    */
  ROSTwist(std::string name, ROSNode& node, PyObject* receiver, std::string
    topic = "/cmd_vel", unsigned int queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSTwist();
protected:
#ifndef CPPPARSER
  void callback(const geometry_msgs::Twist::ConstPtr& message);
#endif
};

#endif
