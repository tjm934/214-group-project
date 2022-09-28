#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

class Customer {
public:
    string userName;
    string title;
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string password;
    string cardDetails;
    int passportNumber;
    int frequentFlyerPoints = 0;

    void inputCustomerFromFile(ifstream *inputFile) {
        *inputFile >> userName >> title >> firstName >> lastName >> emailAddress >> phoneNumber >> password >> cardDetails >> passportNumber >> frequentFlyerPoints;
    }

    void outputCustomerToFile(ofstream *outputFile) {
        *outputFile << userName << ' ' << title << ' ' << firstName << ' ' << lastName << ' ' << emailAddress << ' ';
        *outputFile << phoneNumber << ' ' << password << ' ' << cardDetails << ' ' << passportNumber << ' ' << frequentFlyerPoints << endl;
    }
};

#endif // CUSTOMER_H_INCLUDED
