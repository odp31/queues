// input-restricted queue is a queue with a limited capacity
// once queue is full, no more elements can be added until space becomes available through removal operations

class InputRestrictedQueue {
  constructor(capacity) {
    this.queue = [];
    this.capacity = capacity;
    this.size = 0;
  }

  isEmpty() {
    return this.size === 0;
  }
  isFull() {
    return this.size === this.capacity;
  }
  enqueue(element) {
    if(this.isFull()) {
      console.log("queue is full");
      return;
    }
    this.queue.push(element);
    this.size++;
  }

  dequeue() {
    if(this.isEmpty()) {
      console.log("queue is empty");
      return;
    }
    this.queue.shift();
    this.size--;
  }

  peek() {
    if(this.isEmpty()) {
      console.log("queue is empty");
      return;
    }
    return this.queue[0];
  }
}
