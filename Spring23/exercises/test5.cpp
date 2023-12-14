#include <iostream>
using namespace std;

void partition(int arr[], int arrSize, int pivot) {
    int *first = arr;
    int *second = arr + arrSize - 1;
    while (first <= second) {
        if (*first >= pivot && *second < pivot) {
            int temp = *first;
            *first = *second;
            *second = temp;
            first++;
            second--;
        }
        else {
            if (*first < pivot)
                first++;
            if (*second >= pivot)
                second--;
        }
    }
}