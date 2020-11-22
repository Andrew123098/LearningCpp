#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct person{
    string name;
    int timeToDel;
    int timeToTreat;

    // overload the > and < operators for struct
    bool operator>(person p2) const{
        return timeToDel > p2.timeToDel;
    }
    bool operator<(person p2) const{
        return timeToDel < p2.timeToDel;
    }
    // if timeToDel is equal than check the timeToTreat
    // overlaod == operator for struct
    bool operator==(person p2) const{
        if(timeToDel == p2.timeToDel){
            return timeToTreat < p2.timeToTreat;
        } else {
            return timeToDel < p2.timeToDel;
        }
    }
    person(string n, int t, int t2){
        name = n;
        timeToDel = t;
        timeToTreat = t2;
    }
};
struct compare{
    bool operator()(person p, person p2){
        if(p.timeToDel != p2.timeToDel){
            return p > p2;
        } else {
            return p.timeToTreat > p2.timeToTreat;
        }
    }
};

int main(){
  
    person p1("sally", 10, 100);
    person p2("mary", 10, 120);
    if(p1 > p2){ // looks at the greater than operater that has been overloaded for this struct
        cout<<"mary"<<endl;
    } else {
        cout<<"sally"<<endl;
    }
    if(p1 == p2){ 
        cout<<"mary"<<endl;
    } else {
        cout<<"sally"<<endl;
    }

      //priority_queue<int, vector<int>> pqInt; // maxHeap, no comparitor function given
    priority_queue<int, vector<int>, greater<vector<int>::value_type>> pqInt; // minHeap, given camparitor function
    //priority_queue<person, vector<person>, greater<vector<person>::value_type>> pq; // minHeap given comparitor function
    priority_queue<person, vector<person>, compare> pq; // minheap defining compare function in struct
    pq.push(p1);
    pq.push(p2);
    while(!pq.empty()){
        person p = pq.top();
        cout<<p.name<<" "<<p.timeToDel<<" "<<p.timeToTreat<<endl;
        pq.pop();
    }


    pqInt.push(10);
    pqInt.push(100);
    pqInt.push(1);
    pqInt.push(120);
    pqInt.push(2);
    pqInt.push(4);
    pqInt.push(500);

    while(!pqInt.empty()){
        int p = pqInt.top();
        cout<<p<<endl;
        pqInt.pop();
    }
}