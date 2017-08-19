#include<iostream>
using namespace std;

struct node{
  char info;
  struct node *next;
};

struct stack{
  struct node *top;
};
typedef struct stack stack;

void stack_init(stack *s){
  s->top=NULL;
}

bool stack_empty(stack *s){
  return (s->top==NULL);
}

bool stack_top(stack *s , char &element){
  if(stack_empty(s)){
    return false;
  }
  else{
    element=s->top->info;
    return true;
  }
}

bool stack_push(stack *s,char value){
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->info=value;
  if(s->top!=NULL){
    temp->next=s->top;
    s->top=temp;
  }
  else{
    s->top=temp;
    temp->next=NULL;
  }
  return true;
}

bool stack_pop(stack *s, char &element){
  struct node *temp;
  if(stack_empty(s)){
    return false;
  }
  else{
    temp=s->top;
    s->top=temp->next;
    element=temp->info;
    free(temp);
    return true;
  }
}

int main(){
  stack s1;
  char element;

  //INITIALIZING STACK
  stack_init(&s1);

  //CHECK THAT STACK IS EMPTY OR NOT
  if(stack_empty(&s1)==true){
    cout<<"Stack empty as expected "<<endl;
  }
  else{
    cout<<"Error stack not empty"<<endl;
  }

  //PUSHING ELEMENT
  element='F';
  if(stack_push(&s1,element)==true){
    cout<<"Element "<<element<<" pushed"<<endl;
  }
  else{
    cout<<" stack is full";
  }
  element='R';
  if(stack_push(&s1,element)==true){
    cout<<"Element "<<element<<" pushed"<<endl;
  }
  else{
    cout<<" stack is full";
  }
  if(stack_top(&s1,element)==true){
    cout<<"Top element is "<<element<<endl;
  }
  else{
    cout<<"Stack is empty "<<endl;
  }
  for (int i=0;i<10;i++){
    if(stack_pop(&s1,element)==true){
      cout<<"Element "<<element<<" poppped"<<endl;
    }
    else{
      cout<<"Stack empty "<<endl;
      break;
    }

  }



}
