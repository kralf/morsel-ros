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

#include <cstdarg>

#include <ros/ros.h>

#include "ros_subscriber.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSSubscriber::ROSSubscriber(std::string name, ROSNode& node, const
    Subscriber& subscriber, PyObject* receiver) :
  NodePath(name),
  node(node),
  subscriber(new Subscriber(subscriber)),
  receiver(receiver) {
  Py_XINCREF(this->receiver);
}

ROSSubscriber::ROSSubscriber(const ROSSubscriber& src) :
  NodePath(src),
  node(src.node),
  subscriber(new Subscriber(*src.subscriber)),
  receiver(src.receiver) {
  Py_XINCREF(receiver);
}

ROSSubscriber::~ROSSubscriber() {
  Py_DECREF(receiver);
  delete subscriber;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSSubscriber::received(const char* format, ...) {
  va_list args;
  va_start(args, format);

  received(Py_VaBuildValue(format, args));

  va_end(args);
}

void ROSSubscriber::received(PyObject* arguments) {
  Py_XINCREF(arguments);

  PyObject* method = PyObject_GetAttrString(receiver, "inputData");
  Py_XINCREF(method);

  PyObject_CallObject(method, arguments);

  Py_XDECREF(method);
  Py_XDECREF(arguments);
}
