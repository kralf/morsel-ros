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

#ifndef ROS_SUBSCRIBER_H
#define ROS_SUBSCRIBER_H

/** @file ros_subscriber.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <nodePath.h>

#include "morsel-ros/node/ros_node.h"

namespace ros {
  class Subscriber;
};

class ROSSubscriber :
  public NodePath {
PUBLISHED:
  /** Types and non-static subclasses
    */
  typedef ros::Subscriber Subscriber;

  /** Constructors
    */
  ROSSubscriber(std::string name, ROSNode& node, const Subscriber&
    subscriber, PyObject* receiver);
  ROSSubscriber(const ROSSubscriber& src);

  /** Destructor
    */
  virtual ~ROSSubscriber();
protected:
  ROSNode node;
  Subscriber* subscriber;

  PyObject* receiver;

  void received(const char* format, ...);
  void received(PyObject* arguments);
};

#endif
