#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

class Flight {
public:
    string forUsername;
    string startLocation;
    string endLocation;
    time_t flightDateAndTime;
    int flightDurationInHours;
    string layoverLocation;
    int numberOfSeats;
    string seatCode;
    double price;

    void inputFlightFromFile(ifstream *inputFile) {
        *inputFile >> forUsername >> startLocation >> endLocation >> flightDateAndTime >> flightDurationInHours >> layoverLocation >> numberOfSeats >> seatCode >> price;
    }

    void outputFlightToFile(ofstream *outputFile) {
        *outputFile << forUsername << ' ' << startLocation << ' ' << endLocation << ' ' << flightDateAndTime << ' ' << flightDurationInHours << ' ' << layoverLocation << ' ';
        *outputFile << numberOfSeats << ' ' << seatCode << ' ' << price << endl;
    }
};

#endif // FLIGHT_H_INCLUDED
