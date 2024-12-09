#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
  int min_index;
} MinDeque;

void init_deque(MinDeque *deque) {
  deque->front = -1;
  deque->rear = -1;
  deque->min_index = -1;
}

int is_empty(MinDeque *deque) {
  return deque->front == -1;
}
int is_full(MinDeque *deque) {
  return(deque->rear + 1) % MAX_SIZE == deque->front;
}
void insert_front(MinDeque *deque, int item) {
  if(is_full(deque)) {
    printf("deque is full");
    return;
  }
  if(is_empty(deque)) {
    deque->front = deque->rear = 0;
    deque->min_index = 0;
  } else if(deque->front == 0) {
    deque->front = MAX_SIZE - 1;
  } else {
    deque->front = (deque->front - 1) % MAX_SIZE;
  }
  deque->items[deque->front] = item;
  if(item < deque->items[deque->min_index]) {
    deque->min_index = deque->front;
  }
}
void insert_rear(MinDeque *deque, int item) {
  if(is_full(deque)) {
    printf("deque is full");
    return;
  }
  if(is_empty(deque)) {
    deque->front = deque->rear = 0;
    deque->min_index = 0;
  } else {
    deque->rear = (deque->rear + 1) % MAX_SIZE;
  }
  deque->items[deque->rear] = item;
  if(item < deque->items[deque->min_index]) {
    deque->min_index = deque->rear;
  }
}

int delete_front(MinDeque *deque) {
  if(is_empty(deque)) {
    printf("deque is empty");
    return -1;
  }
  int item = deque->items[deque->front];
  if(deque->front == deque->rear) {
    deque->front = deque->rear = -1;
    deque->min_index = -1;
  } else {
    deque->front = (deque->front + 1) % MAX_SIZE;
    if(deque->front == deque->min_index) {
      int min_val = deque->items[deque->front];
      deque->min_index = deque->front;
      for(int i = (deque->front + 1) % MAX_SIZE; i != deque->rear; i = (i + 1) % MAX_SIZE) {
        if(deque->items[i] < min_val) {
          min_val = deque->items[i];
          deque->min_index = i;
        }
      }
    }
  }
  return item;
}

int delete_rear(MinDeque *deque) {
  if(is_empty(deque)) {
    printf("deque is empty");
    return -1;
  }
  int item = deque->items[deque->rear];
  if(deque->front == deque->rear) {
    deque->front = deque->rear = -1;
    deque->min_index = -1;
  } else if(deque->rear == 0) {
    deque->rear = MAX_SIZE - 1;
  } else {
    deque->rear = (deque->rear - 1) % MAX_SIZE;
  }
  if(deque->rear == deque->min_index) {
    int min_val = deque->items[deque->front];
    deque->min_index = deque->front;
    for(int i = (deque->front + 1) % MAX_SIZE; i != deque->rear; i = (i + 1) % MAX_SIZE) {
      if(deque->items[i] < min_val) {
        min_val = deque->items[i];
        deque->min_index = i;
      }
    }
  }
  return item;
}

int get_min(MinDeque *deque) {
  if(is_empty(deque)) {
    printf("deque is empty");
    return -1;
  }
  return deque->items[deque->min_index];
}

void print_deque(MinDeque *deque) {
  if(is_empty(deque)) {
    printf("deque is empty");
    return;
  }
  printf("deque: ");
  for(int i = deque->front; i != deque->rear; i = (i + 1) % MAX_SIZE) {
    printf("%d ", deque->items[i]);
  }
  printf("%d\n", deque->items[deque->rear]);
}

int main() {
  MinDeque deque;
  init_deque(&deque);
  insert_rear(&deque, 10);
  insert_front(&deque, 20);
  insert_rear(&deque, 5);
  insert_front(&deque, 30);

  print_deque(&deque);
  printf("min element: %d\n", get_min(&deque));

  printf("deleted item: %d\n", delete_front(&deque));
  printf("deleted item: %d\n", delete_rear(&deque));
  print_deque(&deque);

  printf("minimum element: %d\n", get_min(&deque));
  return 0;
}
