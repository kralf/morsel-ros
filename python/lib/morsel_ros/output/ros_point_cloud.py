from morsel_ros.output.ros_output import ROSOutput
from morsel_ros.rosc import ROSPointCloud as CROSPointCloud

#-------------------------------------------------------------------------------

class ROSPointCloud(ROSOutput):
  def __init__(self, node, name = "ROSPointCloud", topic = "point_cloud",
      sensor = None, publishColors = False, publishLabels = False,
      publishInvalids = False, **kargs):
    ROSOutput.__init__(self, node, name = name, topic = topic,
      parent = sensor, **kargs)

    self.sensor = sensor
    self.publishColors = publishColors
    self.publishLabels = publishLabels
    self.publishInvalids = publishInvalids

    self.publisher = CROSPointCloud(name, self.node.node, self.topic,
      self.queueSize, self.publishColors, self.publishLabels,    
      self.publishInvalids)
    self.publisher.reparentTo(self)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    if self.sensor:
      self.publish(time, self.frame, self.sensor.sensor)
