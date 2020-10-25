#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"


typedef enum Sex{
    male = 0,
    female,
    other
}Sex_TypeDef;

typedef struct Student{

    int no;
    Sex_TypeDef sex;

}Student_TypeDef;


void create_student(list_t *l){

    int x;

    Student_TypeDef* s;

    s = malloc(sizeof(Student_TypeDef));
   
    if (s == NULL){
        printf("\nbad malloc ");
        return;
    }

    printf("\nEnter student number: ");
    scanf(" %d", &x);
    s->no = x;
    printf("\nEnter student sex(0:male 1:female 2:other): ");
    scanf(" %d", &x);
    s->sex = (Sex_TypeDef)x;
 
    list_push_front(l, s);
}


int find_student(size_t index, node_t *node, void* data){

    Student_TypeDef *n = (Student_TypeDef *)node->element;
    Student_TypeDef *d = (Student_TypeDef *)data;

    if(n->no == d->no)
        return 1;
    else
        return 0;
}

void delete_student(list_t *l){

    int x;
    Student_TypeDef* s;

    s = malloc(sizeof(Student_TypeDef));
   
    if (s == NULL){
        printf("\nbad malloc ");
        return;
    }

    printf("\nEnter student number: ");
    scanf(" %d", &x);                    
    s->no = x;
    
    int a = list_remove_node_if(l, find_student, s);
    printf("\n%d node deleted!", a);
     
}

int print_student(size_t index, node_t *node, void* data){

    Student_TypeDef *s = (Student_TypeDef*)node->element;
    printf("\nno: %d", (int)index);
    printf("\n>>>Student Number: %d", s->no);
    printf("\n>>>Enter student sex: %d ", s->sex);
}
void display_student(list_t *l){

    void *data;
    list_iterate_over_nodes(l, print_student, data);
}
void main()
{
 printf("< - Link List - Creation - Deletion - Traversal - >\n");
    int ch;
    list_t *l;
    l = list_create();
    while(1){
        printf("\n*********************************");
        printf("\n1. create/insert() \n2. display()\n3. delete()\n4.exit()\n Choice: ");
        scanf(" %d", &ch);

        switch(ch){

         case 1: create_student(l); break;
         case 2: display_student(l); break;
         case 3: delete_student(l); break;
         case 4: exit(1); break;
         default: printf("\nwrong input!");break;
        }
    }
}
