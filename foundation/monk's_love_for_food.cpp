#include<iostream>
using namespace std;
struct stack{
  int size;
  int a[100];
};
typedef struct stack stack;

struct query{
  int a,b;
};

void stack_init(stack *s){
  s->size=0;
}
bool stack_empty(stack *s){
  return (s->size==0);
}
bool stack_full(stack *s,int n){
  return (s->size==(n-1));
}
bool stack_push(stack *s,int n, int element){
  if(stack_full(s,n)){
    return false;
  }
  else{
    s->a[s->size++]=element;
    return true;
  }
}
bool stack_pop(stack *s,int &element){
  if(stack_empty(s)){
    return false;
  }
  else{
    s->size--;
    element=s->a[s->size];
    return true;
  }
}
void food_check(stack *s,int n){
  query q;
  int top=-1;
  for(int i=0 ;i<n;i++){
    cin>>q.a;
    if(q.a==2){
      cin>>q.b;
      top++;
      stack_push(s,n,q.b);
    }
    if(q.a==1){
      if(top==-1){
        cout<<"NO FOOD";
        break;
      }
      else{
      stack_pop(s,q.b);
      cout<<"popped element is "<<q.b<<endl;
      top--;
      }
    }
  }
}
int main(){
  stack s1;
  int n;
  cout<<"ENTER SIZE"<<endl;
  cin>>n;
  stack_init(&s1);
  food_check(&s1,n);
}
