#include <iostream>
using namespace std;

void splitArray(const int * arr, const int size, const int index1, const int index2, int* &returnArr1, int& size1, int* &returnArr2, int& size2) {

//* also true
//* (const int* arr, const int size, const int index1, const int index2, int** returnArr1, int* size1, int** returnArr2, int* size2) {

    size1 = index2-index1+1;
    returnArr1 = new int[size1];

    size2 = size - size1;
    returnArr2 = new int[size2];

    int pos1 = 0;
    int pos2 = 0;

    for(int i = 0; i < size; i++) {
        if( i >= index1 && i <= index2) {
            returnArr1[pos1] = arr[i];
            pos1++;
        }
        else {
            returnArr2[pos2] = arr[i];
            pos2++;
        }
    }
}

int main() {
    int arr[] = {45,2 ,6,88,12 ,10,3, 2,10,21 ,5};
    int* arr2, *arr3, size2, size3, size = 11;
    splitArray(arr, size, 3, 7, arr2, size2, arr3, size3);

    //* for the second option
    //* (arr, size, 3, 7, &arr2, &size2, &arr3, &size3)

    for(int i = 0; i < size2; i++) {
        cout << arr2[i] << "\t";
    }
    cout << endl;
    for(int i = 0; i < size3; i++) {
        cout << arr3[i] << "\t";
    }
    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    delete[] arr2;
    delete[] arr3;
}
