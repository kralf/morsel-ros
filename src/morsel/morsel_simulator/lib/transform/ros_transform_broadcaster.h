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

#ifndef MORSEL_ROS_TRANSFORM_BROADCASTER_H
#define MORSEL_ROS_TRANSFORM_BROADCASTER_H

/** @file ros_transform_broadcaster.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <nodePath.h>

#include "node/ros_node.h"

namespace tf {
  class TransformBroadcaster;
};

class ROSTransformBroadcaster :
  public NodePath {
PUBLISHED:
  /** Types and non-static subclasses
    */
  typedef tf::TransformBroadcaster Broadcaster;

  /** Constructors
    */
  ROSTransformBroadcaster(std::string name, ROSNode& node);
  ROSTransformBroadcaster(const ROSTransformBroadcaster& src);

  /** Destructor
    */
  virtual ~ROSTransformBroadcaster();
protected:
  ROSNode node;
  Broadcaster* broadcaster;

#ifndef CPPPARSER
  template <typename T> void publish(const T& transform);
#endif
};

#ifndef CPPPARSER
#include "transform/ros_transform_broadcaster.tpp"
#endif

#endif
