#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

using namespace std;

#ifndef __QUERYDATA_HPP
#define __QUERYDATA_HPP

double queryChoice(int* option);
int tubesQuantity(const double volume);
void displayQuery(MPN* dataMPN, const int size);


#endif