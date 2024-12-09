# FIFO data structure where elements are inserted at rear and removed from front

class Queue:
  def __init__(self):
    self.queue = []
  def is_empty(self):
    return len(self.queue) == 0
  def enqueue(self, item):
    self.queue.append(item)
  def dequeue(self):
    if self.is_empty():
      raise IndexError("queue is empty")
    return self.queue.pop(0)
  def peek(self):
    if self.is_empty():
      raise IndexError("queue is empty")
    return self.queue[0]
