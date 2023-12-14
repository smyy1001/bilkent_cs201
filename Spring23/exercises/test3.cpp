#include <iostream>
using namespace std;

void method1(int* a, int b) {
    for(int i = 0; i < b; i++ ) {
        a[i] = 10;
        cout << a[i] << endl;
    }
    b = 10;
}

int main() {
    const int size = 5;
    int A[size];
    method1(A, size);
    cout << size << endl;
    // string str;
    // cout << "enter your name: ";
    // cin >> str;
    // cout << str << endl;
    return 0;
}