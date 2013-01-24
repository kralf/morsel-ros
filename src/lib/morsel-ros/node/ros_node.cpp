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

#include "ros_node.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSNode::ROSNode(std::string name, std::string masterUri, std::string
    nameSpace) :
  NodePath(name) {
  ros::VP_string remappings;

  remappings.push_back(std::make_pair("__master", masterUri));
  if (!nameSpace.empty())
    remappings.push_back(std::make_pair("__ns", nameSpace));
  ros::init(remappings, name);

  handle = new Handle();
}

ROSNode::ROSNode(const ROSNode& src) :
  NodePath(src),
  handle(new Handle(*src.handle)) {
}

ROSNode::~ROSNode() {
  delete handle;
}

/******************************************************************************/
/* Accessors                                                                  */
/******************************************************************************/

ROSNode::Handle& ROSNode::getHandle() {
  return *handle;
}

const ROSNode::Handle& ROSNode::getHandle() const {
  return *handle;
}

/******************************************************************************/
/* Methods                                                                    */
/******************************************************************************/

void ROSNode::receive(double time) {
  ros::spinOnce();
}
