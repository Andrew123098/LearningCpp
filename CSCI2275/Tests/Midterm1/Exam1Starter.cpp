#include<iostream>
#include<vector>


using namespace std;
class Elevator{
    private:
        int topFloor=10;
        int currentFloor=1;
        int bottomFloor=0;
    public:
        Elevator(){}
        Elevator(int topF, int currentF, int bottomF){     // Constructor takes 3 areguments for top, current, and bottom floor.
            topFloor=topF;
            currentFloor=currentF;
            bottomFloor=bottomF;
        }
        int getCurrentFloor(){
            return currentFloor;
        }
        void setCurrentFloor(int cf){
            currentFloor = cf;
        }
        void goUpOneFloor(){                                 // Go up one floor.
            if(currentFloor < topFloor){                     // If lees than the top floor...
                currentFloor++;                              // Increase floor value by 1.
                cout<<"Now at floor: "<<currentFloor<<endl;  // And print the new floor level.
            } else if(currentFloor == topFloor){             // If at the top floor...
                cout<<"Already at the top!"<<endl;           // Print that you are already there.
            }
        }
        void goDownOneFloor(){                               // Go down one floor.
            if(currentFloor > bottomFloor){                  // If greater than the bottom floor...
                currentFloor--;                              // Dencrease floor value by 1.
                cout<<"Now at floor: "<<currentFloor<<endl;  // And print the new floor level.
            } else if(currentFloor == topFloor){             // If at the bottom floor...
                cout<<"Already at the bottom!"<<endl;        // Print that you are already there.
            }
        }

        void printFloors(Elevator *el){
            cout<<"Top Floor = "<<el->topFloor<<endl;
            cout<<"Bottom Floor = "<<el->bottomFloor<<endl;
            cout<<"Current Floor = "<<el->currentFloor<<endl;
        }

};

int main(int argc, char *argv[]){
    Elevator ev;
    int numberOfElevators = stoi(argv[1]);

    ev.goDownOneFloor();
    vector<Elevator> elevators (numberOfElevators);
    
    

    int input;
    do {
        cout<<"Please input an elevator number:";
        cin>>input;
        cout<<endl;
        if(input > elevators.size()){
            cout<<"Error: We only have "<<elevators.size()<<" elevators."<<endl;
        } 
    } while(input > elevators.size());

    while(input != ev.getCurrentFloor()){
        if(input > ev.getCurrentFloor()){
            ev.goUpOneFloor();
        } else if(input < ev.getCurrentFloor()){
            ev.goDownOneFloor();
        }
    }

    cout<<"Please get off. You are at floor "<<ev.getCurrentFloor()<<endl;
}