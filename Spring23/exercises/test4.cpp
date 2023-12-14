#include <iostream>
#include <string>
using namespace std;

void fun(string& x, string y) {
    x.erase(0,2);
    x.insert(2, y.substr(1,2));
    x.append("***");
    cout << "x: " << x << endl;

    y += x[0];
    y[2] = 'e';
    cout << "y: " << y << endl; 
}

int main() {
    string s1 = "python", s2 = "java";
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    fun(s1, s2);
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;
    return 0;
}