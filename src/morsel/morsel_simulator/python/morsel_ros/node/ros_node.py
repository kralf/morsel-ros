from morsel.nodes import Node
from morsel_ros.rosc import ROSNode as CROSNode

#-------------------------------------------------------------------------------

class ROSNode(Node):
  def __init__(self, name = None, log = None, masterUri = None,
      namespace = None, frequency = 10.0, **kargs):
    if not name:
      name = ros.name
    if not masterUri:
      masterUri = ros.masterUri
    if not log:
      log = ros.log
    if not namespace:
      namespace = ros.namespace
      
    Node.__init__(self, name, masterUri, **kargs)
    
    self.masterUri = masterUri
    self.log = log
    self.namespace = namespace;
    self.frequency = frequency;

    self.node = CROSNode(name, self.masterUri, self.log, self.namespace)
    self.node.reparentTo(self)

    framework.scheduler.addTask(name+"Receive", self.receive,
      1.0/self.frequency)

#-------------------------------------------------------------------------------

  def receive(self, time):
    self.node.receive(time)
    return True
