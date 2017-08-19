#include<iostream>
using namespace std;

struct node{
  char info;
  struct node *next;
};
struct queue{
  struct node *front;
};typedef struct queue queue;
void queue_init(queue *q){
  q->front=NULL;
}
bool queue_empty(queue *q){
  return (q->front==NULL);
}
bool queue_front(queue *q,char &element){
  if(queue_empty(q)){
    return false;
  }
  else{
    element=q->front->info;
    return true;
  }
}
bool queue_insert(queue *q,char element){
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->info=element;
  if(q->front==NULL){
    temp->next=NULL;
    q->front=temp;

  }
  else{
    struct node *temp1;
    temp1=q->front;
    while(temp1->next!=NULL){
      temp1=temp1->next;
    }
    temp1->next=temp;
    temp->next=NULL;
  }
    return true;
}
bool queue_remove(queue *q,char &element){
  if(queue_empty(q)){
    return false;
  }
  else{
    struct node *temp;
    temp=q->front;
    q->front=temp->next;
    element=temp->info;
    free(temp);
    return true;
  }
}
int main(){
  queue q1;
  char element;
  queue_init(&q1);
  if(queue_empty(&q1)==true){
    cout<<"EMPTY AS EXPECTED"<<endl;
  }
  else{
    cout<<"ERROR";
  }
  element='f';
  if(queue_insert(&q1,element)==true){
    cout<<"ELEMENT "<<element<<" INSERTED"<<endl;
  }
  else{
    cout<<"FULL"<<endl;
  }
  element='r';
  if(queue_insert(&q1,element)==true){
    cout<<"ELEMENT "<<element<<" INSERTED"<<endl;
  }
  else{
    cout<<"FULL"<<endl;
  }
  element='s';
  if(queue_insert(&q1,element)==true){
    cout<<"ELEMENT "<<element<<" INSERTED"<<endl;
  }
  else{
    cout<<"FULL"<<endl;
  }
  if(queue_front(&q1,element)==true){
    cout<<"FRONT ELEMENT IS "<<element<<endl;
  }
  else{
    cout<<"EMPTY"<<endl;
  }
  for(int i=0;i<10;i++){
    if(queue_remove(&q1,element)==true){
      cout<<element<<" REMOVED"<<endl;
    }
    else{
      cout<<"EMPTY "<<endl;
      break;
    }
  }
}
