#ifndef PURCHASEMANAGER_H //manage purchases 
#define PURCHASEMANAGER_H
#include <vector>
#include <iostream>
#include<string>

class PurchaseManager {
public:
    double totalSpent();

private:
//define vector, total purchases etc(vars) --constructor to read from file
    struct Purchases { 
    double spent, itemCost, total; 
    std::string item, date;  
    }
    
    std::vector<Purchases*> purchases;

};

#endif