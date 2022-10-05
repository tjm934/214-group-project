#include <iostream>
#include <vector>
#include <fstream>
#include "customer.h"
#include "flight.h"

using namespace std;

void userScreen(Customer *toLoad) {
    bool dontExitLoop = true;
    const string flightsDataFile = "flightsInfo";
    vector<Flight> listOfFlights;
    Flight flightToLoad;

    ifstream inputFromFlightsFile(flightsDataFile);
    if(inputFromFlightsFile.fail()) {
        inputFromFlightsFile.close();
    }else{
        while(!inputFromFlightsFile.eof()) {
            flightToLoad.inputFlightFromFile(&inputFromFlightsFile);
            listOfFlights.push_back(flightToLoad);
        }
    }

    while(dontExitLoop) {
        int choiceNumber = 0;
        cout << "==============================" << endl;
        cout << "1: Update details" << endl;
        cout << "2: Book flight" << endl;
        cout << "3: Upgrade seats" << endl;
        cout << "4: Cancel booking" << endl;
        cout << "5: Purchase in-flight services" << endl;
        cout << "6: Exit" << endl;
        cout << "==============================" << endl;
        cin.clear();
        cin.ignore();
        cin >> choiceNumber;
        if(choiceNumber == 1) {
            cout << "Re-enter new username: ";
            cin >> toLoad->userName;
            cout << "Re-enter password: ";
            cin >> toLoad->password;
            cout << "Re-enter title: ";
            cin >> toLoad->title;
            cout << "Re-enter first name: ";
            cin >> toLoad->firstName;
            cout << "Re-enter last name: ";
            cin >> toLoad->lastName;
            cout << "Re-enter email address: ";
            cin >> toLoad->emailAddress;
            cout << "Re-enter phone number(international format): ";
            cin >> toLoad->phoneNumber;
            cout << "Re-enter card details(in format number;expiry date;cv): ";
            cin >> toLoad->cardDetails;
            cout << "Re-enter passport number: ";
            cin >> toLoad->passportNumber;
        }else if(choiceNumber == 2) {
            flightToLoad.forUsername = toLoad->userName;
            cout << "Enter start location: ";
            cin >> flightToLoad.startLocation;
            cout << "Enter end location: ";
            cin >> flightToLoad.endLocation;
            cout << "Enter layover location: ";
            cin >> flightToLoad.layoverLocation;
            cout << "Enter number of seats: ";
            cin >> flightToLoad.numberOfSeats;
            cout << "Enter seat code(example A1, first row first seat, for multiple rows A1,G6): ";
            cin >> flightToLoad.seatCode;
            cout << "Flight duration is " << (flightToLoad.endLocation.length() - flightToLoad.startLocation.length()) + 1 << " hours " << endl;
            flightToLoad.flightDurationInHours = (flightToLoad.endLocation.length() - flightToLoad.startLocation.length()) + 1;
            cout << "Enter type of booking: ";
            string typeOfBooking;
            cin >> typeOfBooking;
            if(typeOfBooking == "early") {
                flightToLoad.price = flightToLoad.flightDurationInHours*75;
            }else if(typeOfBooking == "normal") {
                flightToLoad.price = flightToLoad.flightDurationInHours*100;
            }else if(typeOfBooking == "late") {
                flightToLoad.price = flightToLoad.flightDurationInHours*125;
            }
            cout << "Enter the date for flight(day/month): ";
            cin >> flightToLoad.flightDate;
            listOfFlights.push_back(flightToLoad);
        }else if(choiceNumber == 3) {
            int flightsCounter = 1;
            cout << " | To              | From" << endl;
            for(auto iter = listOfFlights.begin(); iter != listOfFlights.end(); iter++) {
                if(iter->forUsername == toLoad->userName) {
                    cout << flightsCounter << ": " << iter->startLocation << "           " << iter->endLocation << endl;
                    flightsCounter++;
                }
            }
            int choice = 0;
            cout << "Which booked flight do you want to increase?" << endl;
            cin >> choice;
            for(auto iter = listOfFlights.begin(); iter != listOfFlights.end(); iter++) {
                if(iter->forUsername == toLoad->userName) {
                    if(flightsCounter == choice) {
                        cout << "Enter new number of seats: ";
                        cin >> iter->numberOfSeats;
                        cout << "Seats upgraded, upgrade price will charged to card" << endl;
                    }
                    flightsCounter++;
                }
            }

        }else if(choiceNumber == 4) {
            int flightsCounter = 1;
            cout << " | To              | From" << endl;
            for(auto iter = listOfFlights.begin(); iter != listOfFlights.end(); iter++) {
                if(iter->forUsername == toLoad->userName) {
                    cout << flightsCounter << ": " << iter->startLocation << " " << iter->endLocation << endl;
                    flightsCounter++;
                }
            }
            int choice = 0;
            int i = 0;
            cout << "Which booked flight do you want to cancel?" << endl;
            cin >> choice;
            for(auto iter = listOfFlights.begin(); iter != listOfFlights.end(); iter++) {
                if(iter->forUsername == toLoad->userName) {
                    if(flightsCounter == choice) {
                        cout << "yes" << endl;
                        listOfFlights.erase(iter);
                    }
                    flightsCounter++;
                }
            }
        }else if(choiceNumber == 5) {
            int insignificant;
            cout << "================================" << endl;
            cout << "What would you like to purchase?" << endl;
            cout << "1: Chips" << endl;
            cout << "2: Soft drink" << endl;
            cout << "3: Water" << endl;
            cout << "4: Alcoholic beverages" << endl;
            cout << "================================" << endl;
            cin >> insignificant;
            cout << "Flight attendant with cart is now coming towards your seat" << endl << "Please choose from the options available when they arrive" << endl;
        }else{
            ofstream outputToFlightsFile(flightsDataFile);
            for(auto iter = listOfFlights.begin(); iter != listOfFlights.end(); iter++) {
                iter->outputFlightToFile(&outputToFlightsFile);
            }
            outputToFlightsFile.close();
            dontExitLoop = false;
        }

    }
    return;
}

