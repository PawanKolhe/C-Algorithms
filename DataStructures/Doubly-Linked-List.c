#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* prev;
  struct node* next;
};

struct node *head, *tail;

void insertBefore(struct node *n){
  int x;
  printf("\nEnter (x): ");
  scanf("%d", &x);

  if(head->data == x){
    head->prev = n;
    n->next = head;
    head = n;
    return;
  }

  struct node *p = head;
  while(p != NULL){
    if(p->data == x){
      struct node *tmp = p->prev;
      p->prev = n;
      n->next = p;
      n->prev = tmp;
      tmp->next = n;
      printf("\nInserted data (%d)\n", n->data);
      return;
    }
    p = p->next;
  }

  printf("\nNo data (%d)\nInserted to last\n", x);
  tail->next = n;
  n->prev = tail;
  tail = n;
}

void insertAfter(struct node *n){
  int x;
  printf("\nEnter (x): ");
  scanf("%d", &x);

  struct node *p = head;
  while(p != tail){
    if(p->data == x){
      struct node *tmp = p->next;
      p->next = n;
      n->prev = p;
      n->next = tmp;
      tmp->prev = n;
      printf("\nInserted data (%d)\n", n->data);
      return;
    }
    p = p->next;
  }

  printf("\nNo data (%d)\nInserted to last\n", x);
  tail->next = n;
  n->prev = tail;
  tail = n;
}

void insert(){
  int d;
  printf("\nEnter data: ");
  scanf("%d", &d);

  struct node *newn = (struct node*)malloc(sizeof(struct node));
  newn->data = d;
  newn->prev = NULL;
  newn->next = NULL;

  if(head == NULL){
    head = tail = newn;
    printf("\nCreated List.\n");
  }else{
    int c;
    printf("\n1. First\n2. Before (x)\n3. After (x)\n4. Last\n");
    scanf("%d", &c);
    switch(c){
      case 1: 
        head->prev = newn;
        newn->next = head;
        head = newn;
        break;
      case 2: insertBefore(newn); break;
      case 3: insertAfter(newn); break;
      case 4:
        tail->next = newn;
        newn->prev = tail;
        tail = newn;
        break;
      default: printf("\nWrong input!"); break;
    }
  }
}

void displayForward(){
  struct node *p = head;
  if(head == NULL){
    printf("\nNo data to display!");
    return;
  }

  printf("\nList data: ");
  while(p != NULL){
    printf(" %d", p->data);
    p = p->next;
  }
}

void displayBackward(){
  struct node *p = tail;
  if(tail == NULL){
    printf("\nNo data to display!");
    return;
  }

  printf("\nList data(Backward): ");
  while(p != NULL){
    printf(" %d", p->data);
    p = p->prev;
  }
}

void display(){
  int c;
  printf("\n1. Forward(head -> tail)\n2. Backward(tail -> head)\n Choice: ");
  scanf("%d", &c);
  switch(c){
    case 1: displayForward(); break;
    case 2: displayBackward(); break;
    default: printf("\nWrong input!"); break;
  }
}

void delete(){
  int x;
  printf("\nEnter (x): ");
  scanf("%d", &x);

  if(head->data == x){
    head->next->prev = NULL;
    head = head->next;
    free(head);
    printf("\nDeleted data (%d)\n", x);
    return;
  }

  if(tail->data == x){
    tail->prev->next = NULL;
    tail = tail->prev;
    free(tail);
    printf("\nDeleted data (%d)\n", x);
    return;
  }

  struct node *p = head;
  while(p != NULL){
    if(p->data == x){
      p->prev->next = p->next;
      p->next->prev = p->prev;
      free(p);
      printf("\nDeleted data (%d)\n", x);
      return;
    }
    p = p->next;
  }
}

void main()
{
  int c;
  while(1){
    printf("\n1. Create/Insert\n2. Display\n3. Delete\n4. Exit\n Choice: ");
    scanf("%d", &c);
    switch(c){
      case 1: insert(); break;
      case 2: display(); break;
      case 3: delete(); break;
      case 4: exit(0);
      default: printf("\nWrong input!"); break;
    }
  }
}
