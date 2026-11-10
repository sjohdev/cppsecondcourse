#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

/*
KEY POINTS: 
- Pass simple types (int, double) by value for clarity and safety
- Pass large objects (strings, vectors) by const reference when read-only access is needed
- Use references when functions need to modify the original data

*/

// Function using const reference for efficiency (no copying, no modification)
void printEmployeeReport(const std::string& name, const std::vector<double>& scores) {
    std::cout << "Performance Report for: " << name << std::endl;
    std::cout << "Scores: ";
    for (double score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
}

// Function using reference to modify vector elements
void normalizeScores(std::vector<double>& scores) {
    if (scores.empty()) return;
    // Find maximum score
    double maxScore = scores[0];
    for (double score : scores) {
        if (score > maxScore) {
            maxScore = score;
        }
    }
    // Normalize all scores to percentage of maximum
    for (double& score : scores) {
        score = (score / maxScore) * 100.0;
    }
}

int main() {
    std::string employeeName = "Bob Wilson";
    std::vector<double> performanceScores = {85.0, 92.0, 78.0, 88.0, 95.0};
    
    // Test const reference function
    printEmployeeReport(employeeName, performanceScores);
    
    // Test vector modification by reference
    std::cout << "\nOriginal scores: ";
    for (double score : performanceScores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    normalizeScores(performanceScores);
    std::cout << "Normalized scores: " << std::fixed << std::setprecision(1);
    for (double score : performanceScores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    return 0;
}

