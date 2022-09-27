#include <iostream>
#include <vector>
#include <fstream>
#include "customer.h"
#include "flight.h"

using namespace std;

int main()
{
    vector<Customer> listOfCustomers;
    bool hasntFoundCustomer = true;
    ifstream inputFromDataFile("customersInfo");
    ofstream outputToDataFile;

    if(!inputFromDataFile.fail()) {
        outputToDataFile.open("customersInfo");
    }

    Customer customerToLoad;
    while(!inputFromDataFile.eof()) {
        inputFromDataFile >> customerToLoad.userName >> customerToLoad.title >> customerToLoad.firstName >> customerToLoad.lastName >> customerToLoad.emailAddress >> customerToLoad.phoneNumber >> customerToLoad.password >> customerToLoad.cardDetails >> customerToLoad.passportNumber >> customerToLoad.frequentFlyerPoints;
        listOfCustomers.push_back(customerToLoad);
    }

    int choice = 0;
    cout << "1: Login as existing customer" << endl;
    cout << "2: Create new customer" << endl;
    cout << "3: Exit" << endl;
    cin >> choice;
    switch(choice) {
    case 1:
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
             }
        }
        cout << "Couldn't find user, please create new user" << endl;
        break;
    case 2:
        string userName;
        string title;
        string firstName;
        string lastName;
        string emailAddress;
        string phoneNumber;
        string password;
        string cardDetails;
        cout << "Enter username: ";
        cin >> userName;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;
        cout << "Enter email address: ";
        cin >> emailAddress;
        cout << "Enter phone number(international format): ";
        cin >> phoneNumber;
        cout << "Enter card details(in format number;expiry date;cv): ";
        cin >> cardDetails;
        outputToDataFile << userName << title << firstName << lastName << emailAddress << phoneNumber << password << cardDetails << passportNumber << frequentFlyerPoints;
        customerToLoad.password = password;
        customerToLoad.title = title;
        customerToLoad.firstName = firstName;
        customerToLoad.lastName = lastName;
        customerToLoad.emailAddress = emailAddress;
        customerToLoad.phoneNumber = phoneNumber;
        customerToLoad.cardDetails = cardDetails;
        listOfCustomers.push_back(customerToLoad);
    }
    return 0;
}
