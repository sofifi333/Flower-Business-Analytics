#include "menu.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>



void Menu::printMenu()
{
     std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     std::cout << "|\t\t\t\t\t\tMENU\t\t\t\t\t\t|\n";
     std::cout << "|\t\t\t\t\t____________________\t\t\t\t\t|\n"
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" <<  std::endl;
     std::cout << "\033[31m"; // Set color to green
     cout << "";
     std::cout << R"(             __
        _   /  |                    
       | \  \/_/                    
       \_\| / __                     
          \/_/__\           )";
     std::cout << R"( .--='/~\
   ____,__/__,_____,______)/   /{~}}}
   -,-----,--\--,-----,---,\'-' {{~}}
)";
      std::cout << R"(        __/\_            '--=.\}/
          /_/ |\\
               \/
)" << "\033[0m" <<   std::endl;
     std::cout << "|\t\tWelcome to Blossom Botique! Your one-stop shop for all your floral needs.\t|\n"
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" <<  std::endl;
     std::cout << "|\t\tPlease Select a Number corresponding with one of the following options:\t\t|\n"
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" <<  std::endl;
    
     std::cout << "|   \t            1. Print menu" << "\t\t\t\t\t\t\t\t|" << std::endl;
     std::cout << "|   \t            2. Print all Customers"
         << "\t\t\t\t\t\t\t|" <<  std::endl;
     std::cout << "|   \t	    3. Print Customer list in DESCENDING order\t\t\t\t\t|\n";
     std::cout << "|   \t	    4. Print Customer list in ASCENDING order\t\t\t\t\t|\n";
     std::cout << "|   \t	    5. Print a Customer's account information\t\t\t\t\t|\n";

     std::cout << "|   \t	    6. Print total spent for a select Customer\t\t\t\t\t|\n";
     std::cout << "|   \t	    7. Add new Customer\t\t\t\t\t\t\t\t|\n";
     std::cout << "|   \t	    8. Add multiple Customers\t\t\t\t\t\t\t|\n";
     std::cout << "|   \t	    9. Update select Customer's information\t\t\t\t\t|\n";

     std::cout << "|   \t	   10. Delete select Customer's account information\t\t\t\t|\n";
     std::cout << "|   \t	   11. Add new Customer's purchase\t\t\t\t\t\t|\n";
     std::cout << "|   \t	   12. Add multiple new Customer purchases\t\t\t\t\t|\n";
     std::cout << "|   \t	   13. Save new data\t\t\t\t\t\t\t\t|\n"; //create outfile, overwrite what you wrote  std::cout (to outfile) make sure to call the function --use the same file you wrote in 
     std::cout << "|   \t	   14. Export to new file\t\t\t\t\t\t\t|\n"; //create outfile, exporting to secondary file--make sure to do both files(must do it twice) (make function do both to both files, from within output function you want it to print it)
     std::cout << "|   \t	   15. exit\t\t\t\t\t\t\t\t\t|\n" //create outfile, exporting to secondary file--make sure to do both files(must do it twice) (make function do both to both files, from within output function you want it to print it)
         << "|\t\t\t\t\t\t\t\t\t\t\t\t|" <<  std::endl;
     std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<  std::endl;
}

void Menu::run()
{
     std::string option;
    printMenu();

    while (1 + 1 == 2)
    {
        if (option != "") {
RUN_AGAIN:
             std::cout << "Would you like to print the menu? (Y/n): ";
             std::getline(cin, option);
            if (option == "Y" || option == "y" ) {
                printMenu();
            } else if (option != "N" && option != "n") {
                goto RUN_AGAIN;
            }
        }
    LABEL:
         std::cout << "main menu> ";
        cin.clear(); //
         std::getline(cin, option);

        // try catch ->used for errors...trying to make input a # .. if user doesn't enter a # catch the error
        // other approach is to use while loop/if stmts
        try
        {
            int option_int = stoi(option); // stoi converts input to number

            execute(option_int);
        }
        catch ( exception e)
        {
             std::cout << "Please enter a number! " <<  std::endl;
            goto LABEL; // loops again from  std::cout << main menu
        }
    }
}

