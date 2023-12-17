//Implement a class complrx which represents the Complex Number data type Implemet the following operation:
//1) Constructor (including a default constructor which create which create the comple number 0+0i)
//2) Overload operator+ to add two complex numbers
//3) overload operator* to multiply two complex numbers.
//4) Overloaded <<and>> to print and read Complex Numbers.

#include <iostream>
using namespace std;

class complex{
    double img;
    double real;

    public:
    complex(){
        img = 0;
        real = 0;

    }

    complex(double x,double y){

        img = x;
        real = y;
    }

    complex operator+( complex& other){
        complex sum;
        sum.real = real+ other.real;
        sum.img = real+ other.img;
        return sum;

    }
   complex operator*( complex& other) {
    complex mul;
    mul.real = (real * other.real) - (img * other.img);
    mul.img = (real * other.img) + (img * other.real);
    return mul;
}
    friend ostream& operator<<(ostream& out, complex& c){
        return out <<c.real<<" + "<<c.img <<"i";
    }

    friend istream& operator>>(istream& in,complex& c){
        cout<<"Enter the real part : ";
        in>>c.real;
        cout<<"Enter the imaginary part : ";
        in>>c.img;
        return in;
    }
};


int main(){
    complex clx1,clx2,result;
    cout<<"Enter a first complx Number : \n";
    cin>>clx1;
    cout<<"Enter the Second complex Number : \n";
    cin>>clx2;

    result = clx1+ clx2;
    cout<<"Sum : "<<result<<endl;

    result = clx1*clx2;
    cout<<"Product : "<<result<<endl;
    return 0;
}