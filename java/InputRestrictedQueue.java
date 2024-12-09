// allows insertion only from one end (usually the rear) and deletion from both ends (front and rear)
// useful in scenarios where you might need to remove elemetns from either end based on criteria

public class InputRestrictedQueue {
  private int[] arr;
  private int front, rear, capacity;

  public InputRestrictedQueue(int capacity) {
    this.capacity = capacity;
    arr = new int[capacity];
    front = rear = -1;
  }
  // function to check if queue is full
  public boolean isFull() {
    return(rear == capacity - 1);
  }
  // function to check if queue is empty
  public boolean isEmpty() {
    return (front == -1);
  }
  // function to insert element at rear
  public void enqueue(int item) {
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
  public int dequeueFront() {
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
  // function to delete element from rear
  public int dequeueRear() {
    if(isEmpty()) {
      System.out.println("queue is empty");
      return -1;
    }
    int item = arr[rear];
    if(front == rear) {
      front = rear = -1; // queue becomes empty
    } else if (rear == 0) {
      rear = capacity - 1;
    } else {
      rear--;
    }
    return item;
  }
}
