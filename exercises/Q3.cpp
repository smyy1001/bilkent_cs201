#include <iostream>
using namespace std;

int a = 5;

void f1(int a) {
    cout << a << endl;
}

void f2() {
    cout << a << endl;
}

int main() {
    int a = 10, b = 7;

    cout << a << endl; //! 10

    if (a > b) {
        int a = 40;
        cout << a << endl; //! 40
    }

    cout << a << endl; //! 10

    f1(b); //! 7
    f2(); //! 5

    cout << a << endl; //! 10

    return 0;
}