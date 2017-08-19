#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool checkParenthesis(char infix[]){
  int open=0,close=0,i=0;
  // cout<<"h";
  while(infix[i]!='\0'){
    if(infix[i]=='('){
      open++;
    }
    if(infix[i]==')'){
      close++;
      if(close>open){
        return false;
        // break;
      }
    }
    i++;
  }
  if(open==close){
    return true;
  }
  else{
    return false;
  }
}

bool isValid(char currentChar){
  return ((currentChar>=65 && currentChar<=90)||(currentChar>=95 && currentChar<=122)
          ||(currentChar>=40 && currentChar<=43)|| currentChar==45 || currentChar==47
          || currentChar==94);
}

bool validate(char infix[]){
  int i=0;
  while(infix[i]!='\0'){
    if(!isValid(infix[i])){
      return false;
    }
    else{
      i++;
    }
  }
  if(checkParenthesis(infix)==false){
    return false;
  }
  return true;
}

int priorityNumber(char Operator){
  if(Operator=='^'){
    return 0;}
  if(Operator=='*' || Operator=='/'){
    return 1;}
  if(Operator=='+' || Operator=='-'){
    return 2;}
  if(Operator==')'){
    return 3;}
}

bool checkPriority(char currentoper, char topoper){
  if(priorityNumber(currentoper)<priorityNumber(topoper)){
    return true;
  }
  else{
    return false;
  }
}

bool isOperand(char currentChar){
  return(currentChar>=65 && currentChar<=97) || (currentChar>=97 && currentChar<=122);
}

void infix2Postfix(char infix[],char answer[]){
  int i=0,j=0;
  char currentChar,postfix[50];
  stack<char>operatorStack;

  while(infix[i]!='\0'){
    currentChar=infix[i];
    if(isOperand(currentChar)){
      postfix[j]=currentChar;
      j++;
    }
    else{
      if(currentChar=='('){
        operatorStack.push(currentChar);
        i++;
        j++;
        continue;
      }
      if(operatorStack.empty() && currentChar!=')'){
        operatorStack.push(currentChar);
      }
      else{
        if(checkPriority(currentChar,operatorStack.top())){
          operatorStack.push(currentChar);
        }
        else{
          while(!operatorStack.empty()){
            if(operatorStack.top()=='('){
              operatorStack.pop();
              break;
            }
            postfix[j]=operatorStack.top();
            j++;
            operatorStack.pop();
          }// end of while
          if(currentChar!=')'){
            operatorStack.push(currentChar);
          }
        }
      }
    }
    i++;
  }// end of while
  while(!operatorStack.empty()){
    postfix[j]=operatorStack.top();
    operatorStack.pop();
    j++;
  }
  strcpy(answer,postfix);
}// end of function

int main(){
  char infix[50],postfix[50];
  cout<<"Enter the infix expression"<<endl;
  cin>>infix;
  if(validate(infix)==false){
    cout<<"Error invalid expression"<<endl;
  }
  else{
    cout<<"Infix expression is "<<infix<<endl;
    infix2Postfix(infix,postfix);
    cout<<"Postfix expression is ";
    for(int j=0;j<strlen(infix);j++){
      cout<<postfix[j];
    }
    cout<<endl;
  }
}
