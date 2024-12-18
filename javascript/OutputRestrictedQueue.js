class OutputRestrictedQueue {
  constructor(limit) {
    this.queue = [];
    this.limit = limit;
  }

  isEmpty() {
    return this.queue.length === 0;
  }

  isFull() {
    return this.queue.length === this.limit;
  }

  enqueue(element) {
    this.queue.push(element);
  }

  dequeue() {
    if(this.isEmpty()) {
      console.log("queue is empty");
      return;
    }
    if(this.queue.length > this.limit) {
      this.queue.shift();
    }
    return this.queue.shift();
  }

  peek() {
    if(this.isEmpty()) {
      console.log("queue is empty");
      return;
    }
    return this.queue[0];
  }
}
