#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include "displayData.hpp"
#include "searchData.hpp"
#include "insertData.hpp"
#include "updateData.hpp"
#include "queryData.hpp"
#include "outFile.hpp"
#include "deleteData.hpp"
#include "mergeSort.hpp"

using namespace std;

void displayOption(int& mpnOption);
void welcomeMessage();

int main() {
    int size = 125, mpnOption = 0;
    MPN* dataMPN = createMPN(size);
    ifstream infile;
    ofstream outFile;
    size = readFile(dataMPN, infile);
    //sort the file via mergesort
    //in case if the file is not in order(I purposely made mix up the value)
    //has the best worst time complexity and more stable than heap sort
    sort(dataMPN, size);
    //immediately write to file after sorting is done
    writeFile(dataMPN, size, outFile);
    do {
        displayOption(mpnOption);
        if (mpnOption == 1) {
            output(dataMPN, size, 0);
        }
        else if (mpnOption == 2) {
            containCombinationPositive(dataMPN, size);
        }
        else if (mpnOption == 3) {
            insertNewData(dataMPN, size);
            writeFile(dataMPN, size, outFile);
        }
        else if (mpnOption == 4) {
            updateList(dataMPN, size);
            writeFile(dataMPN, size, outFile);
        }
        else if (mpnOption == 5) {
            displayQuery(dataMPN, size);
        }
        else if (mpnOption == 6) {
            deleteData(dataMPN, size);
            writeFile(dataMPN, size, outFile);
        }
        else if (mpnOption == 7) {
            writeFile(dataMPN, size, outFile);
        }
        if (mpnOption < 7) {
            cout << "Press any key to continue (except space key & enter key)..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\033[2J\033[1;1H";
        }
    } while (mpnOption != 7);
    writeFile(dataMPN, size, outFile);
    delete[] dataMPN;
    return 0;
}



void welcomeMessage() {
    cout <<  setfill(' ') << setw(50) << "\t       __      __        __\n";
    cout << setw(80) << "\t      /  \\    /  \\ ____ |  | ____  ____    _____   _____ \n";
    cout << setw(80) << "\t      \\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ /  __ \\\n";
    cout << setw(80) << "\t       \\        /|  ___/|  |  \\__(  <_> )|  | |  ||  ___/\n";
    cout << setw(80) << "\t        \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\\n" << endl;
}

void displayOption(int& mpnOption) {
    string line;
    bool isDigit;
    welcomeMessage();
    do {
        cout << "1. Display MPN list" << endl;
        cout << "2. Search data" << endl;
        cout << "3. Insert new data" << endl;
        cout << "4. Update data" << endl;
        cout << "5. Query data" << endl;
        cout << "6. Delete data" << endl;
        cout << "7. Exit" << endl;
        cout << "Please choose your option: ";
        getline(cin, line);
        isDigit = isInt(line, 1, 7);
        if (isDigit)
            mpnOption = line.at(0) - '0';
    } while (!isDigit);
}