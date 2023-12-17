///Write  program in C++ to use map associative container.The keys will be the n,mes of states and the values will be the population of the states.
//When the Program runs, the user promted to type the name of a staet
//The Program then looks in mao , Using the state names and index and returns the population of the state

#include<iostream>
#include<string>
#include<map>
#include<iterator> 

using namespace std;

int main() {
    map<string, int> population;
    char input;

    
    population.insert(pair<string, int>("Maharashtra", 124));
    population.insert(pair<string, int>("Bihar", 194));
    population.insert(pair<string, int>("Odisha", 94));
    population.insert(pair<string, int>("Kerala", 104));
    population.insert(pair<string, int>("Goa", 50));
    population.insert(pair<string, int>("Telangana", 100));

    
    cout << "Total States and UTs of India with Population:\n";
    for (auto itr = population.begin(); itr != population.end(); ++itr) {
        cout << itr->first << " : " << itr->second << " million\n";
    }

    do {
        string state;
        cout << "Enter the Name of State You Want to know Population About: ";
        cin >> state;
        auto itr = population.find(state);

        if (itr != population.end()) {
            cout << "Population of " << state << " is " << itr->second << " million\n";
        } else {
            cout << "State Not Found\n";
        }

        cout << "Do you want to Continue? (y/n): ";
        cin >> input;
    } while (input == 'Y' || input == 'y');

    population.clear();
    return 0;
}
