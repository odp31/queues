#include <stdio.h>
#indlude <stdlib.h>

#define MAX_SIZE 100

typedef Struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} InputRestrictedQueue;

void init_queue(InputRestrictedQueue *queue) {
  queue->front = -1;
  queue->rear = -1;
}
int is_empty(InputRestrictedQueue *queue) {
  return queue->front == -1;
}
int is_full(InputRestrictedQueue *queue) {
  return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(InputRestrictedQueue *queue, int item) {
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

int dequeue_front(InputRestrictedQueue *queue) {
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

int dequeue_rear(InputRestrictedQueue *queue) {
  if(is_empty(queue)) {
    printf("queue is empty");
    return -1;
  }
  int item = queue->items[queue->rear];
  if(queue->front == queue->rear) {
    queue->front = queue->rear = -1;
  }
  else if(queue->rear == 0) {
    queue->rear = MAX_SIZE - 1;
  } else {
    queue->rear = (queue->rear - 1) % MAX_SIZE;
  }
  return item;
}

void print_queue(InputRestrictedQueue *queue) {
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
  InputRestrictedQueue queue;
  init_queue(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);
  print_queue(&queue);

  printf("dequed item from front: %d\n", dequeue_front(&queue));
  printf("dequed item from rear: %d\n", dequeue_rear(&queue));
  print_queue(&queue);

  return 0;
}
