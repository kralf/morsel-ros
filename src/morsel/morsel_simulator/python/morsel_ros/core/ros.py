from morsel_ros.config import Configuration

#-------------------------------------------------------------------------------

class ROS(object):
  def __init__(self):
    object.__init__(self)

    self.name = "morsel"
    self.log = ""
    self.masterUri = "http://localhost:11311/"
    self.namespace = ""
