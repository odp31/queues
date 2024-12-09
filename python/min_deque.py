# python implementation using double ended queue from collections module and a min heap 

from collections import deque
import heapq

class MinDeque:
  def __init__(self):
    self.deque = deque()
    self.min_heap = []

  def push_front(self, val):
    self.deque.appendleft(val)
    heapq.heappush(self.min_heap, val)

  def push_back(self, val):
    self.deque.append(val)
    heapq.heappush(self.min_heap, val)

  def pop_front(self):
    if not self.deque:
      raise IndexError("deque is empty")
    val = self.deque.popleft()
    self.min_heap.remove(val)
    heapq.heapify(self.min_heap)
    return val 

  def pop_back(self):
    if not self.deque:
      raise IndexError("deque is empty")
    val = self.deque.pop()
    self.min_heap.remove(val)
    heapq.heapify(self.min_heap)
    return val 

  def get_min(self):
    if not self.min_heap:
      raise IndexError("deque is empty")
    return self.min_heap[0]
