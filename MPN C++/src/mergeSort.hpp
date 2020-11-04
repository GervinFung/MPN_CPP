#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

#ifndef __MERGESORT_HPP
#define __MERGESORT_HPP

using namespace std;

//implement mergeSort to sort the file if it is not in order
void merge(MPN *dataMPN, const int left, const int mid, const int right);
MPN* mergeSort (MPN *dataMPN, const int left, const int right);
MPN* sort(MPN *dataMPN, const int size);

#endif
