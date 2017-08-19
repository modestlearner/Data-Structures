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
char stack_top(stack *s){
  if(stack_empty(s)){
    return false;
  }
  else{
    return (s->a[s->size-1]);
  }
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
    return true;
  }
}

int check(stack *s,char str[],int n){
  int top=0,i,j=0,k=0,status=0;
  for(i=0;i<n;i++){
    if(str[i]!='c'){
      j=1;
    }
    if(str[i]=='c'){
      status++;
      k=2;
    }
    if(j==0 && k==2){
      top=100;
      break;
    }
    if(j==1 && k==0){
      stack_push(s,str[i],n);
      top++;
    }
    if(k==2 && j==1 && status==1){
      if(str[i]=='c'){
        continue;
      }
      else if(str[i]==stack_top(s)){
        stack_pop(s);
        top--;
      }
      else{
        top=100;
        break;
      }
    }
  }
    if(top==0){
      return 1;
    }
}
int len(char str[]){
  int i=0;
  while(str[i]!='\0'){
    i++;
  }
  return i-1;
}

int main(){
  stack s1;
  char str[MAX];
  int n;
  fgets(str,MAX,stdin);
  n=len(str);
  stack_init(&s1);
  if(check(&s1,str,n)==1){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
}
