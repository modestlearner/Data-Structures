#include<iostream>
#include<stack>
using namespace std;

class textEditor{
private:
  stack<char>leftStack; // left stack
  stack<char>rightStack;// right stack
public:
  void insertCharacter(char character);
  void insertWord(char word[]);
  bool deleteCharacter();
  bool backspaceCharacter();
  void moveCursor(int position);
  void moveLeft(int position);
  void moveRight(int position);
  void findAndReplace(char find,char replace);
  void examineTop();
};

void textEditor::examineTop(){
  if(leftStack.empty()){
    cout<<"Left stack Empty\t"<<endl;
  }
  else{
    cout<<"Left stack :"<<leftStack.top()<<","<<leftStack.size()<<endl;
  }
  if(rightStack.empty()){
    cout<<"Right stack Empty\t"<<endl;
  }
  else{
    cout<<"Right Stack :"<<rightStack.top()<<","<<rightStack.size()<<endl;
  }
}// end of function

void textEditor::insertWord(char word[]){
  int i=0;
  while(word[i]!='\0'){
    insertCharacter(word[i]);
    i++;
  }
}// end of function

void textEditor::insertCharacter(char character){
  leftStack.push(character);
}// end of function

bool textEditor::deleteCharacter(){
  if(rightStack.empty()){
    return false;
  }
  else{
    rightStack.pop();
    return true;
  }
}// end of function

bool textEditor::backspaceCharacter(){
  if(leftStack.empty()){
    return false;
  }
  else{
    leftStack.pop();
    return true;
  }
}//end of function

void textEditor::moveCursor(int position){
  int leftSize,rightSize,count;
  leftSize=leftStack.size();
  rightSize=rightStack.size();
  if(position<leftSize){
    moveLeft(position);
  }
  else{
    count=position-leftSize;
    moveRight(count);
  }
}// end of function

void textEditor::moveLeft(int position){
  int leftSize;
  leftSize=leftStack.size();
  while(position!=leftSize){
    rightStack.push(leftStack.top());
    leftStack.pop();
    leftSize=leftStack.size();
  }
}// end of function

void textEditor::moveRight(int position){
  int rightSize,i=1;
  rightSize=rightStack.size();
  if(position>rightSize){
    cout<<"Cannot move the cursor to the specified position"<<endl;
  }
  else{
    while(i<=position){
      leftStack.push(rightStack.top());
      rightStack.pop();
      i++;
    }
  }
}// end of function

void textEditor::findAndReplace(char find , char replace){
  int count=1,originalCursor=leftStack.size();
  moveCursor(0);// moved all element to the left stack
  // Move character from right to left and examine
  while(!rightStack.empty()){
    if(rightStack.top()==find){
      deleteCharacter();
      insertCharacter(replace);
    }
    else{
      moveCursor(count);
    }
    count++;
  }
  moveCursor(originalCursor);
}// end of function
int main(){
  int i=0;
  char text[80];
  textEditor txt;
  // Inserting the word
  cout<<"Enter the word to be inserted "<<endl;
  cin.getline(text,80);
  txt.insertWord(text);
  cout<<"Inserting the word "<<endl;
  txt.examineTop();
  // Inserting the word
  cout<<"Enter the word to be inserted "<<endl;
  cin.getline(text,80);
  txt.insertWord(text);
  cout<<"Inserting the word "<<endl;
  txt.examineTop();

  //Move the cursor
  cout<<"Move the cursor to position 14"<<endl;
  txt.moveCursor(14);
  txt.examineTop();

  cout<<"Move the cursor to position 17"<<endl;
  txt.moveCursor(17);
  txt.examineTop();

  // Delete Character
  for(i=0;i<3;i++){
    if(!txt.deleteCharacter()){
      cout<<"Thers nothing to delete"<<endl;
    }
    else{
      cout<<"Delete using del"<<endl;
    }
    txt.examineTop();
  }
  txt.findAndReplace('t','T');
  cout<<"Replaced occurances of t with T"<<endl;
  txt.examineTop();
  return 0;
}
