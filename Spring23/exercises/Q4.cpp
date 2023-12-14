#include <iostream>
using namespace std;

int main() {
    int A, B;
    int *x = &A, *y = &B;
    x = &B;
    *x = 24;
    cout << "B   = " << B << endl; //! B   = 24
    cout << "*y  = " << *y << endl; //! *y   = 24

    y = &A;
    *y = 32;
    cout << "&*y = " << &*y << endl; //! xxxxxxxx
    cout << "*x  = " << *x << endl; //! 24
    cout << "A  = " << A << endl; //! A   = 32
    cout << "&A  = " << &A << endl; //! xxxxxxxx

    return 0;
}
