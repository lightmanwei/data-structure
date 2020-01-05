#include <iostream>
#include <stdlib.h>
#include <time.h>

int SearchBin(int array[], int target, int length, int &n) {
    int low = 0, high = length - 1;
    int mid = 0;

    while (low <= high) {
        n++;
        mid = (low + high) / 2;
        if (array[mid] == target) return mid;
        else if (target > array[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int InsertSort(int array[], int length, int &n) {
    int i = 0, j = 0;
    for (i = 2; i <= length; i++) {
        if (array[i] < array[i - 1]) {
            array[0] = array[i];
            array[i] = array[i - 1];
            for (j = i - 2; array[j] > array[0]; j--)
                array[j + 1] = array[j];
            array[j + 1] = array[0];
        }
    }
}

void PrintArray(int array[], int length) {
    for (int i = 1; i <= length; i++)
        std::cout << array[i] << "\t";
    std::cout << "\n";
}

int main() {
    int array[] = {0, 1, 11, 3, 23, 5, 57, 7, 8, 9, 10};
    int n = 0;
    InsertSort(array, 10, n);
    PrintArray(array, 10);



//    srand((unsigned) time(NULL));
//    int target = 0;
//    for (int i = 0; i < 1000; i++) {
//        target = rand() % 12;
//        std::cout << "target is " << target << "\n";
//        std::cout << "location is "
//                  << SearchBin(array, target,
//                               10, n) << "\n";
//    }
//    std::cout << "n is " << n << "\n";
    return 0;
}
