#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>

class Purchase {
public:
    Purchase(std::string accountNumber, std::string item, std::string date, std::string amount);
    std::string getAccountNumber() const;
    std::string getAmount() const;
    void print() const;
private:
    struct PurchaseData {
        std::string accountNumber;
        std::string item;
        std::string date;
        std::string amount;
    };

    PurchaseData purchaseData;
};

#endif