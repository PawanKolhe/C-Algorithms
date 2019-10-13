#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node* link;
}*root;

void create(){

   int x;

   struct node* newn;
   newn = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter Data: ");
    scanf(" %d", &x);
    newn -> data = x;
    newn -> link = NULL;

       if(root == NULL){
        root = newn;
        printf("\nRoot Node created!");
       }

       else{
        struct node *p;
        p = root;

         while(p -> link != NULL)
             p = p -> link;
    

         p -> link = newn;
         newn -> link = NULL;

         printf("\nNode inserted!");
       }
}

void delt(){
    struct node *p, *c;
    p = root;
    c = root;
    
    if (p == NULL)
        printf("\nNo Data to delete!");
    
    else{
        
        while(p -> link != NULL){
           c = p ;
           p = p -> link;
          
        }
           printf("\n%d node deleted!", p -> data);
           c -> link = NULL;
            free(p);
     }
     
}

void display(){

struct node* tmp;
tmp = root;

if(root == NULL)
    printf("\nNo data to display!");

printf("\nLink list data: ");

  while(tmp != NULL){
    printf(" %d", tmp -> data);
    tmp = tmp -> link;
  }

}
void main()
{
 printf("< - Link List - Creation - Deletion - Traversal - >\n");
    int ch;
    while(1){
        printf("\n1. create/insert() \n2. display()\n3. delete()\n4.exit()\n Choice: ");
        scanf(" %d", &ch);

        switch(ch){

         case 1: create(); break;
         case 2: display(); break;
         case 3: delt(); break;
         case 4: exit(1); break;
         default: printf("\nwrong input!");break;
        }
    }
}