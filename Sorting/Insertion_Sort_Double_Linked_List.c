#include <stdio.h>
#include <stdlib.h>

/* InsertionSort for double-linked lists */

typedef struct Node{
int data;
struct Node *next;
struct Node *prev;
}Node;
/* the algorithm */
Node *InsertionSort (Node *myList){
	int key;
	myList->prev = NULL;
	Node *j=NULL;
	Node *i=NULL;
	Node *temp=myList;
	j=myList->next;
	while(j!=NULL){
		key=j->data;
		i=j->prev;
		while( i != NULL && i->data > key) {
			i->next->data = i ->data;
			i=i->prev;
		}
		if(i!=NULL){
			i->next->data=key;
		}else{
			i=myList;
			i->data=key;
		}
		j=j->next;
	}
	return temp;
}
/* an example main to test that the algorithm actually runs */
int main(){
	int i,val;
	Node *head = (Node *)malloc(sizeof(struct Node));
	Node *n=head;
	Node *tail=n;
	Node *temp;
	head->prev=NULL;
	for (i=0;i<10;i++){
		n->next=(Node *) malloc(sizeof(struct Node));
		printf("Give 10 values:\n");
		scanf("%d",&val);
		n->data=val;
		n=n->next;
		n->prev=tail;
		tail=n;
	}
	n->prev->next=NULL;
	temp=head;
	printf("before sort: \n");
	while(temp!=NULL){
		printf(" |%d| ", temp->data);
		temp=temp->next;
	}
	printf("\n");
	printf("after sort: \n");
	temp=InsertionSort(head);
	while(temp!=NULL){
                printf(" |%d| ",temp->data);
                temp=temp->next;
        }
        printf("\n");
	return 0;
}

