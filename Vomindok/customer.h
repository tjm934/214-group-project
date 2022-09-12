#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

class Customer {
private:
    string title;
    string firstName;
    string lastName;
    string emailAddress;
    string phoneNumber;
    string cardDetails[3];
    int passportNumber;
    int frequentFlyerPoints;
public:
    Customer(string newTitle, string newFirstName, string newLastName, string newEmailAddress, string newPhoneNumber, string[] newCardDetails, int passportNumber, int frequentFlyerPoints) {
        title = newTitle;
        firstName = newFirstName;
        lastName = newLastName;
        emailAddress = newEmailAddress;
        phoneNumber = newPhoneNumber
        cardDetails = newCardDetails;
        passportNumber = newPassportNumber;
        frequentFlyerPoints = newFrequentFlyerPoints;
    }
};

#endif // CUSTOMER_H_INCLUDED
