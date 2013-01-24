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

#ifndef ROS_CAMERA_H
#define ROS_CAMERA_H

/** @file ros_camera.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <sensor_msgs/Image.h>

#include "morsel-ros/node/ros_publisher.h"

class ImageSensor;

class ROSCamera :
  public ROSPublisher {
PUBLISHED:
  /** Constructors
    */
  ROSCamera(std::string name, ROSNode& node, NodePath& sensor, std::string
    frame = "camera", std::string topic = "/image_color", unsigned int
    queueSize = 1000);

  /** Destructor
    */
  virtual ~ROSCamera();

  void publish(double time);
protected:
  ImageSensor& sensor;

  unsigned int sequence;
  std::string frame;
};

#endif
