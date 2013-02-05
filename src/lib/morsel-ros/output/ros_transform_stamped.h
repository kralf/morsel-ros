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

#ifndef ROS_TRANSFORM_STAMPED_H
#define ROS_TRANSFORM_STAMPED_H

/** @file ros_transform_stamped.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <geometry_msgs/TransformStamped.h>

#include "morsel-ros/node/ros_publisher.h"

class ROSTransformStamped :
  public ROSPublisher {
PUBLISHED:
  /** Constructors
    */
  ROSTransformStamped(std::string name, ROSNode& node, std::string
    topic = "/transform", unsigned int queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSTransformStamped();

  void publish(double time, std::string frame, std::string childFrame,
    const LVecBase3f& translation, const LQuaternionf& rotation);
protected:
  unsigned int sequence;
};

#endif