// constructor to read file1 automatically:
Menu::Menu()
{
     std::string line, temp, data[8]; //  std::string that can be 8 chars/array
     std::ifstream inFile("customerData.txt");
    // dont forget to  std::ofstream in another file
    if (!inFile.is_open())
    {
         std::cout << "ERROR: File does NOT open " <<  std::endl;
        return;
    }

    while ( std::getline(inFile, line))
    {
        // loop through each character line by line and save it in each variable
        int i = 0;
        for (auto c : line)
        { // line is storing the entire line(8 vars of one line in 8 indexes) ...for every char in line
            if (c == ' ')
            {
                data[i++] = temp; // set slot equal to current word BRENT saved in data[0]
                temp = "";
            }
            else
                temp += c; // if theres no space we are still adding characters of that same word
        }
        data[i] = temp; // transferring
        temp = "";
        Customer *newCustomer = new Customer(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]); // temp ptr variable
        customers.push_back(newCustomer);                                                                             // vector contains mem addy of the objects
    }

    inFile.close();

    inFile.open("purchaseData.txt");

    if (!inFile.is_open())
    {
         std::cout << "ERROR: File does NOT open " <<  std::endl;
        return;
    }

    while ( std::getline(inFile, line))
    {
        int i = 0;
        for (auto c : line)
        {
            if (c == ' ')
            {
                data[i++] = temp; // set slot equal to current character saved in data[0]
                temp = "";
            }
            else
                temp += c; // if theres no space we are still adding characters of that same word
        }
        data[i] = temp; // transferring
        temp = "";
        Purchase *newPurchase = new Purchase(data[0], data[1], data[2], data[3]); // temp ptr variable
        purchases.push_back(newPurchase);
    }

    inFile.close();

    run();
}

void Menu::printCustomers()
{ // print list of all customers --calls print for every index of vector
     std::cout <<  std::left <<  std::setw(12) << "First Name" <<  std::left <<  std::setw(13) << "Last Name" <<  std::left <<  std::setw(15) << "Account Num" <<  std::left <<  std::setw(22) << "Address" <<  std::left <<  std::setw(20) << "City" <<   std::left << std::setw(14) << "State" <<  std::left <<  std::setw(15) << "Zip Code" <<  std::left <<  std::setw(12) << "Phone Num" <<  std::endl;
     std::cout << setfill ('-') <<  std::setw (123) << ""<<  std::endl << setfill(' ');
    for (Customer *customer : customers)
    { // for each customer IN customers -> for each loop ..for every index in customers u make ptr var/object customer that accesses anything within the index--every index is ptr to object(can access vars, methods, anything w -> syntax)
        customer->print();
         std::cout << "\n\t";
         std::cout << "Purchases for: " << customer->getFullName() <<  std::endl;
         std::cout << "\t";
         std::cout <<  std::left <<  std::setw(16) << "Account Num" <<  std::left <<  std::setw(13) << "Item" <<  std::left <<  std::setw(15) << "Date" <<  std::left <<  std::setw(22) << "Amount" <<  std::endl;
         std::cout << "\t";
         std::cout << setfill ('-') <<  std::setw(66) << ""<<  std::endl << setfill(' ');
        printPurchases(customer->getAccountNumber());
         std::cout << "\n\n";
    }
} // PRINT ALL PURCHASE INFORMATION IN COLUMN FORMAT HERE: 
/*
idea: change the initial  std::cout statement: add a header for purchase: << purchase item << date << 
 use a purchase.cpp function called printPurchase() that will get each purchase for each customer, and print it 
use this within the for loop somehow
*/

void Menu::printPurchases( std::string accountNumber) {
    for(auto* purchase : purchases) {
        if (purchase->getAccountNumber() == accountNumber) {
             std::cout << "\t";
            purchase->print();
        }
    }
}

void Menu::printDescendingList()
{ // like quick sort and print
    sort(customers.begin(), customers.end(), [](Customer *a, Customer *b)
         { return a->getFullName() > b->getFullName(); }); // sorting by 2s--swaps a & b
    printCustomers();
}

void Menu::printAscendingList()
{ // sort and print

    sort(customers.begin(), customers.end(), [](Customer *a, Customer *b)
         { return a->getFullName() < b->getFullName(); });
    printCustomers();
}

