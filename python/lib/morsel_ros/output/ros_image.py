from morsel_ros.output.ros_output import ROSOutput
from morsel_ros.rosc import ROSImage as CROSImage

#-------------------------------------------------------------------------------

class ROSImage(ROSOutput):
  def __init__(self, node, name = "ROSImage", topic = "image_color",
      image = None, **kargs):
    ROSOutput.__init__(self, node, name = name, topic = topic, **kargs)

    self.image = image

    self.publisher = CROSImage(name, self.node.node, self.topic,
      self.queueSize)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    if self.image:
      self.publish(time, self.frame, self.image)
