#ifndef MENU_H
#define MENU_H

#include <vector>
#include "customer.h"
#include "purchase.h"

class Menu { //manages all menu functionalities
public: 
    Menu();
    void run();
    void printMenu();
    void execute(int);
    void save();
    void export_data();
    void printPurchases(string);

    void printCustomers();
    void printDescendingList();
    void printAscendingList();
    void printCustomerInfo();
    void printCustomerTotal();
    void addNewCustomer();
    void addNewCustomers();
    void updateCustomerInfo();
    void deleteCustomerInfo();
    void addNewPurchase();
    void addNewPurchases();

private:
    std::vector<Purchase *> purchases;
    std::vector<Customer *> customers;
};

#endif 