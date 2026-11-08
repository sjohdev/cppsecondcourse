#include <iostream>
#include <limits>
#include <string>
#include <iomanip>

/*
KEY POINTS:
- std::cin.clear() resets stream error flags after invalid input
- std::cin.ignore() removes unwanted characters from the input buffer
- Stream manipulators like std::setw() and std::setprecision() control output formatting
- Input validation loops prevent program crashes and ensure data quality

Common mistakes to avoid: 
- Forgetting to clear the stream state after invalid input
- Not using std::cin.ignore() to clear the input buffer
- Mixing std::cin >> and std::getline() without proper buffer management
- Setting precision without using std::fixed for consistent decimal places
*/

void getUserInput(auto& dataVar, auto minVal, auto maxVal) {
    // Check for inputstream failure and invalid user input at the same time:
    // IMPORTANT: the parenthesis around the !() statement matters
    while (!(std::cin >> dataVar) || dataVar < minVal || dataVar > maxVal) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again: ";
    }
}

int main() {
    int age = 0;
    std::cout << "Enter customer age (0-110): ";
    getUserInput(age, 0, 110);
    std::cout << "Customer age: " << age << std::endl;
    
    // Part 2: Formatting
    std::string name = "John Smith";
    int customerID = 1234;
    double balance = 456.789;
    
    // Get user info: 
    // Clear cin error flags
    std::cin.clear(); 
    // ignore previous leftover-inputs
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Prompt user for data
    std::cout << "Enter customer name: ";
    std::getline(std::cin, name);
    std::cout << "Enter customer ID: ";
    getUserInput(customerID, 1000, 9999);
    std::cout << "Enter account balance: ";
    getUserInput(balance, 0, 999999);

    
    //Display output
    // Header
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ') << "CUSTOMER INFORMATION" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    // Data display
    std::cout << std::setfill(' ') << std::left;
    std::cout << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::setw(15) << "Customer ID:" << customerID << std::endl;
    std::cout << std::setw(15) << "Balance:" << std::fixed << std::setprecision(2) << "$" << balance << std::endl;

    return 0;
}
