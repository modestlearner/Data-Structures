#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  vector<int> intVec(5); // As vector is a template class so we need to give the data type
  vector<float> floatVec(20); // size is 20
  vector<char> charVec(5,'a');// size is 5 and each element is initialized with a

  cout<<intVec.size()<<" "<<floatVec.size()<<" "<<charVec.size()<<endl; // prints the size of the vector
  for(int i=0;i<5;i++){
    cout<<charVec[i]<<endl; //will print all a's as we initialized it with a
  }
  for(int i=0;i<5;i++){
    intVec.at(i)=i;
  }
  cout<<"Front element is "<<intVec.front()<<endl;
  cout<<"Back element is "<<intVec.back()<<endl;

  // Using push_back member function to add element to a vector of size 0
  vector<int>vec;
  for(int j=0;j<5;j++){
    cin>>n;
    vec.push_back(n);
  }
  for(int i=0;i<5;i++){
    cout<<vec.at(i);
  }
  cout<<endl;
  cout<<vec.size()<<endl;

  // Using pop_back member function to delete the last element from the vector
  for(int i=0;i<3;i++){
    vec.pop_back();
  }

  for(int i=0;i<vec.size();i++){
    cout<<vec.at(i);
  }
  cout<<endl;

  //Using iterator functions begin and end in vector class
  for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
    cout<<*it<<" ";
  }
   cout<<endl;
  for(int j=0;j<5;j++){
    cin>>n;
    vec.push_back(n);
  }
  cout<<endl;
  for(int i=0;i<vec.size();i++){
    cout<<vec.at(i);
  }
  cout<<endl;

  // Inserting elements in the middle using iterator functions
  vector<int>::iterator it=vec.begin()+2;// assigns index where the value needs to be inserted
  vec.insert(it,100);// it is the index we just assigned and 100 is the value
  cout<<"Value inserted at the 2nd position"<<endl;
  for(int i=0;i<vec.size();i++){
    cout<<vec.at(i);
  }
  cout<<endl;

  // Deleting element from the middle using iterator function
  it=vec.begin()+3; // assigned index to iterator from where the element needs to be deleted
  vec.erase(it);
  cout<<"Element deleted "<<endl;
  for(int i=0;i<vec.size();i++){
    cout<<vec.at(i);
  }
  cout<<endl;

  // Resizing a vector
  vector<int> vec2(10);
  cout<<"Size before resizing "<<vec2.size()<<endl;
  vec2.resize(20);
  cout<<"Size after resizing "<<vec2.size()<<endl;

  

}
