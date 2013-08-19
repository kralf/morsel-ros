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

#include <ros/ros.h>

#include <morsel/sensors/image_sensor.h>

#include "ros_camera_info.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSCameraInfo::ROSCameraInfo(std::string name, ROSNode& node, std::string
    topic, unsigned int queueSize) :
  ROSPublisher(name, node,
    node.getHandle().advertise<sensor_msgs::CameraInfo>(topic, queueSize)),
  sequence(0) {
}

ROSCameraInfo::~ROSCameraInfo() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSCameraInfo::publish(double time, std::string frame, const Camera&
    camera) {
  DisplayRegion* displayRegion = (DisplayRegion*)camera.get_display_region(0);
  Lens* lens = camera.get_lens();
  sensor_msgs::CameraInfo message;

  double fx = lens->get_focal_length()*displayRegion->get_pixel_width()/
    lens->get_film_size()[0];
  double fy = lens->get_focal_length()*displayRegion->get_pixel_height()/
    lens->get_film_size()[1];
  double cx = 0.5*displayRegion->get_pixel_width();
  double cy = 0.5*displayRegion->get_pixel_height();

  message.header.seq = sequence;
  message.header.stamp = ros::Time(time);
  message.header.frame_id = frame;
  message.height = displayRegion->get_pixel_height();
  message.width = displayRegion->get_pixel_width();
  message.K[0*3+0] = fx;
  message.K[1*3+1] = fy;
  message.K[0*3+2] = cx;
  message.K[1*3+2] = cy;
  message.K[2*3+2] = 1.0;
  for (int i = 0; i < 3; ++i)
    message.R[i*3+i] = 1.0;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      message.P[i*4+j] = message.K[i*3+j];

  ROSPublisher::publish(message);

  ++sequence;
}
