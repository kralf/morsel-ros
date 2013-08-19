from morsel_ros.output.ros_output import ROSOutput
from morsel_ros.rosc import ROSOdometry as CROSOdometry

#-------------------------------------------------------------------------------

class ROSOdometry(ROSOutput):
  def __init__(self, node, name = "ROSOdometry", topic = "odometry",
      actuator = None, platform = None, **kargs):
    if platform:
      actuator = platform.actuator;

    ROSOutput.__init__(self, node, name = name, topic = topic,
      parent = actuator, **kargs)

    self.actuator = actuator

    self.publisher = CROSOdometry(name, self.node.node, self.topic,
      self.queueSize)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    parentNode, parentFrame = self.frameParent

    if self.frame != parentFrame:
      translation = self.getPos(parentNode)
      rotation = self.getQuat(parentNode)
      translationalVelocity = parentNode.getRelativeVector(self.actuator,
        panda.Vec3(*self.actuator.translationalVelocity))
      rotationalVelocity = parentNode.getRelativeVector(self.actuator,
        panda.Vec3(self.actuator.rotationalVelocity[2],
        self.actuator.rotationalVelocity[1],
        self.actuator.rotationalVelocity[0]))

      self.publish(time, parentFrame, translation, rotation,
        translationalVelocity, panda.Vec3(rotationalVelocity[2],
        rotationalVelocity[1], rotationalVelocity[0]))
