#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

using namespace std;

class Customer { //customerData vars +  input data or read data
public:
        Customer(string name, string lastName, string accountNum, string addy, string city, string state, string zipCode, string phoneNum);
        void print();

        string getFullName() const;

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