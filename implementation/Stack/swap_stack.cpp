#include<iostream>
using namespace std;

struct stack{
  int size;
  int a[1000];
};
typedef struct stack stack;
void stack_init(stack *s){
  s->size=0;
}
bool stack_empty(stack *s){
  return (s->size==0);
}
int stack_top(stack *s){
  if(stack_empty(s)){
    return -1;
  }
  else{
    int top=s->a[s->size-1];
    return top;
  }
}
bool stack_push(stack *s,int element){
  s->a[s->size++]=element;
  return true;
}
bool stack_pop(stack *s){
  if(stack_empty(s)){
    return false;
  }
  else{
    s->size--;
    return true;
  }
}
void swap(stack *s,stack *s1){
  stack s3;
  stack_init(&s3);
  int q=s->size;
  int w=s1->size;
  while(stack_empty(s)==false){
      int k=stack_top(s);
      stack_pop(s);
      stack_push(&s3,k);
  }
  while(stack_empty(s1)==false){
      int t=stack_top(s1);
      stack_pop(s1);
      stack_push(&s3,t);
  }
  for(int i=0;i<w;i++){
    int t=stack_top(&s3);
    stack_push(s,t);
    stack_pop(&s3);
  }
  for(int i=0;i<q;i++){
    int t=stack_top(&s3);
    stack_push(s1,t);
    stack_pop(&s3);
  }
}
int main(){
  stack s1,s2;
  int ele;
  stack_init(&s1);
  stack_init(&s2);
  ele=1;
  stack_push(&s1,ele);
  ele=2;
  stack_push(&s1,ele);
  ele=3;
  stack_push(&s2,ele);
  ele=4;
  stack_push(&s2,ele);
  ele=5;
  stack_push(&s2,ele);
  for(int i=0;i<s2.size;i++){
    // cout<<s1.a[i];
    cout<<s2.a[i];
  }
  cout<<endl;
  swap(&s1,&s2);
  for(int i=0;i<s2.size;i++){
    // cout<<s1.a[i];
    cout<<s2.a[i];
  }
}
