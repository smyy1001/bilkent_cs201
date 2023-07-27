#include <iostream>
using namespace std;

void findMinMax(const int* arr, const int size, int& min, int& max ) {
    min = arr[0];
    max = min;
    for(int i = 0; i < size; i++) {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min) 
            min = arr[i];
    }
}

int main() {
    int min;
    int max;
    int size = 6;
    int arr[] = {0, -1, 5, 91, -82, 100};
    findMinMax(arr, size, min, max);
    cout << "Max: " << max << " Min: " << min << endl;
}