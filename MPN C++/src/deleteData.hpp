#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

#ifndef __DELETEDATA_HPP
#define __DELETEDATA_HPP

using namespace std;

void deleteData(MPN* dataMPN, int &size);
void shiftDataToLeft(MPN* dataMPN, int &size, const int index);

#endif