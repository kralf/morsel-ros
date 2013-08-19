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

#include <morsel/sensors/range_sensor.h>

#include "ros_point_cloud.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSPointCloud::ROSPointCloud(std::string name, ROSNode& node, std::string
    topic, unsigned int queueSize, bool publishColors, bool publishLabels,
    bool publishInvalids) :
  ROSPublisher(name, node,
    node.getHandle().advertise<sensor_msgs::PointCloud2>(topic, queueSize)),
  sequence(0),
  publishColors(publishColors),
  publishLabels(publishLabels),
  publishInvalids(publishInvalids) {
}

ROSPointCloud::~ROSPointCloud() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSPointCloud::publish(double time, std::string frame, NodePath&
    sensorNode) {
  RangeSensor& sensor = static_cast<RangeSensor&>(sensorNode);
  sensor_msgs::PointCloud2 message;
  sensor_msgs::PointField x, y, z;
  unsigned int pointStep = 0, width = 0;

  x.name = "x";
  x.offset = pointStep;
  x.datatype = sensor_msgs::PointField::FLOAT32;
  x.count = 1;
  message.fields.push_back(x);
  pointStep += 4;

  y.name = "y";
  y.offset = pointStep;
  y.datatype = sensor_msgs::PointField::FLOAT32;
  y.count = 1;
  message.fields.push_back(y);
  pointStep += 4;

  z.name = "z";
  z.offset = pointStep;
  z.datatype = sensor_msgs::PointField::FLOAT32;
  z.count = 1;
  message.fields.push_back(z);
  pointStep += 4;

  if (publishColors) {
    sensor_msgs::PointField color;
    color.name = "rgb";
    color.offset = pointStep;
    color.datatype = sensor_msgs::PointField::UINT32;
    color.count = 1;
    message.fields.push_back(color);
    pointStep += 4;
  }

  if (publishLabels) {
    sensor_msgs::PointField label;
    label.name = "label";
    label.offset = pointStep;
    label.datatype = sensor_msgs::PointField::UINT32;
    label.count = 1;
    message.fields.push_back(label);
    pointStep += 4;
  }

  if (publishInvalids) {
    sensor_msgs::PointField valid;
    valid.name = "valid";
    valid.offset = pointStep;
    valid.datatype = sensor_msgs::PointField::UINT8;
    valid.count = 1;
    message.fields.push_back(valid);
    pointStep += 1;

    width = sensor.getNumRays();
  }
  else {
    for (int i = 0; i < sensor.getNumRays(); ++i)
      if (sensor.getRay(i).valid)
        ++width;
  }

  message.data.resize(width*pointStep);
  int j = 0;
  for (int i = 0; i < sensor.getNumRays(); ++i) {
    RangeSensor::Ray ray = sensor.getRay(i);
    unsigned int pointOffset = 0;

    if (publishInvalids || ray.valid) {
      float* data = (float*)&message.data[j*pointStep];
      data[0] = ray.point[0];
      data[1] = ray.point[1];
      data[2] = ray.point[2];
      pointOffset += 12;

      if (publishColors) {
        uint* data = (uint*)&message.data[j*pointStep+pointOffset];
        data[0] = (uchar)round(ray.color[3]*255.0) << 24 |
          (uchar)round(ray.color[0]*255.0) << 16 |
          (uchar)round(ray.color[1]*255.0) << 8 |
          (uchar)round(ray.color[2]*255.0);
        pointOffset += 4;
      }

      if (publishLabels) {
        uint* data = (uint*)&message.data[j*pointStep+pointOffset];
        data[0] = ray.label;
        pointOffset += 4;
      }

      if (publishInvalids) {
        message.data[j*pointStep+pointOffset] = ray.valid;
        pointOffset += 1;
      }

      ++j;
    }
  }

  message.header.seq = sequence;
  message.header.stamp = ros::Time(sensor.getTimestamp());
  message.header.frame_id = frame;
  message.height = 1;
  message.width = width;
  message.is_bigendian = true;
  message.point_step = pointStep;
  message.row_step = message.point_step*message.width;
  message.is_dense = true;

  ROSPublisher::publish(message);

  ++sequence;
}
