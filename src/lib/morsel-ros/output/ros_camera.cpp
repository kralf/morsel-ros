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
#include <sensor_msgs/image_encodings.h>

#include <morsel/sensors/image_sensor.h>

#include "ros_camera.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSCamera::ROSCamera(std::string name, ROSNode& node, NodePath& sensor,
    std::string frame, std::string topic, unsigned int queueSize) :
  ROSPublisher(name, node,
    node.getHandle().advertise<sensor_msgs::Image>(topic, queueSize)),
  sensor(static_cast<ImageSensor&>(sensor)),
  sequence(0),
  frame(frame) {
}

ROSCamera::~ROSCamera() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSCamera::publish(double time) {
  sensor_msgs::Image message;
  const PNMImage& image = sensor.getImage();

  message.header.seq = sequence;
  message.header.stamp = ros::Time(time);
  message.header.frame_id = frame;

  message.height = image.get_read_y_size();
  message.width = image.get_read_x_size();
  message.encoding = sensor_msgs::image_encodings::RGB8;
  message.is_bigendian = false;
  message.step = message.width*3;

  message.data.resize(message.height*message.step);
  for (int i = 0; i < message.width; ++i)
      for (int j = 0; j < message.height; ++j) {
    message.data[j*message.step+3*i] = image.get_red_val(i, j);
    message.data[j*message.step+3*i+1] = image.get_green_val(i, j);
    message.data[j*message.step+3*i+2] = image.get_blue_val(i, j);
  }

  publisher->publish(message);
  ++sequence;
}
