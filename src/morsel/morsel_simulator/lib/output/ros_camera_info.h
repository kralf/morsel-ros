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

#ifndef MORSEL_ROS_CAMERA_INFO_H
#define MORSEL_ROS_CAMERA_INFO_H

/** @file ros_camera_info.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <sensor_msgs/CameraInfo.h>

#include <camera.h>

#include "node/ros_publisher.h"

class ImageSensor;

class ROSCameraInfo :
  public ROSPublisher {
PUBLISHED:
  /** Constructors
    */
  ROSCameraInfo(std::string name, ROSNode& node, std::string
    topic = "/camera_info", unsigned int queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSCameraInfo();

  void publish(double time, std::string frame, const Camera& camera);
protected:
  unsigned int sequence;
};

#endif
