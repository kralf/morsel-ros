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

#include <py_panda.h>

#include "ros_transforms_stamped.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSTransformsStamped::ROSTransformsStamped(std::string name, ROSNode& node) :
  ROSTransformBroadcaster(name, node),
  sequence(0) {
}

ROSTransformsStamped::~ROSTransformsStamped() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSTransformsStamped::publish(double time, PyObject* transforms) {
  Py_INCREF(transforms);
  std::vector<geometry_msgs::TransformStamped> messages;
  geometry_msgs::TransformStamped message;

  PyObject* key;
  PyObject* value;
  Py_ssize_t i = 0;

  while (PyDict_Next(transforms, &i, &key, &value)) {
    std::string childFrame = PyString_AsString(key);
    std::string frame = PyString_AsString(PyTuple_GetItem(value, 0));
    const LVecBase3f& translation = *(LVecBase3f*)((Dtool_PyInstDef*)
      PyTuple_GetItem(value, 1))->_ptr_to_object;
    const LQuaternionf& rotation = *(LQuaternionf*)((Dtool_PyInstDef*)
      PyTuple_GetItem(value, 2))->_ptr_to_object;

    message.header.seq = sequence;
    message.header.stamp = ros::Time(time);
    message.header.frame_id = PyString_AsString(PyTuple_GetItem(value, 0));
    message.child_frame_id = PyString_AsString(key);
    message.transform.translation.x = translation[0];
    message.transform.translation.y = translation[1];
    message.transform.translation.z = translation[2];
    message.transform.rotation.x = rotation[1];
    message.transform.rotation.y = rotation[2];
    message.transform.rotation.z = rotation[3];
    message.transform.rotation.w = rotation[0];

    messages.push_back(message);
  }

  ROSTransformBroadcaster::publish(messages);

  Py_DECREF(transforms);
  ++sequence;
}
