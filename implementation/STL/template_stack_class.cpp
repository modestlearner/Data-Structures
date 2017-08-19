// In this program we will see the stack library and the built in functions in the stack library
#include<iostream>
#include<stack>
using namespace std;

int main(){
  stack<char> s1; // We declare a character stack s1
  stack<char> s2;
  char element='a';
  if(s1.empty()==true){
    cout<<"Stack is empty"<<endl;
  }
  else{
    cout<<"Error"<<endl;
  }
  for(int i=0;i<2;i++){
    s1.push(element);
    cout<<"Element pushed is "<<element;
    element++;
  }
  cout<<endl<<"Size of stack is "<<s1.size()<<endl;
  while(s1.empty()!=true){
    cout<<"Top element is "<<s1.top()<<endl;
    s1.pop();
    cout<<"Element popped"<<endl;
  }
  if(s1.empty()==true){
    cout<<"Stack is empty"<<endl;
  }
  else{
    cout<<"Error"<<endl;
  }
  element='q';
  s1.push(element);
  element='r';
  s2.push(element);
  element='t';
  s2.push(element);
  swap(s1,s2);
  for(int i=0;i<2;i++){
    cout<<s1.top();
    s1.pop();
  }

}
