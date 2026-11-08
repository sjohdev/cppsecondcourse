#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>

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
    
    
    // Part 3: C-style vs CPP strings:
    // C-style string operations
    const char* c_str = "Hello";
    char c_buffer[20];
    strcpy(c_buffer, c_str);
    strcat(c_buffer,"World");
    std::cout << "C-style result: " << c_buffer << std::endl;
    std::cout << "C-style length: " << strlen(c_buffer) << std::endl;
    // std::string operations
    std::string cpp_str = "Hello";
    cpp_str += "World";
    std::cout << "std::string result: " << cpp_str << std::endl;
    std::cout << "std::string length: " << cpp_str.length() << std::endl;
    
    // Try to access character at index 15 in both strings
    //std::cout << "C-style string at index 15: " << c_buffer[15] << std::endl; // Undefined behaviour
    //std::cout << "std::string at index 15: " << cpp_str[15] << std::endl; // crash, much better reliability
    
    /*// Show what happens when you try to concatenate
     a very long string to c_buffer (comment out to avoid crash) */
     //strcat(c_buffer, " This is a very long string that will cause overflow");
     
     
    // PArt 4: Text analysis
    std::string text2 = "The Quick Brown Fox Jumps Over The Lazy Dog";
    std::cout << "Analyzing text: " << text2 << std::endl;
    // Count words
    int wordCount = 1 + std::count(text2.begin(), text2.end(), ' '); // std::count is case-insenitive by default
    std::cout << "Number of words: " << wordCount << std::endl;
    // Count vowels: 
    std::string vowels = "aeiouy";
    int tempCount = 0;
    int totalVowels = 0;
    for (char letter : vowels) {
        tempCount = std::count(text2.begin(), text2.end(), letter);
        std::cout << "Letter: " << letter << ": " << tempCount << std::endl;
        totalVowels += tempCount;
    }
    std::cout << "Number of vowels in text: " << totalVowels << std::endl;
    
    // Find longest word in string: 
    // Extract all words: 
    int wordLength;
    std::string_view symbol = " ";
    int maxWordLength = 0;
    int maxWordPos = 0;
    int wordStart = 0;
    int wordEnd;
    pos = text2.find(symbol, wordStart);
    while (pos != std::string::npos) {
        wordEnd = pos - 1;
        // new word found: count length and add to memory
        wordLength = 1 + wordEnd - wordStart;
        if (wordLength > maxWordLength) {
            maxWordLength = wordLength;
            maxWordPos = wordStart;
        }
        wordStart = 2 + wordEnd;  // assumes single whitespace between words
        pos = text2.find(symbol, wordStart);
    }
    std::string maxWord = text2.substr(maxWordPos, maxWordLength);
    std::cout << "Longest word in text was '" << maxWord << "' (" << maxWordLength << " letters)" << std::endl;
    
    return 0;
}

