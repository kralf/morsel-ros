from morsel_ros.output.ros_output import ROSOutput
from morsel_ros.rosc import ROSTransformsStamped as CROSTransformsStamped

#-------------------------------------------------------------------------------

class ROSTransformsStamped(ROSOutput):
  def __init__(self, node, name = "ROSTransforms", **kargs):
    ROSOutput.__init__(self, node, name = name, topic = "/tf", **kargs)

    self.publisher = CROSTransformsStamped(name, self.node.node)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    transforms = {}
    
    for output in Iterator(self.parent, ROSOutput).generator:
      if output.frame != self.frame:
        parentNode, parentFrame = output.frameParent        
        translation = output.getPos(parentNode)
        rotation = output.getQuat(parentNode)
        
        transforms[output.frame] = (parentFrame, translation, rotation)

    if transforms:
      self.publish(time, transforms)
      