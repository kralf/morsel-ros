from morsel_ros.output.ros_image import ROSImage

#-------------------------------------------------------------------------------

class ROSCapture(ROSImage):
  def __init__(self, node, name = "ROSCapture", topic = "image_color",
      **kargs):
    ROSImage.__init__(self, node, name = name, topic = topic,
      image = panda.PNMImage(), parent = framework.base.camera, **kargs)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    framework.window.getScreenshot(self.image)
    ROSImage.outputData(self, time)
