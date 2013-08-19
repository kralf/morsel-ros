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

#ifndef MORSEL_ROS_POSE_STAMPED_H
#define MORSEL_ROS_POSE_STAMPED_H

/** @file ros_pose_stamped.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <geometry_msgs/PoseStamped.h>

#include "node/ros_publisher.h"

class ROSPoseStamped :
  public ROSPublisher {
PUBLISHED:
  /** Constructors
    */
  ROSPoseStamped(std::string name, ROSNode& node, std::string topic = "/pose",
    unsigned int queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSPoseStamped();

  void publish(double time, std::string frame, const LVecBase3f& position,
    const LQuaternionf& orientation);
protected:
  unsigned int sequence;
};

#endif
