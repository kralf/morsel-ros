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

#ifndef ROS_PUBLISHER_H
#define ROS_PUBLISHER_H

/** @file ros_publisher.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <nodePath.h>

#include "morsel-ros/node/ros_node.h"

namespace ros {
  class Publisher;
};

class ROSPublisher :
  public NodePath {
PUBLISHED:
  /** Types and non-static subclasses
    */
  typedef ros::Publisher Publisher;

  /** Constructors
    */
  ROSPublisher(std::string name, ROSNode& node, const Publisher&
    publisher);
  ROSPublisher(const ROSPublisher& src);

  /** Destructor
    */
  virtual ~ROSPublisher();
protected:
  ROSNode node;
  Publisher* publisher;

#ifndef CPPPARSER
  template <typename M> void publish(const M& message);
#endif
};

#ifndef CPPPARSER
#include "morsel-ros/node/ros_publisher.tpp"
#endif

#endif