void Menu::printCustomerInfo()
{ // select a customer and print all info
    int i = 1;
     std::string number;
    // for a customer in customers
    for (auto *customer : customers)
    {
         std::cout << i << ") " << customer->getFullName() <<  std::endl; // customer->getFullName ..ptr customer is getting the fullName
        i++;
    }
CUSTOMERINFO_LABEL: // jumps back here
     std::cout << "customer info> ";

    cin.clear();
     std::getline(cin, number);

    try
    {
        int number_int = stoi(number); // stoi converts input to number

        if (number_int > customers.size())
        { // if number is out of range
             std::cout << "Customer is not found!" <<  std::endl;
            goto CUSTOMERINFO_LABEL;
        }

        customers[number_int - 1]->print(); // prints actual values at # user inputted vector stores at index 0, so use-1.
    }
    catch ( exception e)
    { // exception e-- stores the error. if there was an error with try, automatically goes to catch
         std::cout << "Please enter a number! " <<  std::endl;
        goto CUSTOMERINFO_LABEL;
    }
}

void Menu::printCustomerTotal()
{ // select a customer and print out total for all their purchases
    int i = 1;
     std::string number;
    // for a customer in customers
    for (auto *customer : customers)
    {
         std::cout << i << ") " << customer->getFullName() <<  std::endl; // customer->getFullName ..ptr customer is getting the fullName
        i++;
    }
PURCHASE_LABEL: // jumps back here
     std::cout << "purchase info> ";

    cin.clear();
     std::getline(cin, number);

    try
    {
        int number_int = stoi(number); // stoi converts input to number

        if (number_int > customers.size())
        { // if number is out of range
             std::cout << "Customer is not found!" <<  std::endl;
            goto PURCHASE_LABEL;
        }
        // customer counts as the index
        auto *customer = customers[number_int - 1];
        double sum = 0; // for every purch in purch/for every line of code purch is like index
         std::cout <<  std::left <<  std::setw(16) << "Account Num" <<  std::left <<  std::setw(13) << "Item" <<  std::left <<  std::setw(15) << "Date" <<  std::left <<  std::setw(22) << "Amount" <<  std::endl;
         std::cout << setfill ('-') <<  std::setw(66) << ""<<  std::endl << setfill(' ');
        for (auto *purchase : purchases)
        {
            if (purchase->getAccountNumber() == customer->getAccountNumber())
            {
                auto amount = purchase->getAmount();
                purchase->print();
                sum += stod(amount);
            }
        }

         std::cout << "\n" << customer->getFullName() << "'s total purchase is " << sum <<  std::endl;

    }
    catch ( exception e)
    { // exception e-- stores the error. if there was an error with try, automatically goes to catch
         std::cout << "Please enter a number! " <<  std::endl;
        goto PURCHASE_LABEL; 
    }
}

void Menu::addNewCustomer()
{
    srand(time(NULL));
    // when creating an account number...generate it to be a random  std::string of numbers with a length of ten.
     std::string data[7];
     std::cout << "Enter customer's first name:\n";
     std::cout << "add customer> ";

     std::getline(cin, data[0]);
    // create a new customer in vector of customers

     std::cout << "Enter customer's last name:\n";
     std::cout << "add customer> ";

     std::getline(cin, data[1]);

     std::cout << "Enter customer's address:\n";
     std::cout << "add customer> ";

     std::getline(cin, data[2]);

     std::cout << "Enter customer's city:\n";
     std::cout << "add customer> ";

     std::getline(cin, data[3]);

     std::cout << "Enter customer's state:\n";
     std::cout << "add customer> ";

     std::getline(cin, data[4]);

ZIPPY:
     std::cout << "Enter customer's zip code:\n";
     std::cout << "add customer> ";

     std::getline(cin, data[5]);

    if (data[5].size() != 5)
    {
         std::cout << "Error: must be 5 digits!" <<  std::endl;
        goto ZIPPY;
    }

    for (auto c : data[5])
    {
        if (c > '9' || c < '0')
        {
             std::cout << "Error: must be 5 digits!" <<  std::endl;
            goto ZIPPY;
        }
    }

NUMMY:
     std::cout << "Enter customer's phone number:\n";
     std::cout << "add customer> ";

     std::getline(cin, data[6]);

    // set the name to name of custy, set account number random, streetName, city, state,

    if (data[6].size() != 10)
    {
         std::cout << "Error: must be 10 digits!" <<  std::endl;
        goto NUMMY;
    }

    for (auto c : data[6])
    {
        if (c > '9' || c < '0')
        {
             std::cout << "Error: must be 10 digits!" <<  std::endl;
            goto NUMMY;
        }
    }

     std::string accountNumber = "";

    for (int i = 0; i < 10; i++)
    {
        accountNumber += (char)(rand() % 10) + 48;
    }

    Customer *newCustomer = new Customer(data[0], data[1], accountNumber, data[2], data[3], data[4], data[5], data[6]);

    customers.push_back(newCustomer);
}

