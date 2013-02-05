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

#ifndef ROS_ODOMETRY_H
#define ROS_ODOMETRY_H

/** @file ros_odometry.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <nav_msgs/Odometry.h>

#include "morsel-ros/node/ros_publisher.h"

class ROSOdometry :
  public ROSPublisher {
PUBLISHED:
  /** Constructors
    */
  ROSOdometry(std::string name, ROSNode& node, std::string topic = "/odometry",
    unsigned int queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSOdometry();

  void publish(double time, std::string frame, const LVecBase3f& position,
    const LQuaternionf& orientation, const LVecBase3f& translationalVelocity,
    const LVecBase3f& rotationalVelocity);
protected:
  unsigned int sequence;
};

#endif
