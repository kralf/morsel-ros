from morsel.nodes import Node
from morsel_ros.rosc import ROSNode as CROSNode

#-------------------------------------------------------------------------------

class ROSNode(Node):
  def __init__(self, name = "MorselROS", masterUri = "http://localhost:11311/",
      namespace = "", frequency = 10.0, **kargs):
    Node.__init__(self, name, masterUri, **kargs)

    self.masterUri = masterUri
    self.namespace = namespace;
    self.frequency = frequency;

    self.node = CROSNode(name, self.masterUri, self.namespace)
    self.node.reparentTo(self)

    framework.scheduler.addTask(name+"Receive", self.receive,
      1.0/self.frequency)

#-------------------------------------------------------------------------------

  def receive(self, time):
    self.node.receive(time)
    return True
