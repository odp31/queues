// queue where each element has a priority associated with it 
// elements with higher priority are dequeued before elements with lower priority 

class PriorityQueue {
  constructor() {
    this.heap = [];
  }
  isEmpty() {
    return this.heap.length === 0;
  }
  enqueue(element, priority) {
    const node = { element, priority };
    this.heap.push(node);
    this.heapifyUp(this.heap.length - 1);
  }
  dequeue() {
    if(this.isEmpty()) {
      return null;
    }
    const root = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.heapifyDown(0);
    return root.element;
  }

  peek() {
    if(this.isEmpty()) {
      return null;
    }
    return this.heap[0].element;
  }

  heapifyUp(index) {
    let parentIndex = Math.floor((index - 1) / 2);
    while (index > 0 && this.heap[index].priority < this.heap[parentIndex].priority) {
      [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
      index = parentIndex;
      parentIndex = Math.floor((index - 1) / 2);
    }
  }

  heapifyDown(index) {
    let leftChildIndex = 2 * index + 1;
    let rightChildIndex = 2 * index + 2; 
    let smallest = index;

    if(leftChildIndex < this.heap.length && this.heap[leftChildIndex].priority < this.heap[smallest].priority) {
      smallest = leftChildIndex;
    }
    if(rightChildIndex < this.heap.length && this.heap[rightChildIndex].priority < this.heap[smallest].priority) {
      smallest = rightChildIndex;
    }
    if(smallest !== index) {
      [this.heap[index], this.heap[smallest]] = [this.heap[smallest], this.heap[index]];
      this.heapifyDown(smallest);
    }
  }
}
