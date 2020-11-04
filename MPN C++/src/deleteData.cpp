#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "deleteData.hpp"
#include "searchData.hpp"
#include "displayData.hpp"

using namespace std;

void deleteData(MPN* dataMPN, int &size) {
    string line = getCombinationPositive();
    for (int i = 0; i < size; i++) {
        if (line == dataMPN[i].getCombinationPositive()) {
            output(dataMPN, i + 1, i);
            cout << "Are you sure you want to delete the data above\nSuch action is irreversible" << endl;
            cout << "Press yes to delete/ any key to exit" << endl;
            getline(cin, line);
            if (line.compare("yes") == 0 || line.compare("Yes") == 0) {
                cout << "Deleting data...\nData successfully deleted" << endl;
                shiftDataToLeft(dataMPN, size, i+1);
                return;
            }
            else return;
        }
    }
}

void shiftDataToLeft(MPN* dataMPN, int &size, const int index) {
    for (int i = index; i < size; i++)
        dataMPN[i - 1] = dataMPN[i];
    size--;
}