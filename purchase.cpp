#include "purchase.h"
#include <string>
#include <iostream>

using namespace std;

Purchase::Purchase(std::string accountNumber, std::string item, std::string date, std::string amount) {
    purchaseData.accountNumber = accountNumber;
    purchaseData.item = item;
    purchaseData.date = date;
    purchaseData.amount = amount;
}

std::string Purchase::getAmount() const {
    return purchaseData.amount;
}

std::string Purchase::getAccountNumber() const {
    return purchaseData.accountNumber;
}

void Purchase::print() const {
    cout << "account number: " << purchaseData.accountNumber << endl;
    cout << "amount: " << purchaseData.amount << endl;
    cout << "date: " << purchaseData.date << endl;
    cout << "item: " << purchaseData.item << endl;
}