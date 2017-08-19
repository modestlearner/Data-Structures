#include<iostream>
using namespace std;
#define MAX 3

struct queue{
  int size;
  char a[MAX];
};
typedef struct queue queue;

void queue_init(queue *q){
  q->size=0;
}

bool queue_empty(queue *q){
  return (q->size==0);
}

bool queue_full(queue *q){
  return (q->size==MAX);
}

bool queue_inspect_front(queue *q , char &element){
  if(queue_empty(q)){
    return false;
  }
  else{
    element=q->a[q->size-1];
    return true;
  }
}

bool queue_insert(queue *q,char element){
  if(queue_full(q)){
    return false;
  }
  else{
    for(int i=q->size;i>0;i--){
      q->a[i]=q->a[i-1];
    }
    q->a[0]=element;
    q->size++;
    return true;
  }
}

bool queue_remove(queue *q, char &element){
  if(queue_empty(q)){
    return false;
  }
  else{
    q->size--;
    element=q->a[q->size];
    return true;
  }
}
int main(){
  queue q1;
  char element;

  queue_init(&q1);

  if(queue_empty(&q1)==true){
    cout<<"Empty as expected"<<endl;
  }
  else{
    cout<<"ERROR";
  }
  element='f';
  if(queue_insert(&q1,element)==true){
    cout<<"Element "<<element<<" pushed"<<endl;
  }
  else{
    cout<<"FULL"<<endl;
  }
  element='r';
  if(queue_insert(&q1,element)==true){
    cout<<"Element "<<element<<" pushed"<<endl;
  }
  else{
    cout<<"FULL"<<endl;
  }
  if(queue_inspect_front(&q1,element)==true){
    cout<<"FRONT ELEMENT IS "<<element<<endl;
  }
  else{
    cout<<"EMPTY"<<endl;
  }
  for(int i=0;i<10;i++){
    if(queue_remove(&q1,element)==true){
      cout<<element<<"POPPED"<<endl;
    }
    else{
      cout<<"EMPTY"<<endl;
      break;
    }
  }
}
