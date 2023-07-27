#include <iostream>
using namespace std;

class test{
public:
    test( int i = 0 ){
        id = i;
        cout << "Constructor " << id << endl;
    }
    ~test() {
        cout << "Destructor: " << id << endl;
    }
    test( const test& o ) {
        id = o.id;
        cout << "Copy constructor " << id << endl;
    }
    test& operator=(const test& right) {
        id = right.id;
        cout << "Assignment " << id << endl;
        return *this;
    }
    int id;
};

test t1(10);
test t2(20);

void foo(bool flag) {
    test t3(30);
    static test t4(40);
    if(flag) {
        test t5(50);
        test t6(60);
    }
    test t7(70);
}


int main() {
    // cout << "1-------" << endl;
    // test t8(80);
    // test& testt = t8; //prints nothing
    // cout << "2-------" << endl;
    // foo(false);
    // cout << "3-------" << endl;
    // foo(true);
    // cout << "4-------" << endl;

//----------------------------------------
    
    // cout << "1-------" << endl;
    // test *b1;
    // cout << "2-------" << endl;
    // b1 = new test(100);
    // delete b1;
    // cout << "3-------" << endl;
    // b1 = new test[2];
    // b1[0].id = 200;
    // b1[1].id = 300;
    // delete[] b1;
    // cout << "4-------" << endl;
    // b1 = new test[2];
    // b1[0].id = 400;
    // b1[1].id = 500;
    // delete b1;
    // cout << "5-------" << endl;

    return 0;
}



















