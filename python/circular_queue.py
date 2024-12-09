class CircularQueue:
  def __init__(self, size):
    self.size = size
    self.queue = [None] * size
    self.front = self.rear = -1

  def is_empty(self):
    return self.front == -1

  def is_full(self):
    return (self.rear + 1) % self.size == self.front

  def enqueue(self, item):
    if self.is_full():
      print("queue is full")
      return
    if self.is_empty():
      self.front = self.rear = 0
    else:
      self.rear = (self.rear + 1) % self.size
    self.queue[self.rear] = item

  def dequeue(self):
    if self.is_empty():
      print("queue is empty")
      return
    item = self.queue[self.front]
    if self.front == self.rear:
      self.front = self.rear = -1
    else:
      self.front = (self.front + 1) % self.size
    return item

  def print_queue(self):
    if self.is_empty():
      print("queue is empty")
      return
    print("queue: ")
    for i in range(self.front, self.rear + 1):
      print(self.queue[i % self.size], end="")
    print()

