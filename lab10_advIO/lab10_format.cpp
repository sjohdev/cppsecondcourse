#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <format>

// Note: std::format requires C++20. If unavailable, we'll use traditional formatting
// #include <format> // Uncomment if available
struct Product {
    std::string name;
    double price;
    int quantity;
    double total() const {
        return price * quantity; 
    }
};

int main() {
    double grandTotal = 0.0;
    std::vector<Product> productVector = {
        {"Laptop", 999.99, 2},
        {"Mouse", 29.5, 5},
        {"Keyboard", 89.99, 3}
    };
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "INVOICE SUMMARY" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    
    for (const auto& product : productVector) {
        std::cout << std::format("{}: ${:.2f} (#{} in stock)\n", product.name, product.price, product.quantity);
        grandTotal += product.total();
    }
    
    // Modern formatting:     
    std::cout << std::format("\nTax (8.5%): ${:.2f}\n", grandTotal * 0.085);
    std::cout << std::format("Final Total: ${:.2f}\n", grandTotal * 1.085);
    return 0;
}