void Menu::addNewCustomers()
{
     std::string input;
     std::cout << "do you want to add another customer(y/n): ";

     std::getline(cin, input);

    if (input == "y")
    {
        addNewCustomer();
        addNewCustomers();
    }
    else
    {
        return;
    }
}

void Menu::updateCustomerInfo()
{
    int i = 1;
     std::string number;
    // for a customer in customers
    for (auto *customer : customers)
    {
         std::cout << i << ") " << customer->getFullName() <<  std::endl; // customer->getFullName ..ptr customer is getting the fullName
        i++;
    }
UPDATE: // jumps back here
     std::cout << "update customer> ";

    cin.clear();
     std::getline(cin, number);

    try
    {
        int number_int = stoi(number); // stoi converts input to number

        if (number_int > customers.size())
        { // if number is out of range
             std::cout << "Customer is not found!" <<  std::endl;
            goto UPDATE; 
        }

        auto *customer = customers[number_int - 1];

         std::string data[7];
         std::cout << "enter the new first name(enter k to keep the same)\n";
         std::cout << "update customer> ";
         std::getline(cin, data[0]);

         std::cout << "enter the new last name(enter k to keep the same)\n";
         std::cout << "update customer> ";
         std::getline(cin, data[1]);

         std::cout << "enter the new address(enter k to keep the same)\n";
         std::cout << "update customer> ";
         std::getline(cin, data[2]);

         std::cout << "enter the city(enter k to keep the same)\n";
         std::cout << "update customer> ";
         std::getline(cin, data[3]);

         std::cout << "enter the state(enter k to keep the same)\n";
         std::cout << "update customer> ";
         std::getline(cin, data[4]);

         std::cout << "enter the zip code(enter k to keep the same)\n";
         std::cout << "update customer> ";
         std::getline(cin, data[5]);

         std::cout << "enter the phone number(enter k to keep the same)\n";
         std::cout << "update customer> ";
         std::getline(cin, data[6]);

        if (data[0] != "k")
        {
            customer->setFirstName(data[0]);
        }

        if (data[1] != "k")
        {
            customer->setLastName(data[1]);
        }

        if (data[2] != "k")
        {
            customer->setAddress(data[2]);
        }

        if (data[3] != "k")
        {
            customer->setCity(data[3]);
        }

        if (data[4] != "k")
        {
            customer->setState(data[4]);
        }

        if (data[5] != "k")
        {
            customer->setZipCode(data[5]);
        }

        if (data[6] != "k")
        {
            customer->setPhoneNumber(data[6]);
        }
    }
    catch ( exception e)
    { // exception e-- stores the error. if there was an error with try, automatically goes to catch
         std::cout << "Please enter a number! " <<  std::endl;
        goto UPDATE;
    }
}

void Menu::deleteCustomerInfo()
{
    int i = 1;
     std::string number;
    // for a customer in customers
    for (auto *customer : customers)
    {
         std::cout << i << ") " << customer->getFullName() <<  std::endl; // customer->getFullName ..ptr customer is getting the fullName
        i++;
    }
DELETE_LABEL: // jumps back here
     std::cout << "delete customer> ";

    cin.clear();
     std::getline(cin, number);

    try
    {
        int number_int = stoi(number); // stoi converts input to number

        if (number_int > customers.size())
        { // if number is out of range
             std::cout << "Customer is not found!" <<  std::endl;
            goto DELETE_LABEL;
        }

        auto *customer = customers[number_int - 1];

        delete customer;
        customers.erase(customers.begin() + number_int - 1);
         std::cout << "customer deleted" <<  std::endl;
    }
    catch ( exception e)
    { // exception e-- stores the error. if there was an error with try, automatically goes to catch
         std::cout << "Please enter a number! " <<  std::endl;
        goto DELETE_LABEL;
    }
}

