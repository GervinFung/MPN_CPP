#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <iomanip>
#include "outFile.hpp"

using namespace std;
bool openFile(ofstream &outFile) {
    outFile.open("data.txt");
    return !outFile.fail();
}

void writeFile(MPN* dataMPN, const int size, ofstream &outFile) {
    bool canOpen = openFile(outFile);
    if (canOpen) {
        for (int i = 0; i < size; i++) {
            const string combinePositive = dataMPN[i].getCombinationPositive();
            const int mpn = dataMPN[i].getMPN();
            const int lower = dataMPN[i].getLowerConfidenceLimit();
            const int upper = dataMPN[i].getUpperConfidenceLimit();
            outFile << combinePositive << " " << mpn << " " << lower << " " << upper << " ";
            if (i != size - 1){
                outFile << endl;
            }
        }
        outFile.close();
    } else cerr << "Failed to open file" << endl;
}