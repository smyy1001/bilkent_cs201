#include <iostream>
using namespace std;

int* selectNegatives(int* arr, int& size ) {
    int newSize = 0;
    for(int j = 0; j < size; j++) {
        if(arr[j] < 0) 
            newSize++;
    }
    if(newSize == 0) {
        size = 0;
        return NULL;
    }
    int* negatives = new int[newSize];
    int pos = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0) {
            negatives[pos++] = arr[i];
        }
    }
    size = newSize;
    return negatives;
}

int main() {
    int arr[] = {0,2,6,8,-54,-9,0-6};
    int size = 8;
    int* neg = selectNegatives(arr, size);
    for(int i = 0; i < size; i++) {
        cout << neg[i] << "  ";
    }
}