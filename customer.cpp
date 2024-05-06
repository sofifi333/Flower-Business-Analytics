#include "customer.h"
#include <iostream>
#include <string>

using namespace std;

string Customer::getFullName() const {
    return customerData.name + " " + customerData.lastName;
}
Customer::Customer(string name, string lastName, string accountNum, string addy, string city, string state, string zipCode, string phoneNum) {
    customerData.name = name;
    customerData.lastName = lastName;
    customerData.accountNum = accountNum;
    customerData.addy = addy;
    customerData.city = city;
    customerData.state = state;
    customerData.zipCode = zipCode;
    customerData.phoneNum = phoneNum;
}

void Customer::print() {
    cout << "first name: " << customerData.name << endl;
    cout << "last name: " << customerData.lastName << endl;
    cout << "account number: " << customerData.accountNum << endl;
    cout << "address: " << customerData.addy << endl;
    cout << "city: " << customerData.city << endl;
    cout << "state: " << customerData.state << endl;
    cout << "zip code: " << customerData.zipCode << endl;
    cout << "phone number: " << customerData.phoneNum << endl;
}