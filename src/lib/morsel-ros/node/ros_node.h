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

#ifndef ROS_NODE_H
#define ROS_NODE_H

/** @file ros_node.h
    @author Ralf Kaestner ETHZ Autonomous Systems Lab
  */

#include <nodePath.h>

namespace ros {
  class NodeHandle;
  class Publisher;
  class Subscriber;
};

class ROSNode :
  public NodePath {
PUBLISHED:
  /** Types and non-static subclasses
    */
  typedef ros::NodeHandle Handle;

  /** Constructors
    */
  ROSNode(std::string name, std::string masterUri = "http://localhost:11311/",
    std::string nameSpace = "");
  ROSNode(const ROSNode& src);

  /** Destructor
    */
  virtual ~ROSNode();

  void receive(double time);
public:
  Handle& getHandle();
  const Handle& getHandle() const;
protected:
  Handle* handle;
};

#endif
