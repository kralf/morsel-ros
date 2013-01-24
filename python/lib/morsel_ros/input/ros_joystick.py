from morsel.nodes import Input
from morsel_ros.rosc import ROSJoystick as CROSJoystick

#-------------------------------------------------------------------------------

class ROSJoystick(Input):
  def __init__(self, node, name = "ROSJoystick", topic = "/joy",
      queueSize = 1000, joystick = None, **kargs):
    Input.__init__(self, name, **kargs)

    self.node = node
    self.topic = topic
    self.queueSize = queueSize
    self.joystick = joystick

    self.subscriber = CROSJoystick(name, self.node.node, self.joystick,
      self.topic, self.queueSize)
    self.subscriber.reparentTo(self)
