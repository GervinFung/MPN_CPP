#include <iostream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

#ifndef __INSERT_HPP
#define __INSERT_HPP

using namespace std;

//read data
void insertNewData(MPN* dataMPN, int &size);
int getIndexMPN();
bool isInteger(const string line);
int getLowerBound();
int getUpperBound();
void shiftDataToRight(MPN* dataMPN, const int size, const int index);

#endif