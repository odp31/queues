// linear data structure that operates like a queue but with a fixed size 
// once queue is full, next element to be inserted overwrites oldest element

class CircularQueue {
  constructor(size) {
    this.queue = new Array(size);
    this.front = this.rear = -1;
    this.size = size;
  }
  isEmpty() {
    return this.front === -1;
  }
  isFull() {
    return (this.rear + 1) % this.size === this.front;
  }
  enqueue(item) {
    if(this.isFull()) {
      console.log("queue is full");
      return;
    }
    if(this.isEmpty()) {
      this.front = this.rear = 0;
    } else {
      this.rear = (this.rear + 1) % this.size;
    }
    this.queue[this.rear] = item;
  }
  dequeue() {
    if(this.isEmpty()) {
      console.log("queue is empty");
      return;
    }
    const item = this.queue[this.front];
    if(this.front === this.rear) {
      this.front = this.rear = -1;
    } else {
      this.front = (this.front + 1) % this.size;
    }
    return item;
  }

  printQueue() {
    if(this.isEmpty()) {
      console.log("queue is empty");
      return;
    }
    let i = this.front;
    while(i != this.rear) {
      console.log(this.queue[i]);
      i = (i + 1) % this.size;
    }
    console.log(this.queue[i]);
  }
}
