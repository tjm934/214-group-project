#include <iostream>
#include <vector>
#include "customer.h"

using namespace std;

vector<int> noFlyList = new vector<string>();

Customer::Customer(string newTitle, string newFirstName, string newLastName, string newEmailAddress, string newPhoneNumber, string[] newCardDetails, int passportNumber, int frequentFlyerPoints) {
    title = newTitle;
    firstName = newFirstName;
    lastName = newLastName;
    emailAddress = newEmailAddress;
    phoneNumber = newPhoneNumber;
}
