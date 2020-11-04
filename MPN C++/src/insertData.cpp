#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "insertData.hpp"
#include "searchData.hpp"
#include "displayData.hpp"
#include "deleteData.hpp"

using namespace std;

void insertNewData(MPN* dataMPN, int &size) {
    //the size limit of MPN data is 125
    if (size <= 125) {
        const string combinationPositive = getCombinationPositive();
        const int mpn = getIndexMPN();
        const int low = getLowerBound();
        const int up = getUpperBound();
        for (int i = 0; i < size; i++) {
            int compare = combinationPositive.compare(dataMPN[i].getCombinationPositive());
            if (compare == -1) {
                //if the new data is smaller than the next data
                shiftDataToRight(dataMPN, size + 1, i);
                dataMPN[i].setCombinationPositive(combinationPositive);
                dataMPN[i].setMPN(mpn);
                dataMPN[i].setLowerConfidenceLimit(low);
                dataMPN[i].setUpperConfidenceLimit(up);
                size++;
                cout << "Inserting data...\nData successfully inserted" << endl;
                return;
            } else if (compare == 0) {
                //if the new data is alreadt exist
                cout << "You inserted a duplicated combination-of-positives triplet" << endl;
                output(dataMPN, i + 1, i);
                return;
            } else if (compare == 1 && i == size - 1) {
                //if the new data is the largest of all
                dataMPN[i].setCombinationPositive(combinationPositive);
                dataMPN[i].setMPN(mpn);
                dataMPN[i].setLowerConfidenceLimit(low);
                dataMPN[i].setUpperConfidenceLimit(up);
                cout << "Inserting data...\nData successfully inserted" << endl;
                return;
            }
        }
    } else {
        cout << "*WARNING*\nOnly 125 of MPN data is allowed\nYou've exceed the maximum MPN data capacity. Do you wish to delete some MPN data? (yes to proceed/ any key to exit)" << endl;
        string deleteOption;
        getline(cin, deleteOption);
        if (deleteOption.compare("yes") == 0 || deleteOption.compare("Yes") == 0)
            deleteData(dataMPN, size);
        else return ;
    }
}

void shiftDataToRight(MPN* dataMPN, const int size, const int index) {
    for (int i = size; i >= index; i--)
        dataMPN[i] = dataMPN[i - 1];
}

int getLowerBound() {
    string line;
    do {
        cout << "Please enter lower bound of 95% confidence limits: ";
        getline(cin, line);
    } while (!isInteger(line));
    return stoi(line);
}

int getUpperBound() {
    string line;
    do {
        cout << "Please enter upper bound of 95% confidence limits: ";
        getline(cin, line);
    } while (!isInteger(line));
    return stoi(line);
}


int getIndexMPN() {
    string line;
    do {
        cout << "Please enter MPN index/100ml: ";
        getline(cin, line);
    } while (!isInteger(line));
    return stoi(line);
}

bool isInteger(const string line) {
    if (line.length() != 0) {
        for (int i = 0; i < line.length(); i++) {
            if (!isdigit(line.at(i))) {
                cout << "Enter integer only" << endl;
                return false;
            }
        }
        return true;
    }
    return false;
}