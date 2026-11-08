#include <iostream>
#include <sstream>
#include <string>

/*
KEY POINTS: 
- Manipulate strings using std::string for flexible, efficient operations
- Integrate C++ standard library functions to streamline coding
- Emphasize code readability and maintainability in function design
*/

void extractWords(std::string str) {
    std::istringstream sStream(str);
    std::string word;
    
    std::cout << "Original text: " << str << std::endl;
    std::cout << "Words in text: " << std::endl;
    // Loop until reaching end of string or read failure
    sStream >> word;
    while (sStream) {
        if (word[word.length()-1] == '.' || word[word.length()-1] == ',') {
            word.erase(word.length()-1, 1);
        }
        std::cout << word << std::endl;
        sStream >> word;
    }
}

int main() {
    // Separate words from a string
    std::string mystring = "This is a test. Yes I am kidding, or no I'm not.";
    extractWords(mystring);
    return 0;
}
