#include <iostream>
#include <vector>
#include <fstream>
#include "customer.h"
#include "flight.h"

using namespace std;

void userScreen(Customer *toLoad) {

}

void manageSystem() {

}

int main()
{
    vector<Customer> listOfCustomers;
    bool hasntFoundCustomer = true;
    ifstream inputFromDataFile("info");
    ofstream outputToDataFile;

    if(!inputFromDataFile.fail()) {
        outputToDataFile.open("info");
    }

    Customer customerToLoad;
    while(!inputFromDataFile.eof()) {
        inputFromDataFile >> customerToLoad.userName >> customerToLoad.title >> customerToLoad.firstName >> customerToLoad.lastName >> customerToLoad.emailAddress >> customerToLoad.phoneNumber >> customerToLoad.password >> customerToLoad.cardDetails >> customerToLoad.passportNumber >> customerToLoad.frequentFlyerPoints;
        listOfCustomers.push_back(customerToLoad);
    }

    int choice = 0;
    cout << "1: Login as existing customer" << endl;
    cout << "2: Create new customer" << endl;
    cout << "3: Manage system" << endl;
    cout << "Any other key: Exit" << endl;
    cin >> choice;
    if(choice == 1) {
        cout << "Enter username: ";
        string username;
        string password;
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
    }else if(choice == 2) {
        cout << "Enter username: ";
        string userName;
        string title;
        string firstName;
        string lastName;
        string emailAddress;
        string phoneNumber;
        string passWord;
        string cardDetails;
        int passportNumber;
        int frequentFlyerPoints;
        cin >> userName;
        cout << "Enter password: ";
        cin >> passWord;
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
        cout << "Enter passport number: ";
        cin >> passportNumber;
        outputToDataFile << userName << title << firstName << lastName << emailAddress << phoneNumber << passWord << cardDetails << passportNumber << 0;
        customerToLoad.password = passWord;
        customerToLoad.title = title;
        customerToLoad.firstName = firstName;
        customerToLoad.lastName = lastName;
        customerToLoad.emailAddress = emailAddress;
        customerToLoad.phoneNumber = phoneNumber;
        customerToLoad.cardDetails = cardDetails;
        listOfCustomers.push_back(customerToLoad);
        userScreen(user)
    }else if(choice == 3) {
        const string adminPassword = "vomindok";
        string enteredAdminPassword;
        cout << "Enter administrator password: ";
        cin >> enteredAdminPassword;
        if(enteredAdminPassword == adminPassword) {
            manageSystem();
        }
    }
    return 0;
}
