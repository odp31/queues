#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} Deque;

void init_deque(Deque *deque) {
  deque->front = -1;
  deque->rear = -1;
}
int is_empty(Deque *deque) {
  return deque->front == -1;
}
int is_full(Deque *deque) {
  return(deque->rear + 1) % MAX_SIZE == deque->front;
}
void insert_front(Deque *deque, int item) {
  if(is_full(deque)) {
    printf("deque is full\n");
    return;
  }
  if(is_empty(deque)) {
    deque->front = deque->rear = 0;
  } else if(deque->front == 0) {
      deque->front = MAX_SIZE - 1;
  } else {
      deque->front = (deque->front - 1) % MAX_SIZE;
  }
  deque->items[deque->front] = item;
}

void insert_rear(Deque *deque, int item) {
  if(is_full(deque)) {
    printf("deque is full\n");
    return;
  }
  if(is_empty(deque)) {
    deque->front = deque->rear = 0;
  } else {
      deque->rear = (deque->rear + 1) % MAX_SIZE;
  }
  deque->items[deque->rear] = item;
}

int delete_front(Deque *deque) {
  if(is_empty(deque)) {
    printf("deque is empty");
    return -1;
  }
  int item = deque->items[deque->front];
  if(deque->front == deque->rear) {
    deque->front = deque->rear = -1;
  } else { 
      deque->front = (deque->front + 1) % MAX_SIZE;
  }
  return item;
}

int delete_rear(Deque *deque) {
  if(is_empty(deque)) {
    printf("deque is empty");
    return -1;
  }
  int item = deque->items[deque->rear];
  if(deque->front == deque->rear) {
    deque->front = deque->rear = -1;
  } else if (deque->rear == 0) {
    deque->rear = MAX_SIZE - 1;
  } else {
    deque->rear = (deque->rear - 1) % MAX_SIZE;
  }
  return item;
}

void print_deque(Deque *deque) {
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
  Deque deque;
  init_deque(&deque);

  insert_rear(&deque, 10);
  insert_front(&deque, 20);
  insert_rear(&deque, 30);
  print_deque(&deque);

  printf("deleted item: %d\n", delete_front(&deque));
  printf("deleted item: %d\n", delete_rear(&deque));

  print_deque(&deque);
  return 0;
}
