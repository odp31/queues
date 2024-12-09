#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE]:
  int size;
} PriorityQueue;

void init_queue(PriorityQueue *queue) {
  queue->size = 0;
}
int is_empty(PriorityQueue *queue) {
  return queue-> size == 0;
}
int is_full(PriorityQueue *queue) {
  return queue->size == MAX_SIZE;
}
void heapify(PriorityQueue *queue, int index) {
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if(left < queue->size && queue->items[left] > queue->items[largest]) {
    largest = left;
  }
  if(right < queue->size && queue->items[right] > queue->items[largest]) {
    largest = right;
  }
  if(largest != index) {
    int temp = queue->items[index];
    queue->items[index] = queue->items[largest];
    queue->items[largest] = temp;

    heapify(queue, largest);
  }
}

void insert(PriorityQueue *queue, int item) {
  if(is_full(queue)) {
    printf("queue is full");
    return;
  }
  queue->items[queue->size] = item;
  int i = queue->size;
  while(i > 0 && queue->items[(i - 1) / 2] < queue->items[i]) {
    int temp = queue->items[i];
    queue->items[i] = queue->items[(i - 1) / 2];
    queue->items[(i - 1) / 2] = temp;
    i = (i - 1) / 2;
  }
  queue->size++;
}

int extract_max(PriorityQueue *queue) {
  if(is_empty(queue)) {
    printf("queue is empty");
    return -1;
  }
  int max_item = queue->items[0];
  queue->items[0] = queue->items[queue->size - 1];
  queue->size--;
  heapify(queue, 0);
  return max_item;
}

void print_queue(PriorityQueue *queue) {
  if(is_empty(queue)) {
    printf("queue is empty");
    return;
  }
  printf("queue: ");
  for(int i = 0; i < queue->size; i++) {
    printf("%d ", queue->items[i]);
  }
  printf("\n");
}

int main() {
  PriorityQueue queue;
  init_queue(&queue);
  insert(&queue, 10);
  insert(&queue, 5);
  insert(&queue, 15);
  insert(&queue, 2);

  print_queue(&queue);
  printf("extracted max: %d\n", extract_max(&queue)):
  printf("extracted max: %d\n", extract_max(&queue));
  print_queue(&queue);

  return 0;
}
