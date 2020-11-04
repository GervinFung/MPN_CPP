#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "readFile.hpp"

using namespace std;

// return true if successfully open data.txt file
bool openFile(ifstream &infile) {
    infile.open("data.txt");
    return !infile.fail();
}

// return the number of MPN data after reading from file
int readFile(MPN *dataMPN, ifstream &infile) {
    bool canOpen = openFile(infile);
    //check if file is empty
    if (infile.peek() == ifstream::traits_type::eof()) {
        canOpen = false;
        displayFileFormatError();
        exit(0);
    }
    int i = 0;
    string line;
    if (canOpen) {
        try {
            while (getline(infile, line)) {
                int found, j = 0;
                string data[4];
                for (int i = 0; i < 4; i++) {
                    found = line.find(" ");
                    for (int k = 0; k < found; k++)
                        data[j] += line[k];
                    line.erase(0, found + 1);
                    j++;
                }
                dataMPN[i].setCombinationPositive(data[0]);
                dataMPN[i].setMPN(stoi(data[1]));
                dataMPN[i].setLowerConfidenceLimit(stoi(data[2]));
                dataMPN[i].setUpperConfidenceLimit(stoi(data[3]));
                i++;
            }
            infile.close();
        } catch(const exception& e) {
            //catch incorrect file format error
            displayFileFormatError();
            exit(0);
        }
    } else cerr << "Failed to open file" << endl;
    return i;
}

MPN* createMPN(const int size) {
    //initialise array for structure MPN
    MPN* arrayMPN = new MPN[size];
    return arrayMPN;
}

void displayFileFormatError() {
    cerr << "*WARNING*" << endl;
    cerr << "There is an error of data in data.txt text file" << endl;
    cerr << "The data in data.txt should be in the following format\n" << endl;
    cerr << "combination-of-positivestriplet mpnIndex lower 95% limit upper 95& limit\n" << endl;
    cerr << "For example\n1-1-1 50 50 99 " << endl;
    cerr << "1-2-3 55 57 79\nand so on...\nThere should be a space at the end of a number except for combination-of-positivestriplet" << endl;
}