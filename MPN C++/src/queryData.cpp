#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "displayData.hpp"
#include "queryData.hpp"
#include "updateData.hpp"

using namespace std;

void displayQuery(MPN* dataMPN, const int size) {
    string choice = "";
    do {
        int option = 0;
        const double volume = queryChoice(&option);
        const int amountObtained = tubesQuantity(volume);
        MPN* queryMPN = new MPN[size];
        int k = 0;
        if (option == 1) option = 0;
        else if (option == 3) option = 4;
        cout << "Option: " << option << " " << amountObtained << endl;
        for (int i = 0; i < size; i++) {
            int amountBottle = dataMPN[i].getCombinationPositive().at(0) - '0';
            if (amountBottle == amountObtained) {
                queryMPN[k] = dataMPN[i];
                k++;
            }
        }
        cout << "Querying data..." << endl;
        output(queryMPN, k, 0);
        cout << "Data is successfully query" << endl;
        cout << "Would you like to continue to query (yes to continue/ any key to exit): ";
        getline(cin, choice);
    } while (choice.compare("yes") == 0 || choice.compare("Yes") == 0);
}

int tubesQuantity(const double volume) {
    int amount;
    string choice;
    bool isValid;
    do {
        cout << "How many tubes do you want to query for " << volume << "ml tube(s): ";
        getline(cin, choice);
        isValid = isInt(choice, 1, 5);
        if (isValid)
            amount = choice.at(0) - '0';
    } while (!isValid);
    return amount;
}

double queryChoice(int* option) {
    double volume = 0;
    string choice;
    bool isValid = false;
    do {
        cout << "Please enter your option (1-4) to query" << endl;
        cout << "1. 10 ml tube" << endl;
        cout << "2. 1 ml tube" << endl;
        cout << "3. 0.1 ml tube" << endl;
        cout << "4. Exit query" << endl;
        cout << "Option: ";
        getline(cin, choice);
        isValid = isInt(choice, 1, 4);
        if (isValid) {
            *option = choice.at(0) - '0';
            if (*option >= 1 && *option <= 4) {
                if (*option == 1) volume = 10;
                else if (*option == 2) volume = 1;
                else if (*option == 3) volume = 0.1;
            }
        }
    } while (!isValid);
    return volume;
}