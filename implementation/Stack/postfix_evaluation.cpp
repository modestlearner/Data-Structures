#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

bool isOperator(char currentChar){
  if(currentChar=='+'||currentChar=='-'||currentChar=='*'||currentChar=='/'
  ||currentChar=='^'){
    return true;
  }
  else{
    return false;
  }
}

void getValues(char postfix[],float value[]){
  int i=0;
  char currentChar;
  while(postfix[i]!='\0'){
    currentChar=postfix[i];
    if(!isOperator(currentChar)){
      cout<<"Enter the value of "<<currentChar;
      cin>>value[currentChar];
    }
    i++;
  }
}

float calculateValues(float operand1,float operand2,char Operator){
  if(Operator=='+'){
    return operand1+operand2;
  }
  if(Operator=='-'){
    return operand1-operand2;
  }
  if(Operator=='*'){
    return operand1*operand2;
  }
  if(Operator=='/'){
    return operand1/operand2;
  }
  if(Operator=='^'){
    return pow(operand1,operand2);
  }
}

float evaluatePostfix(char postfix[]){
  stack<float> Stack;
  char currentChar;
  int i=0;
  float result,operand1,operand2,value[256];
  getValues(postfix,value);
  while(postfix[i]!='\0'){
    currentChar=postfix[i];
    if(isOperator(currentChar)){
      operand2=Stack.top();
      Stack.pop();
      operand1=Stack.top();
      Stack.pop();
      result=calculateValues(operand2,operand1,currentChar);
      Stack.push(result);
    }
    else{
      Stack.push(value[currentChar]);
    }
    i++;
  }
  return Stack.top();
}
int main(){
  char postfix[50];
  cout<<"Enter a valid postfix "<<endl;
  cin>>postfix;
  cout<<evaluatePostfix(postfix)<<endl;
}
