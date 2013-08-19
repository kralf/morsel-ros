from morsel_ros.output.ros_output import ROSOutput
from morsel_ros.rosc import ROSTransformStamped as CROSTransformStamped

#-------------------------------------------------------------------------------

class ROSTransformStamped(ROSOutput):
  def __init__(self, node, name = "ROSTransformStamped", topic = "transform",
      **kargs):
    ROSOutput.__init__(self, node, name = name, topic = topic, **kargs)

    self.publisher = CROSTransformStamped(name, self.node.node, self.topic,
      self.queueSize)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    parentNode, parentFrame = self.frameParent
    
    if self.frame != parentFrame:
      translation = self.getPos(parentNode)
      rotation = self.getQuat(parentNode)
      
      self.publish(time, parentFrame, self.frame, translation, rotation)
