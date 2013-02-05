from morsel_ros.config import Configuration

import os
from os import *
import ctypes
from ctypes import *

#-------------------------------------------------------------------------------

class ROS(object):
  def __init__(self, *argv):
    object.__init__(self)

    self.configuration = Configuration()

    self.prelinkLibraries()

#-------------------------------------------------------------------------------

  def prelinkLibraries(self):
    for library in self.configuration.libraries:
      libraryInstance = None
      
      for libraryDir in self.configuration.libraryDirs:
        libraryFile = "lib"+library+".so"
        libraryPath = os.path.join(libraryDir, libraryFile)
        
        if os.path.isfile(libraryPath):
          libraryInstance = ctypes.cdll.LoadLibrary(libraryPath)

      if not libraryInstance:
        libraryInstance = ctypes.cdll.LoadLibrary(libraryFile)
