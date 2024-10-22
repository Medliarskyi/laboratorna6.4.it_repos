#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;

void inputArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Введіть елемент масиву [" << i + 1 << "]: ";
        cin >> arr[i];
    }
}

void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(8) << arr[i];
    }
    cout << endl;
}

int findMinIndex(double arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

double sumBetweenNegatives(double arr[], int n) {
    int firstNeg = -1, secondNeg = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (firstNeg == -1) {
                firstNeg = i;
            }
            else {
                secondNeg = i;
                break;
            }
        }
    }

    if (firstNeg == -1 || secondNeg == -1) {
        return 0; 
    }

    double sum = 0;
    for (int i = firstNeg + 1; i < secondNeg; i++) {
        sum += arr[i];
    }
    return sum;
}

void transformArray(double arr[], int n) {
    double* temp = new double[n]; 
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (fabs(arr[i]) <= 1) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (fabs(arr[i]) > 1) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    delete[] temp; 
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    double* arr = new double[n]; 
    inputArray(arr, n);

    cout << "Initial array: ";
    printArray(arr, n);

    int minIndex = findMinIndex(arr, n);
    cout << "Minimum element number: " << minIndex + 1 << endl;

    double sumNeg = sumBetweenNegatives(arr, n);
    cout << "The sum between the first and second negative elements: " << sumNeg << endl;

    transformArray(arr, n);

    cout << "Modified array: ";
    printArray(arr, n);

    delete[] arr;

    return 0;
}