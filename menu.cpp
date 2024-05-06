#include "menu.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Menu::printMenu()
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "|\t\t\t\t\t\tMENU\t\t\t\t\t\t|\n";
    cout << "|\t\t\t\t\t____________________\t\t\t\t\t|\n"
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "|\t\tWelcome to Blossom Botique! Your one-stop shop for all your floral needs.\t|\n"
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "|\t\tPlease Select a Number corresponding with one of the following options:\t\t|\n"
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "|   \t            1. Print menu" << endl;
    cout << "|   \t            2. Print all Customers"
         << "\t\t\t\t\t\t\t|" << endl;
    cout << "|   \t	    3. Print Customer list in DESCENDING order\t\t\t\t\t|\n";
    cout << "|   \t	    4. Print Customer list in ASCENDING order\t\t\t\t\t|\n";
    cout << "|   \t	    5. Print a Customer's account information\t\t\t\t|\n";

    cout << "|   \t	    6. Print total spent for a select Customer\t\t\t\t\t|\n";
    cout << "|   \t	    7. Add new Customer\t\t\t\t\t\t\t\t|\n";
    cout << "|   \t	    8. Add multiple Customers\t\t\t\t\t\t\t|\n";
    cout << "|   \t	    9. Update select Customer's information\t\t\t\t\t|\n";

    cout << "|   \t	    10. Delete select Customer's account information\t\t\t\t|\n";
    cout << "|   \t	   11. Add new Customer's purchase\t\t\t\t\t\t|\n";
    cout << "|   \t	   12. Add multiple new Customer purchases\t\t\t\t\t|\n";
    cout << "|   \t	   13. Save new data\t\t\t\t\t\t\t\t|\n";
    cout << "|   \t	   14. Export to new file\t\t\t\t\t\t\t|\n"
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

}

void Menu::run() {
    string option;
    printMenu();

    while (1 + 1 == 2) {
LABEL:
        cout << "main menu> ";
        cin.clear(); //
        getline(cin, option);

//try catch ->used for errors...trying to make input a # .. if user doesn't enter a # catch the error
//other approach is to use while loop/if stmts 
        try {
            int option_int = stoi(option); //stoi converts input to number

            execute(option_int);
        } catch (std::exception e) {
            cout << "Please enter a number! " << endl;
            goto LABEL; //loops again from cout << main menu
        }
    }
}

//constructor to read file1 automatically: 
Menu::Menu() {
    string line, temp, data[8]; //string that can be 8 chars/array 
    ifstream inFile("customerData.txt"); 
// dont forget to ofstream in another file
    if(!inFile.is_open()) {
        cout << "ERROR: File does NOT open " << endl;
        return;
    }

    while (getline(inFile, line)) {
        //loop through each character line by line and save it in each variable
        int i = 0;
        for (auto c : line) { //line is storing the entire line(8 vars of one line in 8 indexes) ...for every char in line
            if (c == ' ') {
                data[i++] = temp; //set slot equal to current word BRENT saved in data[0] 
                temp = "";
            } else
                temp += c; //if theres no space we are still adding characters of that same word 
        }
        data[i] = temp; //transferring 
        temp = "";
        Customer* newCustomer = new Customer(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]); //temp ptr variable
        customers.push_back(newCustomer); //vector contains mem addy of the objects 
        
    }

    inFile.close();

    run();
}



void Menu::printCustomers()
{ // print list of all customers --calls print for every index of vector 
    for (Customer* customer : customers) { //for each customer IN customers -> for each loop ..for every index in customers u make ptr var/object customer that accesses anything within the index--every index is ptr to object(can access vars, methods, anything w -> syntax)
        customer->print();
        cout << "\n\n";
    }
}

void Menu::printDescendingList()
{ //like quick sort and print
    sort(customers.begin(), customers.end(), [](Customer* a, Customer* b) { return a->getFullName() > b->getFullName(); }); //sorting by 2s--swaps a & b
    printCustomers();
}

void Menu::printAscendingList()
{ // sort and print

    sort(customers.begin(), customers.end(), [](Customer* a, Customer* b) { return a->getFullName() < b->getFullName(); });
    printCustomers();
}

void Menu::printCustomerInfo()
{ // select a customer and print all info+all purchases made
    int i = 1;
    string number;
    //for a customer in customers
    for (auto* customer : customers) {
        cout << i << ") " << customer->getFullName() << endl; //customer->getFullName ..ptr customer is getting the fullName 
        i++;
    }
LABEL: //jumps back here
    cout << "customer info> ";

    cin.clear(); 
    getline(cin, number);

    try {
        int number_int = stoi(number); //stoi converts input to number

        if (number_int > customers.size()) { //if number is out of range
            cout << "Customer is not found!" << endl;
            goto LABEL;
        }

        customers[number_int - 1]->print(); //prints actual values at # user inputted vector stores at index 0, so use-1.
    } catch (std::exception e) { //exception e-- stores the error. if there was an error with try, automatically goes to catch 
        cout << "Please enter a number! " << endl;
        goto LABEL;
    }
}

void Menu::printCustomerTotal()
{ // select a customer and print out total for all their purchases
}

void Menu::execute(int option)
{
    switch (option)
    {
    case 1:
        printMenu();
        break;
    case 2:
        printCustomers();
        break;
    case 3:
        printDescendingList();
        break;
    case 4:
        printAscendingList();
        break;
    case 5:
        printCustomerInfo();
        break;
    case 6:
        printCustomerTotal();
        break;
    case 7:
        // addNewCustomer();
        break;
    case 8:
        // addNewCustomers();
        break;
    case 9:
        // updateCustomerInfo();
        break;
    case 10:
        // deleteCustomerInfo();
        break;
    case 11:
        // addNewPurchase();
        break;
    case 12:
        // addNewPurchases();
        break;
    case 13:
        // save();
        break;
    case 14:
        // export();
        break;
        
    default:
        cout << "Invalid option!" << endl;
    }
}
