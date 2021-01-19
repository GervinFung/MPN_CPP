#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "mergeSort.hpp"

using namespace std;

void merge(MPN *dataMPN, const int left, const int mid, const int right) {
    MPN *leftMPN = new MPN[mid - left + 2];
    MPN *rightMPN = new MPN[right - mid + 1];

    for (int i = left; i <= mid; i++) {
        leftMPN[i - left] = dataMPN[i];
    }
    for (int i = mid + 1; i <= right; i++) {
        rightMPN[i - mid - 1] = dataMPN[i];
    }

    //For compariing to neighbor element
    //since 5-5-5 is the max value, 6-6-6 will be the benchmark for comparison
    leftMPN[mid - left + 1] = MPN("6-6-6", 0, 0, 0);
    rightMPN[right - mid] = MPN("6-6-6", 0, 0, 0);

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        const int compare = leftMPN[i].getCombinationPositive().compare(rightMPN[j].getCombinationPositive());
        if (compare == -1) {
            dataMPN[k] = leftMPN[i];
            i++;
        } else {
            dataMPN[k] = rightMPN[j];
            j++;
        }
    }
    delete[] leftMPN;
    delete[] rightMPN;
}

MPN* mergeSort (MPN *dataMPN, const int left, const int right) {
    if (left < right) {
        const int mid = (left + right) / 2;
        mergeSort(dataMPN, left, mid);
        mergeSort(dataMPN, mid + 1, right);
        merge(dataMPN, left, mid, right);
    }
    return dataMPN;
}

MPN* sort(MPN *dataMPN, const int size) {
    return mergeSort(dataMPN, 0, size - 1);
}