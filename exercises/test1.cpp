#include <iostream>
using namespace std;

class student {
public:
    student() {id = 0;}
    int id;
};

void swapInt(int& i, int& a) {
    int temp = a;
    a = i;
    i = temp;
}

void swapIntPoi(int*& i, int*& j) {
    int* temp = i;
    i = j;
    j = temp;
}

void swapIds(student& s, student& r) {
    int temp = s.id;
    s.id = r.id;
    r.id = temp;
}

void swapStudents(student& s, student& r) {
    student temp = s;
    s = r;
    r = temp;
}

void swapStudentPoi(student*& s, student*& r) {
    student* temp = s;
    s = r;
    r = temp;
}

int main() {
    int a,b, *c = &a, *d = &b;
    student S, R, *X = &S, *Y = &R;
    a = 10;
    b = 20;

    S.id = 2003;
    R.id = 1999;

    // swapInt()
    // cout << a << endl << b << endl;
    // swapInt(a,b);
    // cout << a << endl << b << endl;

    // swapIntPoi()
    // cout << c << endl << d << endl;
    // swapIntPoi(c,d);
    // cout << c << endl << d << endl;

    // swapIDs()
    // cout << S.id << endl << R.id << endl;
    // swapIds(S,R);
    // cout << S.id << endl << R.id << endl;

    // swapStudents()
    // cout << S.id << endl << R.id << endl;
    // swapStudents(S,R);
    // cout << S.id << endl << R.id << endl;

    // swapStudentPoi()
    // cout << (*X).id << endl << (*Y).id << endl;
    // swapStudentPoi(X,Y);
    // cout << (*X).id << endl << (*Y).id << endl;
}