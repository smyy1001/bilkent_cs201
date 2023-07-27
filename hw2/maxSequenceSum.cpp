// Author: Sumeyye ACAR
// ID: 22103640
// File: maxSequenceSum.cpp

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;

// Additional Methods
int maxOf3(int, int, int);
int* generate_array(int size = 1);

// Solutions
int sol1(const int*, int);
int sol2(const int*, int);
int sol3(const int*, int, int, int);
int sol4(const int*, int);

int main() {
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;

    for(int i = 10; i < 10001; i*=10) {
        int size = i;
        int* arr = generate_array(size);
        cout << "----------------------------------Size " << size << "----------------------------------" << endl;

        // Sol1 : Cubic
        startTime = std::chrono::system_clock::now();
        cout << "Result of Solution 1: " << sol1(arr, size) << endl;
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        // Sol2 : Quadratic
        startTime = std::chrono::system_clock::now();
        cout << "Result of Solution 2: " << sol2(arr, size) << endl;
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        // Sol3 : Recursive
        startTime = std::chrono::system_clock::now();
        cout << "Result of Solution 3: " << sol3(arr, size, 0, size-1) << endl;
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        // Sol4 : Linear
        startTime = std::chrono::system_clock::now();
        cout << "Result of Solution 4: " << sol4(arr, size) << endl;
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;   

        // delete
        delete[] arr;
    }
}

int* generate_array(int size) { // Array filled random integers in interval [-100, 100]
    int* arr = new int[size];
    srand(time(NULL));
    int random = 0;
    for(int i = 0; i < size; i++) {
        random = rand()%200;
        arr[i] = random-100;
    }
    return arr;
}

int sol1(const int* arr, int size) { // Cubic
    int maxSum = 0;

    for(int i = 0; i < size; i++) {

        for(int j = i; j < size; j++) {

            int tempSum = 0;

            for(int k = i; k <=j; k++) {
                tempSum += arr[k];
            }

            if(tempSum > maxSum) {
                maxSum = tempSum;
            }
        }
    }

    return maxSum;
}

int sol2(const int* arr, int size) { // Quadratic
    int maxSum = 0;

    for(int i = 0; i < size; i++) {

        int tempSum = 0;

        for(int j = i; j < size; j++) {

            tempSum += arr[j];

            if(tempSum > maxSum) {
                maxSum = tempSum;
            }
        }
    }
    return maxSum;
}

int sol3(const int* arr, int size, int left, int right) { // Divide and Conquer (Recursive)
    if(left == right) {
        if(arr[left] > 0) {
            return arr[left];
        }
        else { return 0; }
    }
    int center = (left + right) / 2;
    int leftSum = sol3(arr, size, left, center);
    int rightSum = sol3(arr, size, center +1, right);

    int maxLeftBorder = 0, leftBorder = 0;
    for(int i = center; i >= left; i--) {
        leftBorder += arr[i];
        if(leftBorder > maxLeftBorder) {
            maxLeftBorder = leftBorder;
        }
    }

    int maxRightBorder = 0, rightBorder = 0;
    for(int j = center +1; j <= right; j++) {
        rightBorder += arr[j];
        if(rightBorder > maxRightBorder) {
            maxRightBorder = rightBorder;
        }
    }

    return maxOf3(leftSum, rightSum, maxLeftBorder + maxRightBorder);
}

int maxOf3(int a, int b, int c) {
    return max(max(a,b),c);
}

int sol4(const int* arr, int size) { // linear-time
    int maxSum = 0, tempSum = 0;
    for(int i = 0; i < size; i++) {
        tempSum += arr[i];

        if(tempSum > maxSum) {
            maxSum = tempSum;
        }
        else if(tempSum < 0) {
            tempSum = 0;
        }
    }
    return maxSum;
}

// end
