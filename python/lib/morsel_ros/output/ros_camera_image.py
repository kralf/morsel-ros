from morsel_ros.output.ros_image import ROSImage

#-------------------------------------------------------------------------------

class ROSCameraImage(ROSImage):
  def __init__(self, node, name = "ROSCameraImage", topic = "image_color",
      sensor = None, orientation = [-90, -90, 0], **kargs):
    ROSImage.__init__(self, node, name = name, topic = topic,
      image = panda.PNMImage(), parent = sensor, orientation = orientation,
      **kargs)

    self.sensor = sensor

#-------------------------------------------------------------------------------

  def outputData(self, time):
    self.image = self.sensor.sensor.getImage()
    ROSImage.outputData(self, self.sensor.sensor.getTimestamp())
