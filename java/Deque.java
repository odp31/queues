// double ended queue
// allows insertion and deletion of elements from both ends 

public class Deque<T> {
  private Node<T> front, rear;

  private class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) {
      this.data = data;
      this.next = null;
    }
  }
  public void addFront(T data) {
    Node<T> newNode = new Node<>(data);
    if(isEmpty()) {
      front = rear = newNode;
    } else {
      newNode.next = front;
      front = newNode;
    }
  }
  public void addRear(T data) {
    Node<T> newNode = new Node<>(data);
    if(isEmpty()) {
      front = rear = newNode;
    } else {
      rear.next = newNode;
      rear = newNode;
    }
  }
  public T removeFront() {
    if(isEmpty()) {
      throw new IllegalStateException("deque is empty");
    }
    T data = front.data;
    if(front == rear) {
      front = rear = null;
    } else {
      front = front.next;
    }
    return data;
  }
  public T removeRear() {
    if(isEmpty()) {
      throw new IllegalStateException("deque is empty");
    }
    T data = rear.data;
    if(front == rear) {
      front = rear = null;
    } else {
      Node<T> temp = front;
      while(temp.next != rear) {
        temp = temp.nexxt;
      }
      temp.next = null;
      rear = temp;
    }
    return data;
  }
  public T peekFront() {
    if(isEmpty()) {
      throw new IllegalStateException("deque is empty");
    }
    return front.data;
  }
  public T peekRear() {
    if(isEmpty()) {
      throw new IllegalStateException("deque is empty");
    }
    return rear.data;
  }
  public boolean isEmpty() {
    return front == null;
  }
}
