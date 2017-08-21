#include<iostream>
#include<vector>
using namespace std;

struct Node{
  int data;
  int leftIndex;
  int rightIndex;
};

class binaryTree{
private:
  vector<struct Node>bt;
public:
  void makeNode(int data);
  void insertLeft(int index,int data);
  void insertRight(int index, int data);
  void insert(int data);
  void traverse(int index,int order);
};

void binaryTree::makeNode(int data){
  struct Node b={data,-1,-1};
  bt.push_back(b);
}

void binaryTree::insertLeft(int index,int data){
  struct Node b={data,-1,-1};
  bt[index].leftIndex=bt.size();
  bt.push_back(b);
}

void binaryTree::insertRight(int index,int data){
  struct Node b={data,-1,-1};
  bt[index].rightIndex=bt.size();
  bt.push_back(b);
}

void binaryTree::insert(int data){

  //Code if tree is empty
  if(bt.size()==0){
    makeNode(data);
  }

  // Code if tree is not empty
  else{
    int index=0;
    while(index<bt.size()){

      //Code to insert to the left of the parent
      if(data<=bt[index].data){
        if(bt[index].leftIndex==-1){
          insertLeft(index,data);
          break;
        }
        else{
          index=bt[index].leftIndex;
        }
      }
      else{
        if(bt[index].rightIndex==-1){
          insertRight(index,data);
          break;
        }
        else{
          index=bt[index].rightIndex;
        }
      }
    }
  }
}

void binaryTree::traverse(int index,int order){
  if(order==1){
    cout<<bt[index].data<<" ";
  }
  if(bt[index].leftIndex!=-1){
    traverse(bt[index].leftIndex,order);
  }
  if(order==2){
    cout<<bt[index].data<<" ";
  }
  if(bt[index].rightIndex!=-1){
    traverse(bt[index].rightIndex,order);
  }
  if(order==3){
    cout<<bt[index].data<<" ";
  }
}
int main(){
  binaryTree b1;
  b1.insert(60);
  b1.insert(40);
  b1.insert(20);
  b1.insert(25);
  b1.insert(90);
  b1.insert(23);
  b1.insert(95);
  b1.insert(80);
  b1.insert(85);

  cout<<"Pre-Order ";b1.traverse(0,1);
  cout<<endl;
  cout<<"In-Order ";b1.traverse(0,2);
  cout<<endl;
  cout<<"Post-Order ";b1.traverse(0,3);
  cout<<endl;


}
