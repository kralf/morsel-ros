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

#include "ros_publisher.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSPublisher::ROSPublisher(std::string name, ROSNode& node, const Publisher&
    publisher) :
  NodePath(name),
  node(node),
  publisher(new Publisher(publisher)) {
}

ROSPublisher::ROSPublisher(const ROSPublisher& src) :
  NodePath(src),
  node(src.node),
  publisher(new Publisher(*src.publisher)) {
}

ROSPublisher::~ROSPublisher() {
  delete publisher;
}
