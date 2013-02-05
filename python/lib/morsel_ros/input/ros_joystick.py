from morsel_ros.input.ros_input import ROSInput
from morsel_ros.rosc import ROSJoystick as CROSJoystick

#-------------------------------------------------------------------------------

class ROSJoystick(ROSInput):
  def __init__(self, node, name = "ROSJoystick", topic = "joy",
      queueSize = None, joystick = None, **kargs):
    ROSInput.__init__(self, node, name = name, topics = [topic],
      queueSizes = [queueSize], parent = joystick, **kargs)

    self.joystick = joystick

    self.subscriber = CROSJoystick(name, self.node.node, self, self.topic,
      self.queueSize)
    self.subscriber.reparentTo(self)

#-------------------------------------------------------------------------------

  def inputData(self, time, axes = []):
    for i in range(len(axes)):
      self.joystick.setAxis(i, axes[i])
