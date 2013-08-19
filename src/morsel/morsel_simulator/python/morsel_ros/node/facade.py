from morsel_ros.node import *

#-------------------------------------------------------------------------------

def ROSNode(**kargs):
  return framework.createInstance("node", type = "ROSNode",
    world = framework.world, **kargs)
