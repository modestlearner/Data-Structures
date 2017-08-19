// WAP to study STL of queue
#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<char> q1;
  int i=0;
  char element='a';
  if(q1.empty()){
    cout<<"Empty"<<endl;
  }
  else{
    cout<<"Not empty"<<endl;
  }
  for(i=0;i<2;i++){
    q1.push(element);
    cout<<"Element pushed is "<<element<<endl;
    element++;
  }
  cout<<"Size of queue is "<<q1.size()<<endl;
  while(!q1.empty()){
    cout<<"Front element is "<<q1.front()<<endl;
    cout<<"Back element is "<<q1.back()<<endl;
    q1.pop();
    cout<<"Element popped "<<endl;
  }
  if(q1.empty()){
    cout<<"Queue empty "<<endl;
  }
  else{
    cout<<"Queue not empty "<<endl;
  }
  return 0;
}
