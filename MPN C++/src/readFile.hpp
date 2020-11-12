#include <iostream>
#include <string>
#include <iomanip>

#ifndef __READFILE_HPP
#define __READFILE_HPP

using namespace std;

struct MPN {
    private : string combinationPositive;
    public :
        void setCombinationPositive(const string combinationPositive) {
            this->combinationPositive = combinationPositive;
        }
        string getCombinationPositive () const{
            return this->combinationPositive;
        }
    private : int mpnIndex, confidenceLower, confidenceUpper;
    public :
        void setMPN(int mpnIndex) {
            this->mpnIndex = mpnIndex;
        }
        void setLowerConfidenceLimit(const int confidenceLower) {
            this->confidenceLower = confidenceLower;
        }
        void setUpperConfidenceLimit(const int confidenceUpper) {
            this->confidenceUpper = confidenceUpper;
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