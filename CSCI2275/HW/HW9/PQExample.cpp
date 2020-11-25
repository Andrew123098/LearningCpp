#include <iostream>
#include <queue>

using namespace std;
struct person{
    string name;
    int timeToDel;
    int timeToTreat;
    //overload the >, < operator
    bool operator>(person p2) const{
        return timeToDel > p2.timeToDel;
    }
    bool operator<(person p2) const{
        return timeToDel < p2.timeToDel;
    }
    //if timeToDel is equal, then check timeToTreat
    bool operator==(person p2) const{
        if(timeToDel == p2.timeToDel){
            return timeToTreat < p2.timeToTreat;
        }else{
            return timeToDel < p2.timeToDel;
        }
    }
    person(string n, int t, int t2){
        timeToDel = t;
        timeToTreat = t2;
        name = n;
    }
};
struct compare{
    bool operator()(person p, person p2) const{
        if(p.timeToDel!=p2.timeToDel){
            return p > p2;
        }else{
            return p.timeToTreat > p2.timeToTreat;
        }
    }
};
int main(){
    person p1("sally", 10, 120);
    person p2("mary", 10, 110);
    if(p1 < p2){
        cout<<"sally";
    }else{
        cout<<"mary";
    }
    cout<<"pq code here"<<endl;
    priority_queue<person, vector<person>, compare> pq; //greater<vector<person>::value_type>> pq;
    pq.push(p1);
    pq.push(p2);
    while(!pq.empty()){
        person p = pq.top();
        cout<<p.name<<" "<<p.timeToDel<<" "<<p.timeToTreat<<endl;
        pq.pop();
    }

    priority_queue<int, vector<int>, greater<vector<int>::value_type>> pqInt; //max heap, no comparitor function given
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

