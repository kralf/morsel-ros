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
#include <tf/transform_broadcaster.h>

#include "ros_transform_broadcaster.h"

/******************************************************************************/
/* Constructors and Destructor                                                */
/******************************************************************************/

ROSTransformBroadcaster::ROSTransformBroadcaster(std::string name,
    ROSNode& node) :
  NodePath(name),
  node(node),
  broadcaster(new Broadcaster()) {
}

ROSTransformBroadcaster::ROSTransformBroadcaster(const
    ROSTransformBroadcaster& src) :
  NodePath(src),
  node(src.node),
  broadcaster(new Broadcaster(*src.broadcaster)) {
}

ROSTransformBroadcaster::~ROSTransformBroadcaster() {
  delete broadcaster;
}
