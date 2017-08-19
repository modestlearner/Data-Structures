#include<iostream>
#include<queue>
using namespace std;

struct personInfo{
  int personId;
  int arrivalTime;
};

class busStop{
private:
  static int id;
  queue<personInfo> busQueue;
public:
  void personArrives(int time);
  void boardBus(int busArrivalTime,int availableSeats);
};
int busStop::id=1000;// a random id to start with

void busStop::personArrives(int time){
  personInfo person;
  person.personId=++id;
  person.arrivalTime=time;
  busQueue.push(person);
  cout<<"Person "<<busQueue.back().personId<<" , "<<busQueue.back().arrivalTime<<endl;
}

void busStop::boardBus(int busArrivalTime,int availableSeats){
  int i, count=0, waitingTime, personArrivalTime=0;

  // code for borading the bus
  for(i=1;i<=availableSeats;i++){
    if(!busQueue.empty()){
      personArrivalTime=busQueue.front().arrivalTime;
      if(personArrivalTime>busArrivalTime){
        waitingTime=0;
      }
      else{
        waitingTime=busArrivalTime - personArrivalTime;
        cout<<"\tWaiting time of "<<busQueue.front().personId;
        cout<<":"<<waitingTime<<endl;
        count++;
        busQueue.pop();
      }
    }
  }
  cout<<"\t"<<count<<"People boarded the bus "<<endl;
  if(!busQueue.empty()){
    cout<<"Next person waiting is "<<busQueue.front().personId<<endl;
  }
  else{
    cout<<"Nobody waiting "<<endl;
  }
}
int main(){
  busStop Bstop;
  int busArrivalTime;

  Bstop.personArrives(1415);
  Bstop.personArrives(1419);
  Bstop.personArrives(1421);
  Bstop.personArrives(1425);

  busArrivalTime=1430;
  cout<<"Bus arrived at "<<busArrivalTime<<endl;
  Bstop.boardBus(busArrivalTime,2);

  busArrivalTime=1440;
  cout<<"Bus arrived at "<<busArrivalTime<<endl;
  Bstop.boardBus(busArrivalTime,5);

  return 0;
}
