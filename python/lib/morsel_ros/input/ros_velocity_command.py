from morsel.nodes import Input
from morsel_ros.rosc import ROSVelocityCommand as CROSVelocityCommand

#-------------------------------------------------------------------------------

class ROSVelocityCommand(Input):
  def __init__(self, node, name = "ROSVelocityCommand", topic = "/cmd_vel",
      queueSize = 1000, actuator = None, platform = None, **kargs):
    if platform:
      actuator = platform.actuator;
        
    Input.__init__(self, name, **kargs)

    self.node = node
    self.topic = topic
    self.queueSize = queueSize
    self.actuator = actuator

    self.subscriber = CROSVelocityCommand(name, self.node.node, self.actuator,
      self.topic, self.queueSize)
    self.subscriber.reparentTo(self)
