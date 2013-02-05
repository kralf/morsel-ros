from morsel.nodes import Input

import re

#-------------------------------------------------------------------------------

class ROSInput(Input):
  def __init__(self, node, name = "ROSInput", topics = [], queueSizes = [],
      **kargs):
    Input.__init__(self, name, **kargs)

    self.node = node
    self.topics = [None]*len(topics)
    self.queueSizes = {}
    self.subscribers = {}
    
    for i in range(len(topics)):
      if topics[i][0] != "/":
        if self.parent:
          self.topics[i] = "/"+re.sub("\s+", "_",
            re.sub("([a-z])([A-Z0-9])", "\\1_\\2", self.parent.name)).lower()
        else:
          self.topics[i] = ""
        self.topics[i] += "/"+topics[i]
      else:
        self.topics[i] = topics[i]

      if i < len(queueSizes):
        if queueSizes[i]:
          self.queueSizes[self.topics[i]] = queueSizes[i]
        else:
          self.queueSizes[self.topics[i]] = 1000

      self.subscribers[self.topics[i]] = None

#-------------------------------------------------------------------------------

  def getTopic(self):
    return self.topics[0]

  topic = property(getTopic)

#-------------------------------------------------------------------------------

  def getQueueSize(self):
    return self.queueSizes[self.topic]

  queueSize = property(getQueueSize)

#-------------------------------------------------------------------------------

  def getSubscriber(self):
    return self.subscribers[self.topic]

  def setSubscriber(self, subscriber):
    self.subscribers[self.topic] = subscriber
    
  subscriber = property(getSubscriber, setSubscriber)
