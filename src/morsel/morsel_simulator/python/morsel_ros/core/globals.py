from morsel_ros.config import *

import __builtin__

#-------------------------------------------------------------------------------

if not __builtin__.__dict__.has_key("ros"):
  from ros import ROS
  __builtin__.__dict__["ros"] = ROS()
