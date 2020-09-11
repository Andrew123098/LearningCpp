#include<iostream>

using namespace std;
class Elevator{
    private:
        int topFloor=10;
        int currentFloor=1;
        int bottomFloor=0;
    public:
        Elevator(){}
        int getCurrentFloor(){
            return currentFloor;
        }
        void setCurrentFloor(int cf){
            currentFloor = cf;
        }

};

int main(){
    Elevator ev;
    cout<<ev.getCurrentFloor()<<endl;
    
}