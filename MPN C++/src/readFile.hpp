#include <iostream>
#include <string>
#include <iomanip>

#ifndef __READFILE_HPP
#define __READFILE_HPP

using namespace std;

struct MPN {
    private : string combinationPositive;
                int mpnIndex, confidenceLower, confidenceUpper;
    public :
        MPN() {}
        MPN(const string combinationPositive, const int mpnIndex, const int confidenceLower, const int confidenceUpper) {
            this->combinationPositive = combinationPositive;
            this->mpnIndex = mpnIndex;
            this->confidenceLower = confidenceLower;
            this->confidenceUpper = confidenceUpper;
        }
        string getCombinationPositive () const{
            return this->combinationPositive;
        }
        int getMPN() const{
            return this->mpnIndex;
        }
        int getLowerConfidenceLimit() const{
            return this->confidenceLower;
        }
        int getUpperConfidenceLimit() const{
            return this->confidenceUpper;
        }
};

//read data
bool openFile(ifstream &infile);
int readFile(MPN *dataMPN, ifstream &infile);
MPN* createMPN(const int size);
void displayFileFormatError();

#endif