#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "readFile.hpp"

#ifndef __OPENFILE_HPP
#define __OPENFILE_HPP

using namespace std;

void writeFile(MPN* dataMPN, const int size, ofstream &outFile);
bool openFile(ofstream &outFile);

#endif
