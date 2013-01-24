from morsel.nodes import Output
from morsel_ros.rosc import ROSCamera as CROSCamera

#-------------------------------------------------------------------------------

class ROSCamera(Output):
  def __init__(self, node, name = "ROSCamera", topic = "/image_color",
      queueSize = 1000, frame = "camera", sensor = None, **kargs):
    Output.__init__(self, name, **kargs)

    self.node = node
    self.topic = topic
    self.queueSize = queueSize
    self.frame = frame
    self.sensor = sensor

    self.publisher = CROSCamera(name, self.node.node, self.sensor.sensor,
      self.frame, self.topic, self.queueSize)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    self.publisher.publish(time)
