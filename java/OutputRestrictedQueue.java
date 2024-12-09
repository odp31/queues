// allows insertion from both ends but deletion only from one (usually front)
// useful in scenarios where you might need to add elements from both ends but can only process them in a FIFO manner

public class OutputRestrictedQueue {
  private int[] arr;
  private int front, rear, capacity;

  public OutputRestrictedQueue(int capacity) {
    this.capacity = capacity;
    arr = new int[capacity];
    front = rear = -1;
  }
  // function to check if queue is full
  public boolean isFull() {
    return (rear + 1) % capacity == front;
  }
  // function to check if queue is empty
  public boolean isEmpty() {
    return front == -1;
  }
  // function to insert element at front
  public void enqueueFront(int item) {
    if(isFull()) {
      System.out.println("queue is full");
      return;
    }
    if(isEmpty()) {
      front = rear = 0;
    } else if (front == 0) {
      front = capacity - 1;
    } else {
      front--;
    }
    arr[front] = item;
  }
  // function to insert element at rear
  public void enqueueRear(int item) {
    if(isFull()) {
      System.out.println("queue is full");
      return;
    }
    if(isEmpty()) {
      front = rear = 0;
    } else {
      rear = (rear + 1) % capacity;
    }
    arr[rear] = item;
  }
  // function to delete element from front
  public int dequeue() {
    if(isEmpty()) {
      System.out.println("queue is empty");
      return -1;
    }
    int item = arr[front];
    if(front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % capacity;
    }
    return item;
  }
}
