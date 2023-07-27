#include <iostream>
using namespace std;

int* rowSum(int* arr, const int row, const int colum) {
    int  *sum = new int[row];
    for(int i = 0; i < row; i ++) {
        sum[i] = 0;
        for(int j = 0; j < colum; j++) {
            sum[i] += arr[i*(colum)+j];
        }
    }
    return sum;
}

int main() {
    int arr[] = {5,3,6,9,4,7}; 
    int* arr2 = rowSum(arr, 3, 2);
    for(int i = 0; i < 3; i++) {
        cout << arr2[i] << "  ";
    }
    cout << endl;
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << "  ";
    }
}