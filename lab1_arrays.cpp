#include <iostream>
#include <array>
#include <stdexcept>

int main() {
    // Initialize C-style array
    int c_temps[10] = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76};
    // Initialize std::array
    std::array<int, 10> std_temps = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76};
    
    std::cout << "Temp-data loaded successfully" << std::endl;
    std::cout << "5th reading C-style: " << c_temps[4] << std::endl;
    std::cout << "5th reading std::array: " << std_temps[4] << std::endl;
    std::cout << "10th reading C-style: " << c_temps[9] << std::endl;
    std::cout << "10th reading std::array: " << std_temps[9] << std::endl;
    
    // Modify 3rd reading to 85
    c_temps[2] = 85;
    std_temps[2] = 85;
    // Modify 8th reading to 90
    c_temps[7] = 90;
    std_temps[7] = 90;
    
    // Display all C-style temperatures
    std::cout << "C-style temperatures: " << std::endl;
    std::cout << "{ ";
    for (int number : c_temps) {
        std::cout << number << " ";
    }
    std::cout << "}" << std::endl;
    
    // Display all std::array temperatures
    std::cout << "std::array temperatures: " << std::endl;
    std::cout << "{ ";
    for (int& nr : std_temps) { // reference instead of variable to avoid copy?
        std::cout << nr << " ";
    }
    std::cout << "}" << std::endl;
    
    
    
    // Test out of bounds access: 
    std::cout << "Out of bounds test: " << std::endl;
    std::cout << "C-style[10]: " << c_temps[10] << " (unsafe)" << std::endl;
    try {
        //std::cout << "std::array[10]: " << std_temps[10] << std::endl; // will crash the program
        std::cout << "std::array.at(10): " << std_temps.at(10) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Out-of-Bounds exception caught: " << e.what() << std::endl;
    }
    // std::array safety advantages:
    // 1. Bounds checking with .at() prevents buffer overflows
    // 2. Exception handling allows graceful error recovery
    // 3. STL compatibility enables use with standard algorithms
    return 0;
}
