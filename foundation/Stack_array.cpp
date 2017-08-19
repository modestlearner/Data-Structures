#include<iostream>
using namespace std;
#define MAX_SIZE 3

struct Stack{
  char a[MAX_SIZE];
  int size;
};
typedef struct Stack Stack;

void Stack_init(Stack *S){
  S->size=0;
}

bool Stack_empty(Stack *S){
  return (S->size==0);
}

bool Stack_full(Stack *S){
  return (S->size==MAX_SIZE);
}

bool Stack_top(Stack *S, char &element){
  if(Stack_empty(S)){
    return false;
  }
  else{
    element=S->a[S->size-1];
    return true;
  }
}

bool Stack_push(Stack *S,char element){
  if(Stack_full(S)){
    return false;
  }
  else{
    S->a[S->size++]=element;
    return true;
  }
}

bool Stack_pop(Stack *S,char &element){
  if(Stack_empty(S)){
    return false;
  }
  else{
    S->size--;
    element=S->a[S->size];
    return true;
  }
}

int main(){
  Stack s1;
  char element;

  //INITIALIZING STACK
  Stack_init(&s1);

  //Confirming that it is empty
  if(Stack_empty(&s1)==1){
    cout<<"Stack empty as expected"<<endl;
  }
  else{
    cout<<"Stack not empty"<<endl;
  }

  //PUSH Element F
  element='F';
  if(Stack_push(&s1,element)==1){
    cout<<"Element "<<element<<"pushed"<<endl;
  }
  else{
    cout<<"Stack is full"<<endl;
  }
  element='R';
  if(Stack_push(&s1,element)==1){
    cout<<"Element "<<element<<"pushed"<<endl;
  }
  else{
    cout<<"Stack is full"<<endl;
  }
  element='Y';
  if(Stack_push(&s1,element)==1){
    cout<<"Element "<<element<<"pushed"<<endl;
  }
  else{
    cout<<"Stack is full"<<endl;
  }
  element='X';
  if(Stack_push(&s1,element)==1){
    cout<<"Element "<<element<<"pushed"<<endl;
  }
  else{
    cout<<"Stack is full"<<endl;
  }

  //ACCESS TOP ELEMENT
  if(Stack_top(&s1,element)==1){
    cout<<"Top element is "<<element<<endl;
  }
  else{
    cout<<"Empty Stack";
  }

  //POPPING ALL ELEMENTS FROM STACK
  for(int i=0;i<10;i++){
    if(Stack_pop(&s1,element)==1){
      cout<<"Element "<<element<<"Popped"<<endl;
    }
    else{
      cout<<"Stack empty"<<endl;
      break;
    }
  }


}
