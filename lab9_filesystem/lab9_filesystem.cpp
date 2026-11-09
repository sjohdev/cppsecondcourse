#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void getHeadersFromFile(std::string fullFilePath) {
    // Open sourcefile
    int lineCount = 0;
    std::string cppLine;
    std::string headerName;
    std::ifstream sourceFile(fullFilePath);
    size_t pos;
    bool isIncludeLine = false;
    if (sourceFile.is_open()) {
        std::cout << "\nIncluded headers in '" << fullFilePath << "':" << std::endl;
        while (std::getline(sourceFile, cppLine)) {
            //std::cout << "Line #" << ++lineCount << ": " << cppLine << std::endl;
            pos = cppLine.find("#include");
            isIncludeLine = (pos != std::string::npos);
            if (isIncludeLine) {
                // #include line found: find header file name
                headerName = cppLine.substr(9 + pos);
                std::cout << headerName << std::endl;
            }
        }
        sourceFile.close();
    } else {
        std::cerr << "Error: could not open file" << std::endl;
    }
}

int main() {
    // get all filenames in directory "source"
    std::string dirName = "source";
    std::string fileName;
    std::filesystem::path sourcePath = dirName;
    std::filesystem::path filePath;
    bool isCppFile = false;
    if (std::filesystem::exists(sourcePath) && std::filesystem::is_directory(sourcePath)) {
        // for each .cpp file in folder, list all included header files:
        std::cout << "Files in directory '" << dirName << "': " << std::endl;
        for (const auto& dirEntry : std::filesystem::directory_iterator(sourcePath)) {
            // Display filename
            std::cout << "- " << dirEntry.path().filename().string() << std::endl;
            
            // Check if file is .cpp source file
            fileName = dirEntry.path().filename().string();
            isCppFile = (fileName.find(".cpp") != std::string::npos);
            if (isCppFile) {
                // .cpp source file found: read and find all #include statements:
                getHeadersFromFile(dirEntry.path().string());
            }
        }
    } else {
        std::cerr << "Error: Directory not found." << std::endl;
    }
    return 0;
}

