#include<iostream>
#define MAX 100
using namespace std;

struct stack{
   char a[100];
   int size;
};
typedef struct stack stack;

void stack_init(stack *s){
  s->size=0;
}

bool stack_empty(stack *s){
  return (s->size==0);
}

bool stack_full(stack *s,int n){
  return (s->size==(n-1));
}

bool stack_push(stack *s,char element,int n){
  if(stack_full(s,n)==true){
    return false;
  }
  else{
    s->a[s->size++]=element;
    return true;
  }
}

bool stack_pop(stack *s){
  if(stack_empty(s)==true){
    return false;
  }
  else{
    s->size--;
    //element=s->a[s->size];
    return true;
  }
}

int check_balanced(stack *s,char str[],int n){
  int top=-1,i;
  for(i=0;i<n;i++){
    if(str[i]=='('){
      top++;
      stack_push(s,str[top],n);

    }
    if(str[i]==')'){
      if(top==-1){
        top=top-1;
        break;
      }
      else{
        stack_pop(s);
        top--;
      }
    }
    if(top==-1){
      return 1;
    }
  }
}
int len(char str[]){
  int i=0;
  while(str[i]!='\0'){
    i++;
  }
  return i;
}

int main(){
  stack s1;
  char str[MAX];
  int n;
  fgets(str,MAX,stdin);
  n=len(str);
  stack_init(&s1);
  if(check_balanced(&s1,str,n)==1){
    cout<<"BALANCED STRING";
  }
  else{
    cout<<"UNBALANCED";
  }
}
