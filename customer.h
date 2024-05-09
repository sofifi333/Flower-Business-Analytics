#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

using namespace std;

class Customer { //customerData vars +  input data or read data
public:
        Customer(string name, string lastName, string accountNum, string addy, string city, string state, string zipCode, string phoneNum);
        void print();

        string getFullName() const;
        string getFirstName() const;
        string getLastName() const;
        string getAddress() const;
        string getCity() const;
        string getState() const;
        string getPhoneNumber() const;
        string getZipCode() const;
        string getAccountNumber() const;


        void setFirstName(string);
        void setLastName(string);
        void setAddress(string);
        void setCity(string);
        void setState(string);
        void setPhoneNumber(string);
        void setZipCode(string);
        void setAccountNumber(string);

private:
//use std:: to reference string since you are not using using namespace std;
    struct CustomerData {
        std::string name;
        std::string lastName;
        std::string accountNum;
        std::string addy;
        std::string city;
        std::string state;
        std::string zipCode;
        std::string phoneNum;
    };
    CustomerData customerData;
};

#endif