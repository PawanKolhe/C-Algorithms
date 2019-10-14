struct sNode
{
    char data;
    struct sNode *next;
};

void push(struct sNode** topref,int newdata)
{
    struct sNode* newnode = (struct sNode*) malloc(sizeof(struct sNode));
    newnode->data=newdata;
    newnode->next=(*topref);
    (*topref)=newnode;
}
int pop(struct sNode** topref)
{
    char res; 
    struct sNode *top; 
  
  /*If stack is empty then error */
  if (*topref == NULL) 
  { 
     exit(0); 
  } 
  else
  { 
     top = *topref; 
     res = top->data; 
     *topref = top->next; 
     free(top); 
     return res; 
  } 
}
bool isMatching(char character1, char character2) 
{ 
   if (character1 == '(' && character2 == ')') 
     return 1; 
   else if (character1 == '{' && character2 == '}') 
     return 1; 
   else if (character1 == '[' && character2 == ']') 
     return 1; 
   else
     return 0; 
} 

bool isValid(char  s[]){
    int i;
    struct sNode *stack=NULL;
    while(s[i])
    {
        if(s[i] == '(' ||s[i] == '{' || s[i] =='[')
            push(&stack,s[i]);
        if(s[i] ==')'||s[i]=='}'||s[i]==']')
        {
            if(stack == NULL)
                return false;
            
            else if(!isMatching(pop(&stack),s[i]))
                return false;
        }
        i++;
    }
    if(stack ==NULL)
        return true;
    else
        return false;
    

}

