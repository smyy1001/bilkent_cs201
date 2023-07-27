#include <iostream>
using namespace std;

void func1(int a, int &b) {
    static int c = 2;
    a = 3;
    b = 4;
    c *= a;
    cout << "func1: a = " << a << " b = " << b << " c = " << c << endl;
}

void func2(int *a, int b) {
    int c = 2;
    *a = 5;
    b = 6;
    c *= *a;
    cout << "func2: a = " << *a << " b = " << b << " c = " << c << endl;
}

int main() {
    int x = 15, y = 25;

    cout << "Initially: x = " << x << " y = " << y << endl; //! Initially: x = 15 y = 25

    cout << "After calling the functions for the first time" << endl; //! After calling the functions for the first time

    func1(x, y); //! func1: a = 3 b = 4 c = 6
    cout << "After func1: x = " << x << " y = " << y << endl; //! After func1: x = 15 y = 4

    func2(&x, y); //! func2: a = 5 b = 6 c = 10
    cout << "After func2: x = " << x << " y = " << y << endl; //! After func2: x = 5 y = 4

    cout << "After calling the functions for the second time" << endl; //! After calling the functions for the second time

    func1(x, y); //! func1: a = 3 b = 4 c = 18
    cout << "After func1: x = " << x << " y = " << y << endl; //! After func1: x = 5 y = 4

    func2(&x, y); //! func2: a = 5 b = 6 c = 10
    cout << "After func2: x = " << x << " y = " << y << endl; //! After func2: x = 5 y = 4

    return 0;
}