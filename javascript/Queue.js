class Queue {
  constructor() {
    this.items = [];
  }
  enqueue(item) {
    this.items.push(item);
  }
  dequeue() {
    if(this.isEmpty()) {
      return "queue is empty";
    }
    return this.items.shift();
  }
  front() {
    if(this.isEmpty()) {
      return "queue is empty";
    }
    return this.items[0];
  }
  isEmpty() {
    return this.items.length === 0;
  }
  size() {
    return this.items.length;
  }
}

// usage example
const queue = new Queue();
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);

console.log(queue.front());
console.log(queue.dequeue());
console.log(queue.dequeue());
console.log(queue.size());
