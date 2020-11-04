#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "displayData.hpp"

using namespace std;

void printLine() {
    cout << "+---+----------------------+-----------------+-------------------------------+------------------------------+" << endl;
}

void outputHeader() {
    printLine();
    cout << "| No" << "| Combination Positive" << " | MPN Index/100ml" << " | (Lower) 95% Confidence Limits" << " | (Upper) 95% Confidence Limits|" << endl;
    printLine();
}

void output(MPN* dataMPN, const int size, const int index) {
    outputHeader();
    for (int i = index; i < size; i++) {
        cout << "|" << setfill('0') << setw(3) << i + 1;
        cout << "|" << setfill(' ') << setw(13) << dataMPN[i].getCombinationPositive() << setfill(' ') << setw(10);
        cout << "|" << setfill(' ') << setw(9) << dataMPN[i].getMPN() << setfill(' ') << setw(9);
        cout << "|" << setfill(' ') << setw(16) << dataMPN[i].getLowerConfidenceLimit() << setfill(' ') << setw(16);
        cout << "|" << setfill(' ') << setw(17) << dataMPN[i].getUpperConfidenceLimit() << setfill(' ') << setw(14)  << "|" <<  endl;
        printLine();
    }
}