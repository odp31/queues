import java.util.PriorityQueue;

public class PriorityQueueExample {
  public static void main(String[] args) {
    PriorityQueue<Integer> pq = new PriorityQueue();
    pq.add(10);
    pq.add(5);
    pq.add(15);
    pq.add(2);
    // remove and print elements in priority order
    while(!pq.isEmpty()) {
      System.out.print(pq.poll() + " ");
    }
  }
}
