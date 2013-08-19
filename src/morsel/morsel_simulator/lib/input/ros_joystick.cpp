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

#include "ros_joystick.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSJoystick::ROSJoystick(std::string name, ROSNode& node, PyObject* receiver,
    std::string topic, unsigned int queueSize) :
  ROSSubscriber(name, node, node.getHandle().subscribe(topic, queueSize,
    &ROSJoystick::callback, this), receiver) {
}

ROSJoystick::~ROSJoystick() {
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSJoystick::callback(const sensor_msgs::Joy::ConstPtr& message) {
  PyObject* axes = PyList_New(message->axes.size());
  Py_XINCREF(axes);

  for (int i = 0; i < message->axes.size(); ++i)
    PyList_SetItem(axes, i, PyFloat_FromDouble(message->axes[i]));
  received("(dO)", message->header.stamp.toSec(), axes);

  Py_XDECREF(axes);
}
