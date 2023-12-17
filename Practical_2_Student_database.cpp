#include <iostream>
#include <cstring>

using namespace std;

class student {
public:
    string name;
    int rollnumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string address;
    long long int number;
    long long int licenseNumber;
    static int count;

    student() {
        rollnumber = 0;
        cout << "Constructor" << endl;
        rollnumber = count;
        count++;
    }

    student(int rollnumber) : rollnumber(rollnumber) {}

    student(const student& obj) {
        rollnumber = obj.rollnumber;
        name = obj.name;
        dob = obj.dob;
        className = obj.className;
        bloodGroup = obj.bloodGroup;
        address = obj.address;
        division = obj.division;
        number = obj.number;
        licenseNumber = obj.licenseNumber;
        count++;
    }

    ~student() {
        cout << "Destructor" << endl;
        cout << "Destroying the Object" << endl;
        count--;
    }

    void getdata() {
        cout << "Enter the Name of the Student: ";
        cin.ignore(); 
        getline(cin, name);

        cout << "Enter the Roll Number: ";
        cin >> rollnumber;

        cout << "Enter the Birthdate (format: YYYY-MM-DD): ";
        cin >> dob;

        cout << "Enter the Blood Group: ";
        cin >> bloodGroup;

        cout << "Enter the Class of the Student: ";
        cin.ignore();
        getline(cin, className);

        cout << "Enter the Division of the Student: ";
        cin >> division;

        cout << "Enter the Contact number of the Student: ";
        cin >> number;

        cout << "Enter the Address of the Student: ";
        cin.ignore();
        getline(cin, address);

        cout << "Enter the License Number of the Student: ";
        cin >> licenseNumber;
    }

    friend void display(const student& obj);
};

int student::count = 1;

void display(const student& obj) {
    cout << "Name: " << obj.name << endl;
    cout << "Roll Number: " << obj.rollnumber << endl;
    cout << "Birthdate: " << obj.dob << endl;
    cout << "Blood Group: " << obj.bloodGroup << endl;
    cout << "Class: " << obj.className << endl;
    cout << "Division: " << obj.division << endl;
    cout << "Contact number: " << obj.number << endl;
    cout << "Address: " << obj.address << endl;
    cout << "License Number: " << obj.licenseNumber << endl;
}

int main() {
    student s1;
    student s2(s1);

    cout << "Enter all details of the student: " << endl;
    s1.getdata();
    cout << "Details of the student: " << endl;
    display(s1);

    int n;
    cout << "How many Students u want to create : ";
    cin >> n;

    student* s[50];

    for (int i = 0; i < n; i++) {
        s[i] = new student();
    }

    for (int i = 0; i < n; i++) {
        s[i]->getdata();
    }

    for (int i = 0; i < n; i++) {
        display(*s[i]);
    }

    for (int i = 0; i < n; i++) {
        delete s[i];
    }

    return 0;
}
