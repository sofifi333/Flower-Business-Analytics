#include "customer.h"//this class is for each/per customer 
#include <iostream>
#include <string>

using namespace std;

string Customer::getFullName() const {
    return customerData.name + " " + customerData.lastName;
}

string Customer::getAccountNumber() const {
    return customerData.accountNum;
}

string Customer::getFirstName() const { 
    return customerData.name;
}

string Customer::getLastName() const {
    return customerData.lastName; 
}

string Customer::getAddress() const {
    return customerData.addy;
}

string  Customer::getCity() const {
    return customerData.city;
}

string Customer::getState() const {
    return customerData.state;
}

string Customer::getPhoneNumber() const {
    return customerData.phoneNum;
}

string Customer::getZipCode() const {
    return customerData.zipCode;
}


void Customer::setFirstName(string firstName) {
    customerData.name = firstName;
}

void Customer::setLastName(string lastName) {
    customerData.lastName = lastName;
}

void Customer::setAddress(string address) {
    customerData.addy = address;
}

void Customer::setCity(string city) {
    customerData.city = city;
}

void Customer::setState(string state) {
    customerData.state = state;
}

void Customer::setPhoneNumber(string phoneNumber) {
    customerData.phoneNum = phoneNumber;
}

void Customer::setZipCode(string zipCode) {
    customerData.zipCode = zipCode;
}

void Customer::setAccountNumber(string accountNumber) {
    customerData.accountNum = accountNumber;
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