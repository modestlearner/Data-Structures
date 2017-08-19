#include<iostream>
#include<string>
using namespace std;

int main(){
  string s1="Hello";
  string s2="World!";
  string s3=s2;
  cout<<s1<<" "<<s3<<endl;

  // Take string input from the user using cin
  // string s4="Please type in your name";
  // string s5;
  // cout<<s4;
  // cin>>s5;// It does not recognize space and assigns the name before the space
  // cout<<"Your name is "<<s5<<endl;

  // Taking string input from the user using getline function
  string s6="Please enter your name again";
  string s7;
  cout<<s6;
  getline(cin,s7); // It recognizes space and prints the correct input
  cout<<"Your name is "<<s7<<endl;

  // Concatenating string using the + operator
  string s8=s1+s2+"concatenated";
  cout<<s8<<endl;

  // Concatenating the string using member function append
  string s9;
  s9.append(s1);
  s9.append(s2,2,4);/* 2 signifies the starting position of the string (including 2) and
                       4 signifies the number of characters to append*/
  s9.append(" appended");
  cout<<s9<<endl;

  // Accessing Characters in the string using at member function
  cout<<s1.at(4)<<endl;

  //Finding a substring in a string using find member function
  int i=s8.find("Hello"); // returns the position of the word scans from left to right
  cout<<i<<endl;

  // Finding a substring in a string using rfind member function
  int j=s8.find("World");
  cout<<j<<endl;

  // Extracting the substring from string using substr
  cout<<s8.substr(2)<<endl;// starting from position 2 to end of the string
  cout<<s8.substr(0,4)<<endl; // starting from position 0 to 4 characters excluding the 4 index

  // Using iterators in the program
  string s="Hey There!!!!";
  for(string::iterator it=s.begin();it!=s.end();it++){
    cout<<*it;
  }
}
