// Use STL for Sorting and searching with user defined recoreds records such as Persopn records(Name,Birth date ,telephone number)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class student
{
public:
    string name;
    long int rollnumber;
    string dob;


    student(const string &n, long int rn, const string &d) : name(n), rollnumber(rn), dob(d) {}

    static vector<student> read()
    {
        int n;
        vector<student> stud;
        cout << "Enter Total Number of Students : " << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string name, dob;
            long int rollnumber;
            cout << "Enter Name, Roll Number, and Date of Birth for student " << i + 1 << ": ";
            cin >> name >> rollnumber >> dob;
            stud.push_back(student(name, rollnumber, dob));
        }
        return stud;
    }

    void displayStudent() const
    {
        cout << rollnumber << " | " << name << " | " << dob << endl;
    }

    // Overload the < operator for sorting
    bool operator<(const student &s) const
    {
        return rollnumber < s.rollnumber;
    }

    // Overload the << operator for displaying
    friend ostream &operator<<(ostream &os, const student &s)
    {
        os << s.rollnumber << " | " << s.name << " | " << s.dob << endl;
        return os;
    }
};

int main()
{
    vector<student> stud;
    int input;
    do
    {
        cout << "Menu" << endl;
        cout << "1) Create" << endl;
        cout << "2) Display" << endl;
        cout << "3) Insert" << endl;
        cout << "4) Search" << endl;
        cout << "5) Sort" << endl;
        cout << "6) Delete" << endl;
        cout << "7) Quit" << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            stud = student::read();
            break;
        case 2:
            for (const auto &s : stud)
            {
                s.displayStudent();
            }
            break;
        case 3:
            {
                string name, dob;
                long int rollnumber;
                cout << "Enter Name, Roll Number, and Date of Birth for new student: ";
                cin >> name >> rollnumber >> dob;
                stud.push_back(student(name, rollnumber, dob));
                cout << "Student inserted successfully." << endl;
            }
            break;
        case 4:
            {
                long int rollnumber;
                cout << "Enter Student Roll Number to Search : " << endl;
                cin >> rollnumber;
                auto itr = find_if(stud.begin(), stud.end(), [rollnumber](const student &s) {
                    return s.rollnumber == rollnumber;
                });

                if (itr != stud.end())
                {
                    cout << *itr;
                }
                else
                {
                    cout << "Not Found" << endl;
                }
            }
            break;
        case 5:
            sort(stud.begin(), stud.end());
            for (const auto &s : stud)
            {
                cout << s;
            }
            break;
        case 6:
            {
                long int rollnumber;
                cout << "Enter the Roll number to Delete : ";
                cin >> rollnumber;
                auto itr = find_if(stud.begin(), stud.end(), [rollnumber](const student &s) {
                    return s.rollnumber == rollnumber;
                });

                if (itr != stud.end())
                {
                    stud.erase(itr);
                    cout << "Student deleted successfully." << endl;
                }
                else
                {
                    cout << "Student not Found " << endl;
                }
            }
            break;
        case 7:
            cout << "Thanks for Using it !! " << endl;
            break;
        default:
            cout << "Invalid Command " << endl;
            break;
        }
    } while (input != 7);

    return 0;
}
