#include <iostream>
using namespace std;

void displayArray(const int A[], const int no) {
    for (int i = 0; i < no; i++)
        cout << A[i] << "\t";
    cout << endl;
}

void modifyArray(int *arr, int index) {
    arr[index] = arr[0] + 10;
}

int main() {
    int B[] = {1, 2, 3, 4, 5, 6, 7, 8};

    displayArray(B, 8); //! 1   2   3   4   5   6   7   8
    displayArray(B + 3, 4); //! 4   5   6   7
    modifyArray(B, 2);
    modifyArray(B + 5, 1);
    modifyArray(&(B[3]), 4);
    displayArray(B, 8); //! 1  2   11  4   5   6    16  14

    return 0;
}