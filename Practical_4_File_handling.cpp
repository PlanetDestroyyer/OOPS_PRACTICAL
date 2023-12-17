//File Handling in C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Employee{
    string name;
    int id;
    double salary;
    public:
    void accept(){
        cout<<"Enter name of Employee : ";
        cin>>name;
        cout<<"Enter ID : ";
        cin>>id;
        cout<<"Enter Salary : ";
        cin>>salary;

    }

    void display(){
        cout<<"Name Of Employee is : "<<name<<endl;
        cout<<"ID of the Employee is : "<<id<<endl;
        cout<<"Salary of the Employee is : "<<salary<<endl;
    }
};
int main(){
    Employee em[5];
    fstream f;
    int i,n;
    f.open("new.txt",ios::out|ios::binary);
    cout<<"How many Employee information U want to Store : ";
    cin>>n;

    cout<<"\nEnter the Information of the Employee : "<<endl;
    for ( i = 0; i < n; i++)
    {
        em[i].accept();
        f.write((char*)& em[i],sizeof em[i]);
    }

    f.close();

    f.open("new.txt",ios::in | ios::binary);

    cout<<"Information are as Followrs :- "<<endl;
    for ( i = 0; i < n; i++)
    {
        em[i].display();

    }

    f.close();
    return 0;
    
    
}