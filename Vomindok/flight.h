#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>
#include <ctime>

using namespace std;

class Flight {
public:
    string startLocation;
    string endLocation;
    time_t flightDateAndTime;
    int flightDurationInHours;
    string layoverLocation;
    int numberOfSeats;
    string seatCode;
};


#endif // FLIGHT_H_INCLUDED
