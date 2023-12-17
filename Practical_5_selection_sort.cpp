#include <iostream>
using namespace std;

#define size 10

template <class T>
void selection_sort(T A[size], int n) {
    int i, j, min;
    T temp;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    cout << "Sorted array : " << endl;
    for (i = 0; i < n; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}

int main() {
    int choice, n;
    int I[size];
    float F[size];

    do {
        cout << "Select the operation : \n1) Integers \n2) Float \n3) Exit " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Total size of the Integer Array : ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter the Elements : ";
                    cin >> I[i];
                }
                selection_sort(I, n);
                break;

            case 2:
                cout << "Enter the Total Size of the Float Array : ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter the Elements : ";
                    cin >> F[i];
                }
                selection_sort(F, n);
                break;

            case 3:
                cout << "Thanks for Using it!!" << endl;
                break;

            default:
                cout << "Invalid Command" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