void manageSystem() {

}

int main()
{
    vector<Customer> listOfCustomers;
    bool hasntExited = true;
    bool hasntFoundCustomer = true;
    const string customersInfoFile = "customersInfo";
    ifstream inputFromCustomersFile(customersInfoFile);
    Customer customerToLoad;

    if(inputFromCustomersFile.fail()) {
        inputFromCustomersFile.close();
    }else{
        while(!inputFromCustomersFile.eof()) {
            customerToLoad.inputCustomerFromFile(&inputFromCustomersFile);
            listOfCustomers.push_back(customerToLoad);
        }
    }

    while(hasntExited) {
        int choice = 0;
        cout << "==============================" << endl;
        cout << "1: Login as existing customer" << endl;
        cout << "2: Create new customer" << endl;
        cout << "3: Manage system" << endl;
        cout << "4: Exit" << endl;
        cout << "==============================" << endl;
        cin >> choice;

        if(choice == 1) {
            string username;
            string password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            for(auto iter = listOfCustomers.begin(); iter != listOfCustomers.end() && hasntFoundCustomer; iter++) {
                if(iter->userName == username) {
                    if(iter->password == password) {
                        cout << "Entered correct password" << endl;
                        customerToLoad = *iter;
                        hasntFoundCustomer = false;
                    }else if(iter->password != password) {
                        cout << "Incorrect password please try again" << endl;
                    }
                }else{
                    cout << iter->userName << endl;
                }
            }

            if(hasntFoundCustomer) {
                cout << "Couldn't find user, please create new user" << endl;
            }else{
                userScreen(&customerToLoad);
            }

        }else if(choice == 2) {
            cout << "Enter username: ";
            cin >> customerToLoad.userName;
            cout << "Enter password: ";
            cin >> customerToLoad.password;
            cout << "Enter title: ";
            cin >> customerToLoad.title;
            cout << "Enter first name: ";
            cin >> customerToLoad.firstName;
            cout << "Enter last name: ";
            cin >> customerToLoad.lastName;
            cout << "Enter email address: ";
            cin >> customerToLoad.emailAddress;
            cout << "Enter phone number(international format): ";
            cin >> customerToLoad.phoneNumber;
            cout << "Enter card details(in format number;expiry date;cv): ";
            cin >> customerToLoad.cardDetails;
            cout << "Enter passport number: ";
            cin >> customerToLoad.passportNumber;
            userScreen(&customerToLoad);
            listOfCustomers.push_back(customerToLoad);
        }else if(choice == 3) {
            const string adminPassword = "vomindok";
            string enteredAdminPassword;
            cout << "Enter administrator password: ";
            cin >> enteredAdminPassword;
            if(enteredAdminPassword == adminPassword) {
                manageSystem();
            }else{
                cout << "Couldn't find user, please create new user" << endl;
            }
        }else{
            hasntExited = false;
        }
    }

    ofstream outputToCustomersFile(customersInfoFile);
    for(auto iter = listOfCustomers.begin(); iter != listOfCustomers.end(); iter++) {
        iter->outputCustomerToFile(&outputToCustomersFile);
    }
    outputToCustomersFile.close();
    return 0;
}
