#include <iostream>

using namespace std;
///fucntions
int foo(int a, int b){
    return a+b;
}
int main(){
    cout<<"Hello World"<<endl;
    //types
    int a=5;
    bool b=true;
    bool c=false;
    float f=3.4;
    double f2=4.5;
    string s="test"

    //conditionals
    if(a<5){
        //do something
    } else if( a>=5 && a <10) {
        //do something
    } else {
        //do something (cannot be empty)
        cout<<"else"<<endl;
    }

    // loops
    int x=0;
    while(x<10){
        x++;
        cout<<x<<endl;
    }

    for(int x2=0 ; x2< 10 ; x2++){
        cout<<x2<<endl;
    }
    //arrays
    int t[10];
    for int(x=0;x<10;x++){
        t[x]=x*2;
        cout<<t[x]<<endl;
    }

    //struct
    struct person{
        int h;
        int w;
        string name;
    };

    person p;
    p.w=120;
    p.h;=65;
    p.name="bob";
    cout<<p.w<<" "<<p.h<<" "<<p.name<<endl;

    person p2[10];
    p2[1].h=120;

    //vectors
    


}

//How to run from the terminal 
// g++ FridayIntro.cpp -o FridayIntro  // This is to build
// ./FridayIntro                       //this is to run

