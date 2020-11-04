#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

#ifndef __SEARCH_HPP
#define __SEARCH_HPP

using namespace std;

string getCombinationPositive();
void containCombinationPositive(MPN* dataMPN, const int size);
bool isCombinationPositive(const string line);

#endif