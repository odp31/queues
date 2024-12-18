class Deque {
  constructor() {
    this.items = [];
  }
  isEmpty() {
    return this.items.length === 0;
  }
  addFront(elements) {
    this.items.unshift(element);
  }
  addRear(element) {
    this.items.push(element);
  }
  removeFront() {
    if(this.isEmpty()) {
      return 'underflow';
    }
    return this.items.shift();
  }
  removeRear() {
    if(this.isEmpty()) {
      return 'underflow';
    }
    return this.items.pop();
  }
  peekFront() {
    if(this.isEmpty()) {
      return 'underflow';
    }
    return this.items[0];
  }
  peekRear() {
    if(this.isEmpty()) {
      return 'underflow';
    }
    return this.items[this.items.length - 1];
  }
}
