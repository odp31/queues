#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} OutputRestrictedQueue;

void init_queue(OutputRestrictedQueue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

int is_empty(OutputRestrictedQueue *queue) {
  return queue->front == -1;
}

int is_full(OutputRestrictedQueue *queue) {
  return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue_front(OutputRestrictedQueue *queue, int item) {
  if(is_full(queue)) {
    printf("queue is full");
    return;
  }
  if(is_empty(queue)) {
    queue->front = queue->rear = 0;
  } else if (queue->front == 0) {
    queue->front = MAX_SIZE - 1;
  } else {
    queue->front = (queue->front - 1) % MAX_SIZE;
  }
  queue->items[queue->front] = item;
}

void enqueue_rear(OutputRestrictedQueue *queue, int item) {
  if(is_full(queue)) {
    printf("queue is full");
    return;
  }
  if(is_empty(queue)) {
    queue->front = queue->rear = 0;
  } else {
    queue->rear = (queue->rear + 1) % MAX_SIZE;
  }
  queue->items[queue->rear] = item;
}


int deque(OutputRestrictedQueue *queue) {
  if(is_empty(queue)) {
    printf("queue is empty");
    return -1;
  }
  int item = queue->items[queue->front];
  if(queue->front == queue->rear) {
    queue->front = queue->rear = -1;
  } else {
    queue->front = (queue->front + 1) % MAX_SIZE;
  }
  return item;
}

void print_queue(OutputRestrictedQueue *queue) {
  if(is_empty(queue)) {
    printf("queue is empty");
    return;
  }
  printf("queue: ");
  for(int i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
    printf("%d ", queue->items[i]);
  }
  printf("%d\n", queue->items[queue->rear]);
}

int main() {
  OutputRestrictedQueue queue;
  init_queue(&queue);
  enqueue_front(&queue, 10);
  enqueue_rear(&queue, 20);
  enqueue_front(&queue, 30);

  print_queue(&queue);

  printf("dequeued item: %d\n", dequeue(&queue));
  printf("dequeued item: %d\n", dequeue(&queue));
  print_queue(&queue);
  return 0;
}
