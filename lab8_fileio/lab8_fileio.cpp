#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <filesystem>

/*
KEY POINTS: 
- Always check if files open successfully using is_open() or boolean conversion
- Use std::getline() to read entire lines from text files
- std::ios::app flag appends to existing files instead of overwriting
- C++17 std::filesystem::exists() safely checks file presence before operations
- Close files explicitly or let destructors handle it automatically

Common mistakes to avoid: 
- Forgetting to check file open status before using file operations
- Not including proper error messages when file operations fail
- Using the wrong file path or assuming files exist in specific locations
- Mixing text and binary file operations without understanding the differences  
*/

int main() {
    // Assumes file "products.txt" contains the following lines:
    // Laptop
    // Mouse
    // Keyboard
    // monitor
    std::string productName;
    std::ifstream inputFile("products.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    int count = 0;
    std::cout << "Product Inventory: " << std::endl;
    while (std::getline(inputFile, productName)) {
        count++;
        std::cout << count << ". " << productName << std::endl;
    }
    inputFile.close();
    std::cout << "Total: " << count << " products." << std::endl;
    
    
    // Part 2: Write to file
    std::ofstream reportFile("sales_report.txt", std::ios::app); // ios::app appends new data instead of overwriting
    if (!reportFile) {
        std::cerr << "Error: could not create sales report file" << std::endl;
        return 1;
    }
    // Write report header
    reportFile << "DAILY SALES REPORT" << std::endl;
    reportFile << "===================" << std::endl;
    reportFile << std::left << std::setw(15) << "Product:"
        << std::setw(10) << "Quantity:"
        << std::setw(10) << "Price:" << std::endl;
    // Sample sales data
    reportFile << std::left << std::setw(15) << "Laptop"
        << std::setw(10) << "5"
        << "$" << std::fixed << std::setprecision(2) << 999.99 << std::endl;
    reportFile << std::left << std::setw(15) << "Mouse"
        << std::setw(10) << "12"
        << "$" << std::fixed << std::setprecision(2) << 29.99 << std::endl;
    
    
    // Part 3: Full CSV-file parsing
    const std::string inFileName = "inventory.txt";
    const std::string outFileName = "summary.txt";
    // Check if input file exists using C++17 filesystem
    if (!std::filesystem::exists(inFileName)) {
        // Create inventory file with csv-format
        std::cout << "Creating sample inventory file..." <<std::endl;
        std::ofstream createdFile(inFileName);
        createdFile << "Widget A,25,15.506" << std::endl;
        createdFile << "Widget B,40,22.00" << std::endl;
        createdFile << "Widget V,15,8.752" << std::endl;
        createdFile.close();
    }
    // Open inventory data
    std::ifstream inFile(inFileName);
    if (!inFile.is_open()) {
        std::cerr << "Error opening inventory file!" << std::endl;
        return 1;
    }
    // Process and summarize inventory file content
    std::string csvLine;
    int totalItems = 0;
    double totalValue = 0.0;
    std::ofstream outFile(outFileName);
    if (!outFile) {
        std::cerr << "Error creating summary file!" << std::endl;
        return 1;
    }
    std::string name;
    int quantity;
    double price;
    size_t firstComma, secondComma;
    bool isValidLine;
    while (std::getline(inFile, csvLine)) {
        // parse each inventory.txt csv-row
        firstComma = csvLine.find(',');
        secondComma = csvLine.find(',', firstComma + 1);
        isValidLine = (firstComma != std::string::npos) && (secondComma != std::string::npos);
        if (isValidLine) {
            name = csvLine.substr(0,firstComma);
            try {
                quantity = std::stoi(csvLine.substr(1 + firstComma, -1 + secondComma - firstComma));
                price = std::stod(csvLine.substr(1 + secondComma));
            } catch (const std::exception& e) {
                std::cerr << "Error parsing csv-line from file. Line = " << csvLine << std::endl;
                continue;
            }
            totalItems += quantity;
            totalValue += quantity * price;
            outFile << "Product: " << name << ", # in stock: " << quantity << ", Value: $"
                << std::fixed << std::setprecision(2)
                << quantity * price << std::endl;
        }
    }
    inFile.close();
    outFile << std::endl << "Total items: " << totalItems << std::endl;
    outFile << std::endl << "Total value: $" << totalValue << std::endl;
    outFile.close();
    std::cout << "Inventory summary CompleTEH" << std::endl;
    return 0;
}



















