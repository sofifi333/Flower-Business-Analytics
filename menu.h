#ifndef MENU_H
#define MENU_H

#include <vector>
#include "customer.h"

class Menu { //manages all menu functionalities
public: 
    Menu();
    void run();
    void printMenu();
    void execute(int);

    void printCustomers();
    void printDescendingList();
    void printAscendingList();
    void printCustomerInfo();
    void printCustomerTotal();
    double totalSpent();
private:
    std::vector<Customer *> customers;
};

#endif 