from morsel_ros.output.ros_output import ROSOutput
from morsel_ros.rosc import ROSCameraInfo as CROSCameraInfo

#-------------------------------------------------------------------------------

class ROSCameraInfo(ROSOutput):
  def __init__(self, node, name = "ROSCameraInfo", topic = "camera_info",
      sensor = None, orientation = [-90, 0, -90], **kargs):
    ROSOutput.__init__(self, node, name = name, topic = topic, parent = sensor,
      orientation = orientation, **kargs)

    self.sensor = sensor

    self.publisher = CROSCameraInfo(name, self.node.node, self.topic,
      self.queueSize)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    if self.sensor:
      self.publish(time, self.frame, self.sensor.sensor.getCamera())
