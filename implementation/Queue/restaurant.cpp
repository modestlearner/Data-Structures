#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct customerInfo{
  int custId;
  int arrivalTime;
};

struct foodInfo{
  int foodId;
  string foodName;
  float rate;
};

struct orders{
  int tokenId;
  float cost;
};

struct kitchen{
  struct orders order;
  int preparationTime;
};

class restaurant{
private:
  static int custId,tokenId,foodIndex,ordersInKitchen;
  struct foodInfo food[100];
  struct orders order;
  struct kitchen k[100];
  queue<customerInfo>customerQueue;
  queue<int>orderDispatch;
public:
  void loadMenu();
  void setFoodItems(int id,string name,float cost);
  void customerArrives(int time);
  void placeOrder(float cost);
  void orderGoesToKitchen(int prepTime);
  void dispatchOrders();
};

int restaurant::custId=0;
int restaurant::ordersInKitchen=0;
int restaurant::foodIndex=0;
int restaurant::tokenId=1000;

void restaurant::setFoodItems(int id,string name,float cost){
  food[foodIndex].foodId=id;
  food[foodIndex].foodName=name;
  food[foodIndex].rate=cost;
  foodIndex++;
}

void restaurant::loadMenu(){
  setFoodItems(1,"Vada Pav",10.0);
  setFoodItems(2,"Uttpam",15.0);
  setFoodItems(3,"Samosa",18.0);
  setFoodItems(4,"Bhel Puri",25.0);
  setFoodItems(5,"Pakoda",20.0);
  setFoodItems(6,"Dosa",40.0);
  setFoodItems(7,"Thali",55.0);
}

void restaurant::customerArrives(int time){
  customerInfo cust;
  cust.custId=++custId;
  cust.arrivalTime=time;
  customerQueue.push(cust);
  cout<<"Customer: "<<customerQueue.back().custId<<", ";
  cout<<customerQueue.back().arrivalTime<<endl;
}

void restaurant::placeOrder(float cost){
  order.tokenId=++tokenId;
  order.cost=cost;
  cout<<"Order placed for the customer "<<customerQueue.front().custId<<" with ";
  cout<<"token "<<order.tokenId<<endl;
  customerQueue.pop();
}

void restaurant::orderGoesToKitchen(int prepTime){
  k[ordersInKitchen].order=order;
  k[ordersInKitchen].preparationTime=prepTime;
  ordersInKitchen++;
}

void restaurant::dispatchOrders(){
  struct kitchen temp;
  int i,j;
  // Sort on Preparation Time
  for(i=0;i<ordersInKitchen;i++) {
    for (j=i+1; j<ordersInKitchen; j++) {
      if (k[i].preparationTime > k[j].preparationTime) {
        temp = k[i]; k[i] = k[j]; k[j] = temp;
      }
    }
  }
  for(i=0;i<ordersInKitchen;i++) {
    orderDispatch.push(k[i].order.tokenId);
    cout << "Dispatched Token ID: " << orderDispatch.back() << endl;
  }
}

int main(){
  struct orders order;
  restaurant MVPRestaurant;
  int i;

  MVPRestaurant.loadMenu();

  MVPRestaurant.customerArrives(1415);
  MVPRestaurant.customerArrives(1417);
  MVPRestaurant.customerArrives(1421);
  MVPRestaurant.customerArrives(1423);

  MVPRestaurant.placeOrder(165.0);
  MVPRestaurant.orderGoesToKitchen(5);

  MVPRestaurant.placeOrder(100.0);
  MVPRestaurant.orderGoesToKitchen(10);

  MVPRestaurant.placeOrder(19.0);
  MVPRestaurant.orderGoesToKitchen(6);

  MVPRestaurant.placeOrder(40.0);
  MVPRestaurant.orderGoesToKitchen(14);

  MVPRestaurant.dispatchOrders();
  return 0;
}
