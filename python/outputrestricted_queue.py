class OutputRestrictedQueue:
  def __init__(self, capacity):
    self.queue = [None] * capacity
    self.capacity = capacity
    self.front = self.rear = -1

  def is_empty(self):
    return self.front == -1

  def is_full(self):
    return (self.rear + 1) % self.capacity == self.front

  def enqueue_front(self, item):
    if self.is_full():
      print("queue is full")
      return
    if self.is_empty():
      self.front == self.rear = 0
    elif self.front == 0:
      self.front = self.capacity - 1
    else:
      self.front -= 1
    self.queue[self.front] = item

  def enqueue_rear(self, item):
    if self.is_full():
      print("queue is full")
      return
    if self.is_empty():
      self.front = self.rear = 0
    else:
      self.rear = (self.rear + 1) % self.capacity
    self.queue[self.rear] = item


  def dequeue(self):
    if self.
    item = self.queue[self.front]
    if self.front == self.rear:
      self.front = self.rear = -1
    else:
      self.front = (self.front + 1) % self.capacity
    return item 
