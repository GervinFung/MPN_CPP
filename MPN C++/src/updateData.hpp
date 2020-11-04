#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

#ifndef __UPDATE_HPP
#define __UPDATE_HPP

using namespace std;

void updateList(MPN* dataMPN, const int size);
int askOption();
void updateData(MPN &dataMPN, const int option);
bool isInt(const string line, const int min, const int max);

#endif