#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} CircularQueue;


void init_queue(CircularQueue *queue) {
  queue->front = -1;
  queue->rear = -1;
}
int is_empty(CircularQueue *queue) {
  return queue->front == -1;
}
int is_full(CircularQueue *queue) {
  return(queue->rear + 1) % MAX_SIZE == queue->front;
}
void enqueue(CircularQueue *queue, int item) {
  if(is_full(queue)) {
    printf("queue is full\n");
    return;
  }
  if(is_empty(queue)) {
    queue->front = queue->rear = 0;
  } else {
      queue->rear = (queue->rear + 1) % MAX_SIZE;
  }
  queue->items[queue->rear] = item;
}

int dequeue(CircularQueue *queue) {
  if(is_empty(queue)) {
    printf("queue is empty\n");
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

void print_queue(CircularQueue *queue) {
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
  CircularQueue queue;
  init_queue(&queue);

  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  print_queue(&queue);
  printf("dequeued item: %d\n", dequeue(&queue));
  printf("dequeued item: %d\n", dequeue(&queue));

  print_queue(&queue);

  return 0;
}
