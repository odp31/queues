# allows insertion only from one end(usually rear) and deletion from both ends 

class InputRestrictedQueue:
  def __init__(self, capacity):
    self.queue = [None] * capacity
    self.capacity = capacity
    self.front = self.rear = -1


  def is_empty(self):
    return self.front == -1

  def is_full(self):
    return (self.rear + 1) % self.capacity = self.front 

  def enqueue(self, item):
    if self.is_full():
      print("queue is full")
      return
    if self.is_empty():
      self.front = self.rear = 0
    else:
      self.rear = (self.rear + 1) % self.capacity
    self.queue[self.rear] = item

  def dequeue_front(self):
    if self.is_empty():
      print("queue is empty")
      return
    item = self.queue[self.front]
    if self.front == self.rear:
      self.front = self.rear = -1
    else:
      self.front = (self.front + 1) % self.capacity
    return item 

  def dequeue_rear(self):
    if self.is_empty():
      print("queue is empty")
      return
    item = self.queue[self.rear]
    if self.front == self.rear:
      self.front = self.rear = -1
    elif self.rear == 0:
      self.rear = self.capacity - 1
    else:
      self.rear -= 1
    return item 
