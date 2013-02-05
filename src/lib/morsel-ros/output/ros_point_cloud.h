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

#ifndef ROS_POINT_CLOUD_H
#define ROS_POINT_CLOUD_H

/** @file ros_point_cloud.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <sensor_msgs/PointCloud2.h>

#include "morsel-ros/node/ros_publisher.h"

class RangeSensor;

class ROSPointCloud :
  public ROSPublisher {
PUBLISHED:
  /** Constructors
    */
  ROSPointCloud(std::string name, ROSNode& node, std::string
    topic = "/point_cloud", unsigned int queueSize = 1000,
    bool publishColors = false, bool publishLabels = false, bool
    publishInvalids = false);

  /** Destructor
    */
  virtual ~ROSPointCloud();

  void publish(double time, std::string frame, NodePath& sensor);
protected:
  unsigned int sequence;

  bool publishColors;
  bool publishLabels;
  bool publishInvalids;
};

#endif
