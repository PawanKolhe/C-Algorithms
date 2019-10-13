/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int queue[20];
int rear = -1;
int front = -1;
int size;

void enqueue(){
    
    int x;
    
     printf("Enter data: ");
     scanf(" %d", &x);
    
    if( (rear >= size-1 && front == 0) || front == rear + 1)
      printf("Node can't be added!");
      
      
      else if(rear == size - 1 && front != 0){
                rear = 0;
                queue[rear] = x;
      }
    
    else{
          if(front == -1)
            front++;
            
          queue[++rear] = x;
          
         printf("\nElement queued!");
    }
     
    
}

void dqueue(){
       if(front == -1 )
       printf("\nQueue Underflow!");
       
       else if(front == size - 1)
         {
             printf("\nDeleted element %d", queue[front]);
             front = 0;
         }
         
        else if(front == rear){
            printf("\nDeleted element %d", queue[front]);
            front = rear = -1;
        }
        
        else
        printf("\nDeleted element %d", queue[front++]);
}

void display(){
    
       if(front == -1 )
       printf("\nQueue Underflow!");
     
     
     printf("\nData in a queue: ");  
    if ( rear > front){
        
    
     for(int i  = front; i <= rear; i++)
       printf(" %d", queue[i]);
     }
    
    else{
        for(int i = front; i <= size-1 ; i++)
          printf(" %d", queue[i]);
          
        for(int j = 0; j <= rear ; j++)
            printf(" %d", queue[j]);
        
    }
}
int main()
{
    
    printf("< - Circular Queue - Creation - Deletion - Traversal - >\n");
    int ch;
    
    printf("Size of the Queue: ");
    scanf(" %d", &size);

    while(1){
        printf("\n1. Enqueue() \n2. Dqueue()\n3. Traversal()\n4.exit()\n Choice: ");
        scanf(" %d", &ch);

        switch(ch){

         case 1: enqueue(); break;
         case 2: dqueue(); break;
         case 3: display(); break;
         case 4: exit(1); break;
         default: printf("\nwrong input!");break;
        }
    }
   
    return 0;
}
