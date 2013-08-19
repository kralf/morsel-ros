from morsel_ros.output.ros_camera_info import ROSCameraInfo
from morsel_ros.output.ros_camera_image import ROSCameraImage

#-------------------------------------------------------------------------------

class ROSCamera(ROSCameraInfo, ROSCameraImage):
  def __init__(self, node, name = "ROSCamera", infoTopic = "camera_info",
      imageTopic = "image_color", sensor = None, orientation = [-90, 0, -90],
      **kargs):
    ROSCameraInfo.__init__(self, node, name = name, topic = infoTopic,
      sensor = sensor, orientation = orientation, **kargs)
    ROSCameraImage.__init__(self, node, name = name, topic = imageTopic,
      sensor = sensor, orientation = orientation, **kargs)

#-------------------------------------------------------------------------------

  def outputData(self, time):
    ROSCameraInfo.outputData(self, time)
    ROSCameraImage.outputData(self, time)
    