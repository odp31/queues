// linear data structure that operates in a circular manner 
// overcomes limitation of fixed size in a simple array-based queue by reusing the space once
// the rear reaches the end of the array 

public class CircularQueue {
  private int[] arr;
  private int front, rear, capacity;

  public CircularQueue(int size) {
    capacity = size;
    arr = new int[capacity];
    front = rear = -1;
  }
  public boolean isEmpty() {
    return front == -1;
  }
  public boolean isFull() {
    return (rear + 1) % capcity == front;
  }
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
    System.out.println(item + "enqueued to queue");
  }
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
    System.out.println(item + "dequeued from queue");
    return item;
  }
  public int peek() {
    if(isEmpty()) {
      System.out.println("queue is empty");
      return -1;
    }
    return arr[front];
  }
}
