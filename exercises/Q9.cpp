#include <iostream>
using namespace std;

class Time {

public:
    Time() {
        hour = minute = second = 5;
    }
    ~Time() {
        hour  = minute = second = 0;
    }
    int getHOur() {
        return hour;
    }

private:
    int hour, minute, second;
};



int main() {
    Time** tim = new Time*[4];
    for(int i = 0; i < 4; i++) {
        tim[i] = new Time[6];
    }
    cout << tim[2] << endl;
    cout << tim[2][1].getHOur() << endl;
    for(int i = 0; i < 4; i++) {
        delete[] tim[i];
    }
    cout << tim[2] << endl;
    cout << tim[2][1].getHOur() << endl;

    delete[] tim;

    cout << tim[2] << endl;
    cout << tim[2][1].getHOur() << endl;
}