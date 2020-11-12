#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "readFile.hpp"
#include "searchData.hpp"

using namespace std;

string getCombinationPositive() {
    string line;
    do {
        cout << "Please enter combination-of-positives triplet: ";
        getline(cin, line);
    } while (!isCombinationPositive(line));
    return line;
}

void containCombinationPositive(MPN* dataMPN, const int size) {
    const string line = getCombinationPositive();
    for (int i = 0; i < size; i++) {
        if (line == dataMPN[i].getCombinationPositive()) {
            cout << "Searching for data..." << endl;
            cout << "Data successfully searched..." << endl;
            cout << "For " << dataMPN[i].getCombinationPositive() << ", MPN is "<< dataMPN[i].getMPN();
            cout << " and 95% of samples contain between " << dataMPN[i].getLowerConfidenceLimit() << " and " << dataMPN[i].getUpperConfidenceLimit() << " bacterial/ml." << endl;
            return;
        }
    }
    cout << "The combination-of-positives triplet you entered does not exist" << endl;
}

// this function determines if the input is in combination-of-positives triplet
bool isCombinationPositive(const string line) {
    if (line.length() == 5) {
        const bool isDigit = isdigit(line.at(0)) && isdigit(line.at(2)) && isdigit(line.at(4));
        const bool isDash = line.at(1) == '-' && line.at(3) == '-';
        if (isDigit && isDash) {
            const int firstDigit = line.at(0) - '0';
            const int secondDigit = line.at(2) - '0';
            const int thirdDigit = line.at(4) - '0';
            const bool isAtMostFive = firstDigit <= 5 && secondDigit <= 5 && thirdDigit <= 5;
            if (!isAtMostFive) {
                cout << "Please enter proper format of combination-of-positives triplet. 5-5-5 for example" << endl;
            }
            return isAtMostFive;
        } else {
            cout << "Please enter proper format of combination-of-positives triplet. 5-5-5 for example" << endl;
        }
        return false;;
    }
    return false;
}