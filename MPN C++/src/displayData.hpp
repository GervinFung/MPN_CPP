#include <iostream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

#ifndef __DISPLAYLIST_HPP
#define __DISPLAYLIST_HPP

using namespace std;

//output data
void printLine();
void output(MPN *dataMPN, const int size, const int index);
void outputHeader();

#endif