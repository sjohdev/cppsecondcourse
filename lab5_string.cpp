#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

int main() {
    std::string message = "WelcOme to the world of C++ programming!";
    std::cout << "Original message: " << message << std::endl;
    // Extract the first word using substr()
    size_t first_space = message.find(' ');
    if (first_space != std::string::npos) {
        std::string first_word = message.substr(0, first_space);
        std::cout << "First word: " << first_word << std::endl;
    }
    // Your code here: Find and extract the last word using rfind() and substr()
    size_t last_space = message.rfind(' ');
    if (last_space != std::string::npos) {
        std::string last_word = message.substr(last_space, message.length()-1);
        std::cout << "Last word: " << last_word << std::endl;
    }
    
    // Your code here: Count how many times the letter 'o' appears in the message
    int ascii = 0;
    bool isO = false;
    int ocounter = 0;
    for (char letter : message) {
        ascii = static_cast<int>(letter);
        isO = (ascii == 79 || ascii == 111); //ascii codes for O and o are 79 and 111
        if (isO) {
            ocounter++;
        }
    }
    std::cout << "The letter 'o' occurs #" << ocounter << " times." << std::endl;
    
    // Part 2: Find and replace in string
    std::string text = "Hello world! The world is intense right now!";
    std::cout << "Original: " << text << std::endl;
    
    // Replace first "world" with "universe": 
    std::string_view wordstr = "world"; // string_view is a faster read-only version of string
    size_t pos = text.find(wordstr);
    if (pos != std::string::npos) {
        // replace(starting_pos, nbrofCharsToreplace, substringToReplaceWIth)
        text.replace(pos, wordstr.length(), "universe"); 
        std::cout << "After first replacement: " << text << std::endl;
    }
    // Replace second "world" with "universe": 
    size_t pos2 = text.find(wordstr, pos + 1);
    if (pos2 != std::string::npos) {
        // replace(starting_pos, nbrofCharsToreplace, substringToReplaceWIth)
        text.replace(pos2, wordstr.length(), "universe"); 
        std::cout << "After second replacement: " << text << std::endl;
    }
    
    // Remove all exclamation marks: 
    wordstr = "!";
    size_t offset = 0;
    pos = text.find(wordstr, offset);
    while (pos != std::string::npos) {
        // wordstr found in text: erase
        text.erase(pos, wordstr.length());        
        offset = pos + 1;
        pos = text.find(wordstr, offset);
    }
    std::cout << "After erasing all '!': " << text << std::endl;
    
    // Convert whole text to uppercase: 
    for (int i = 0; i < text.length(); i++) {
        text[i] = std::toupper(text[i]);
    }
    std::cout << "Text in UPPERCASE: " << text << std::endl;
    return 0;
}
