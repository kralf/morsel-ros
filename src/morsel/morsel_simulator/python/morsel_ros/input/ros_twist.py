from morsel_ros.input.ros_input import ROSInput
from morsel_ros.rosc import ROSTwist as CROSTwist

#-------------------------------------------------------------------------------

class ROSTwist(ROSInput):
  def __init__(self, node, name = "ROSTwist", topic = "cmd_vel",
      queueSize = None, actuator = None, platform = None, **kargs):
    if platform:
      actuator = platform.actuator;
      
    ROSInput.__init__(self, node, name = name, topics = [topic],
      queueSizes = [queueSize], parent = actuator, **kargs)

    self.actuator = actuator

    self.subscriber = CROSTwist(name, self.node.node, self, self.topic,
      self.queueSize)
    self.subscriber.reparentTo(self)

#-------------------------------------------------------------------------------

  def inputData(self, time, translationalVelocity = None,
      rotationalVelocity = None):
    if translationalVelocity:
      self.actuator.translationalVelocity = translationalVelocity
    if rotationalVelocity:
      self.actuator.rotationalVelocity = rotationalVelocity
