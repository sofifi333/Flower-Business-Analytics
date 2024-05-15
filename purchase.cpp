#include "purchase.h"
#include <string>
#include <iostream>
#include <iomanip>

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
    cout << left << setw(16) << purchaseData.accountNumber << left << setw(13) << purchaseData.item << left << setw(15) << purchaseData.date << left << setw(22) << purchaseData.amount << endl;
}


std::string Purchase::getItem() const {
    return purchaseData.item;
}
std::string Purchase::getDate() const {
    return purchaseData.date;
}