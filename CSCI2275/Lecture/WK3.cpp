#include <iostream>
#include <sstream>

using namespace std;

//constructor overloading
//overloading - fucntion call with samee name but differrnt arguments
// operator overloading
//+, =, -, *
//what does it mean to add a user defined type?

class PointClass{
    private:
        int x;
        int y;
    public:
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    PointClass(int xin, int yin){
        x=xin;
        y=yin;
    }
    PointClass(){}
    // returning a PointClass, operator is the '+' operator, implicit is the left-side operand
    //right-side operand is &pc (reference to pc).
    PointClass operator+(const PointClass &pc){ //defineing the + operator
        PointClass pc1;
        pc1.x=this->x+pc.x;
        pc1.y=this->y+pc.y;
        return pc1;
    }

    friend PointClass operator-(const PointClass &pc, const PointClass &pc2);
};
//how do we overload the + operator (2 options)
//member function
//friend function of the class -- need both operands
PointClass operator-(const PointClass &pc, const PointClass &pc2){ //defineing the - operator
        PointClass pc1;
        pc1.x=pc.x-pc2.x;
        pc1.y=pc.y-pc2.y;
        return pc1;
    }

//non-member function (not gonna talk about this this class)


int main(){

    PointClass pc(4, 5);
    PointClass pc1(6, 7);
    PointClass pc2 = pc+pc1; //error because I havent defined what '+' means on PointClass
    cout<<pc2.getX()<<" "<<pc2.getY()<<endl;
    

    stringstream ss("this is a string");
    string line;
    while(getline(ss,line, ' ')){
    cout<<line<<endl;
    }
    
    ss<<line;
    getline(ss, line);
    cout<<line<<endl;

}

