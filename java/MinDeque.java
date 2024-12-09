// data structure that allows insertion and deletion from both ends 
// also provides minimum element at any given time

public class MinDeque {
  private Node head;
  private Node tail;
  private Node minNode;      // node pointing to min element

  private class Node {
    int val;
    Node prev, next;
    Node(int val) {
      this.val = val;
    }
  }
  public void pushFront(int val) {
    Node newNode = new Node(val);
    if(head == null) {
      head = tail = minNode = newNode;
    } else {
      newNode.next = head;
      head.prev = newNode;
      head = newNode;
      minNode = min(minNode, newNode);
    }
  }
  public void pushBack(int val) {
    Node newNode = new Node(val);
    if(tail == null) {
      head = tail = minNode = newNode;
    } else {
      tail.next = newNode;
      newNode.prev = tail;
      tail = newNode;
      minNode = min(minNode, newNode);
    }
  }
  public int popFront() {
    if(head == null) {
      throw new IllegalStateException("deque is empty");
    }
    int val = head.val;
    head = head.next;
    if(head != null) {
      head.prev = null;
      minNode = min(minNode, head);
    } else {
      tail = null;
      minNode = null;
    }
    return val;
  }
  public int popBack() {
    if(tail == null) {
      throw new IllegalStateException("deque is empty");
    }
    int val = tail.val;
    tail = tail.prev;
    if(tail != null) {
      tail.next = null;
      minNode = min(minNode, tail);
    } else {
      head = null;
      minNode = null;
    }
    return val;
  }
  public int getMin() {
    if(minNode == null) {
      throw new IllegalStateException("deque is empty");
    }
    return minNode.val;
  }
  private Node min(Node a, Node b) {
    return a.val <= b.val ? a : b;
  }
}
