#include<iostream>
#include<cmath>
using namespace std;
struct v3{
  double x,y,z;

  double length(){
    return sqrt(x*x + y*y + z*z);
  }
  v3 sum(v3 const &a){
    v3 v;
    v.x= x + a.x;
    v.y= y + a.y;
    v.z= z + a.z;
    return v;
  }
  v3 scale(double factor){
    v3 v;
    v.x= x*factor;
    v.y= y*factor;
    v.z= z*factor;
    return v;
  }
  void print(){
    cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
  }
};
int main(){
  v3 vel,acc,pos; // velocity accelaration and position
  v3 currDisp,currPos; // current displacement and position
  double t=0.0,deltaT,totalT; // t= time elapsed so far
  cout<<"Give x y and z components of velocity:";
  cin>>vel.x>>vel.y>>vel.z;
  cout<<endl<<"Give x y and z components of accelaration:";
  cin>>acc.x>>acc.y>>acc.z;
  cout<<endl<<"Give x y and z components of position:";
  cin>>pos.x>>pos.y>>pos.z;
  cout<<endl<<"Give total simulation time:";
  cin>>totalT;
  cout<<endl<<"Give time of granuality:";
  cin>>deltaT;
  if(totalT<0 || deltaT<=0){
    cout<<"Invalid input "<<endl;
    return -1;
  }
  while(t<=totalT){
    // Calculate displacement using vel*t + 0.5(acc*(t*t))
    currDisp=(vel.scale(t)).sum(acc.scale(0.5*t*t));
    currPos=currDisp.sum(pos);
    cout<<"Time :"<<t<<" ";
    currPos.print();
    t=t+deltaT;
  }
  return 0;
}
