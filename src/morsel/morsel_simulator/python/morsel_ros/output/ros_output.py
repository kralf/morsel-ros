from morsel.nodes import Output

import re
import inspect

#-------------------------------------------------------------------------------

class ROSOutput(Output):
  def __init__(self, node, name = "ROSOutput", topic = None, queueSize = 1000,
      frame = None, **kargs):
    Output.__init__(self, name, **kargs)

    if topic[0] != "/":
      if self.parent:
        self.topic = "/"+re.sub("\s+", "_",
          re.sub("([a-z])([A-Z0-9])", "\\1_\\2",
          self.parent.getName())).lower()
      else:
        self.topic = ""
      self.topic += "/"+topic
    else:
      self.topic = topic

    if not frame and self.parent != render:
      frame = "/"+re.sub("\s+", "_",
        re.sub("([a-z])([A-Z0-9])", "\\1_\\2",
        self.parent.getName())).lower()

    self.node = node
    self.queueSize = queueSize
    self.publisher = None
    self.frame = frame

#-------------------------------------------------------------------------------

  def getModule(self):
    for frame in inspect.getouterframes(inspect.currentframe()):
      module = inspect.getmodule(frame[0])
      if module.__name__ != __name__:
        return module.__name__
      
    return __name__

  module = property(getModule)

#-------------------------------------------------------------------------------

  def getTopic(self):
    return self.topics[self.module]

  def setTopic(self, topic):
    if not hasattr(self, "topics"):
      self.topics = {}

    self.topics[self.module] = topic

  topic = property(getTopic, setTopic)

#-------------------------------------------------------------------------------

  def getNode(self):
    return self.nodes[self.topic]

  def setNode(self, node):
    if not hasattr(self, "nodes"):
      self.nodes = {}

    self.nodes[self.topic] = node

  node = property(getNode, setNode)

#-------------------------------------------------------------------------------

  def getQueueSize(self):
    return self.queueSizes[self.topic]

  def setQueueSize(self, queueSize):
    if not hasattr(self, "queueSizes"):
      self.queueSizes = {}

    self.queueSizes[self.topic] = queueSize
    
  queueSize = property(getQueueSize, setQueueSize)

#-------------------------------------------------------------------------------

  def getPublisher(self):
    return self.publishers[self.topic]

  def setPublisher(self, publisher):
    if not hasattr(self, "publishers"):
      self.publishers = {}
      
    self.publishers[self.topic] = publisher
    
  publisher = property(getPublisher, setPublisher)

#-------------------------------------------------------------------------------

  def getFrame(self):
    if self.parent.hasPythonTag("frame"):
      return self.parent.getPythonTag("frame")
    else:
      return "/world"

  def setFrame(self, frame):
    if frame == "/world":
      frame = None
    
    if self.parent.hasPythonTag("frame"):
      if not frame or self.parent.getPythonTag("frame") != frame:
        framework.error("Conflicting frame identifiers")
    elif frame:
      self.parent.setPythonTag("frame", frame)

  frame = property(getFrame, setFrame)

#-------------------------------------------------------------------------------

  def getFrameParent(self, node = None):
    if not node:
      node = self.parent

    while node and node.hasParent():
      if node.getParent().hasPythonTag("frame"):
        return node.getParent(), node.getParent().getPythonTag("frame")
      else:
        if node.getParent().hasParent():
          node = node.getParent()
        else:
          node = None

    return render, "/world"

  frameParent = property(getFrameParent)

#-------------------------------------------------------------------------------

  def getParentFrame(self, node = None):
    parentNode, parentFrame = self.getFrameParent(node)
    return parentFrame

  parentFrame = property(getParentFrame)

#-------------------------------------------------------------------------------

  def publish(self, *args):
    self.publishers[self.topic].publish(*args)
    