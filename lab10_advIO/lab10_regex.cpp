#include <iostream>
#include <string>
#include <format>
#include <regex>

/*
KEY POINTS: 
- std::cin.clear() resets error flags, std::cin.ignore() clears the input buffer
- Regular expressions provide powerful pattern matching for input validation
- Raw string literals R"(...)" make regex patterns more readable
- Modern formatting features improve output quality and code maintainability
- Comprehensive error handling prevents crashes and guides users

Common mistakes to avoid: 
- Forgetting to clear both error flags AND the input buffer after invalid input
- Using complex regex patterns without testing edge cases thoroughly
- Not providing clear error messages that guide users toward correct input format
- Mixing std::cin >> and std::getline() without proper buffer management
*/

bool validateEmail(const std::string& email) {
    // Basic email pattern: username@domain.extension
    std::regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, email_pattern);
}

bool validatePhone(const std::string& phone) {
    // US phone pattern: (123) 456-7890 or 123-456-7890
    std::regex phone_pattern(R"((\d3\d{3}\s?|\d{3}[-.]?)\d{3}[-.]?\d{4})");
    return std::regex_match(phone, phone_pattern);
}

bool validateName(const std::string& name) {
    // Name should contain only letters and spaces, at least 2 characters
    std::regex name_pattern(R"([a-zA-Z\s]{2,})");
    return std::regex_match(name, name_pattern);
}

// ZIP code validation function:
bool validateZip(const std::string& zip) {
    // ZIP code pattern: 12345 or 12345-6789
    std::regex zip_pattern(R"(\d{5}(-\d{4})?)");
    return std::regex_match(zip, zip_pattern);
}

int main() {
    std::string name;
    
    //Validate name: 
    bool isInvalidName = false;
    do {
        std::cout << "Enter full name: ";
        std::getline(std::cin, name);
        isInvalidName = validateName(name) == false;
        if (isInvalidName) {
            std::cerr << "Error: Name must contain only letters and spaces (min 2 chars)." << std::endl;   
        }
    } while (isInvalidName);
    
    // Print name: 
    std::cout << "\nGreat Success!" << std::endl;
    std::cout << std::string(40,'=') << std::endl;
    std::cout << std::format("Name: {}\n", name);
    std::cout << std::string(40,'=') << std::endl;
    return 0;
}