void Menu::addNewPurchase()
{
    int i = 1;
     std::string number;
    // for a customer in customers
    for (auto *customer : customers)
    {
         std::cout << i << ") " << customer->getFullName() <<  std::endl; // customer->getFullName ..ptr customer is getting the fullName
        i++;
    }
NEW_PURCHASE_LABEL: // jumps back here
     std::cout << "new purchase> ";

    cin.clear();
     std::getline(cin, number);

    try
    {
        int number_int = stoi(number); // stoi converts input to number

        if (number_int > customers.size())
        { // if number is out of range
             std::cout << "Customer is not found!" <<  std::endl;
            goto NEW_PURCHASE_LABEL;
        }

        auto *customer = customers[number_int - 1];

         std::string data[3];
         std::cout << "Enter purchase item name:\n";
         std::cout << "item name> ";

         std::getline(cin, data[0]);

         std::cout << "Enter purchase date:\n";
         std::cout << "purchase date> ";

         std::getline(cin, data[1]);

         std::cout << "Enter purchase price:\n";
         std::cout << "purchase price> ";

         std::getline(cin, data[2]);

        Purchase *newPurchase = new Purchase(customer->getAccountNumber(), data[0], data[1], data[2]);
        purchases.push_back(newPurchase);
    }
    catch ( exception e)
    { // exception e-- stores the error. if there was an error with try, automatically goes to catch
         std::cout << "Please enter a number! " <<  std::endl;
        goto NEW_PURCHASE_LABEL;
    }
}

void Menu::save() {
     std::ofstream customerOutputFile("customerData.txt");
     std::ofstream purchaseOutputFile("purchaseData.txt");

    for (auto* customer : customers) {
        customerOutputFile << customer->getFirstName() << " " << customer->getLastName() << " " << customer->getAccountNumber() << " " << customer->getAddress() << " " << customer->getCity() << " " << customer->getState() << " " << customer->getZipCode() << " " << customer->getPhoneNumber() <<  std::endl;
    }

    for (auto* purchase : purchases) {
        purchaseOutputFile << purchase->getAccountNumber() << " " << purchase->getItem() << " " << purchase->getDate() << " " << purchase->getAmount() <<  std::endl;
    }
}

void Menu::export_data() {
     std::string custy, purchy;
     std::cout << "Enter the name of the customer data file: " <<  std::endl;
     std::getline(cin, custy);

     std::cout << "Enter the name of the purchase data file: " <<  std::endl;
     std::getline(cin, purchy);

     std::ofstream customerOutputFile(custy);
     std::ofstream purchaseOutputFile(purchy);

    for (auto* customer : customers) {
        customerOutputFile << customer->getFirstName() << " " << customer->getLastName() << " " << customer->getAccountNumber() << " " << customer->getAddress() << " " << customer->getCity() << " " << customer->getState() << " " << customer->getZipCode() << " " << customer->getPhoneNumber() <<  std::endl;
    }

    for (auto* purchase : purchases) {
        purchaseOutputFile << purchase->getAccountNumber() << " " << purchase->getItem() << " " << purchase->getDate() << " " << purchase->getAmount() <<  std::endl;
    }
}

void Menu::addNewPurchases()
{
     std::string input;
     std::cout << "do you want to add another purchase(y/n): ";

     std::getline(cin, input);

    if (input == "y")
    {
        addNewPurchase();
        addNewPurchases();
    }
    else
    {
        return;
    }
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
        addNewCustomer();
        break;
    case 8:
        addNewCustomers();
        break;
    case 9:
        updateCustomerInfo();
        break;
    case 10:
        deleteCustomerInfo();
        break;
    case 11:
        addNewPurchase();
        break;
    case 12:
        addNewPurchases();
        break;
    case 13:
        save();
        break;
    case 14:
        export_data();
        break;
    case 15:
         std::cout << "Thank you for visiting Blossom Botique! We hope to see you again!\n";
         std::cout << R"(                    _
                  _(_)_                          wWWWw   _
      @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_
     @@()@@ wWWWw  (_)\    (___)   _(_)_  @@()@@   Y  (_)@(_)
      @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \|/   (_)\
       /      Y       \|    \|/    /(_)    \|      |/      |
    \ |     \ |/       | / \ | /  \|/       |/    \|      \|/
    \\|//   \\|///  \\\|//\\\|/// \|///  \\\|//  \\|//  \\\|// 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
)" <<  std::endl;
        exit(0);
        break;
    

    default:
         std::cout << "Invalid option!" <<  std::endl;
    }
}
