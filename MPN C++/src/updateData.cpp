#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "updateData.hpp"
#include "searchData.hpp"
#include "insertData.hpp"

using namespace std;

void updateList(MPN* dataMPN, const int size) {
    const string data = getCombinationPositive();
    for (int i = 0; i < size; i++) {
        if (data == dataMPN[i].getCombinationPositive()) {
            string choice;
            int option;
            do {
                option = askOption();
                if (option == 4)return;
                updateData(dataMPN[i], option);
                cout << "Would you like to continue to change (yes to continue/ any key to exit): ";
                getline(cin, choice);
            } while (choice.compare("yes") == 0 || choice.compare("Yes") == 0);
        }
    }
}

void updateData(MPN &dataMPN, const int option) {
    int previousData;
    if (option == 1) {
        previousData = dataMPN.getMPN();
        dataMPN.setMPN(getIndexMPN());
        cout << "MPN index/100ml updated from " << previousData << " to " << dataMPN.getMPN() << endl;
    }
    else if (option == 2) {
        previousData = dataMPN.getLowerConfidenceLimit();
        dataMPN.setLowerConfidenceLimit(getLowerBound());
        cout << "95% lower confidence limit updated from " << previousData << " to " << dataMPN.getLowerConfidenceLimit() << endl;
    }
    else if (option == 3) {
        previousData = dataMPN.getUpperConfidenceLimit();
        dataMPN.setUpperConfidenceLimit(getUpperBound());
        cout << "95% upper confidence limit updated from " << previousData << " to " << dataMPN.getUpperConfidenceLimit() << endl;
    }
}

int askOption() {
    int option;
    string choice;
    bool isValid = false;
    do {
        cout << "Please enter your option (1-4) to update" << endl;
        cout << "1. MPN index" << endl;
        cout << "2. Lower 95% confidence interval" << endl;
        cout << "3. Upper 95% confidence interval" << endl;
        cout << "4. Exit update" << endl;
        getline(cin, choice);
        isValid = isInt(choice, 1, 4);
        if (isValid) option = choice.at(0) - '0';
    } while (!isValid);
    return option;
}

bool isInt(const string line, const int min, const int max) {
    if (isdigit(line.at(0)) && line.length() == 1) {
        const int x = line.at(0) - '0';
        if(x >= min && x <= max) return true;
        else {
            cout << "Please enter integer from " << min << " to " << max << " only" << endl;
            return false;
        }
    } else cout << "Please enter integer from " << min << " to " << max << " only" << endl;
    return false;
}