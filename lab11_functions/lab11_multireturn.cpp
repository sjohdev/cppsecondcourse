#include <iostream>
#include <string>
#include <vector>

/*
KEY POINTS: 
- Return structs or pairs when functions need to provide multiple related values
- Always validate function inputs and handle edge cases
- Function names should clearly describe what the function does
*/

// Struct to return multiple employee statistics
struct EmployeeStats {
    double averageScore;
    double highestScore;
    double lowestScore;
    int totalEvaluations;
};

// Function returning multiple values using a struct
EmployeeStats calculateEmployeeStats(const std::vector<double>& scores) {
    if (scores.empty()) {
        return {0.0, 0.0, 0.0, 0};
    }
    double sum = 0.0;
    double highest = scores[0];
    double lowest = scores[0];
    for (double score : scores) {
        sum += score;
        if (score > highest) highest = score;
        if (score < lowest) lowest = score;
    }
    return {
        sum / scores.size(),    // average
        highest,                // highest
        lowest,                 // lowest
        static_cast<int>(scores.size()) // total count
    };
}

bool checkEmployeeData(const int& employeeId, std::string& name, double& salary) {
    // Validate input data
    if (employeeId <= 0 || name.empty() || salary < 0) {
        return false;
    }
    // Process the data (example: format name and adjust salary)
    // Convert name to title case (simplified)
    if (!name.empty()) {
        name[0] = std::toupper(name[0]);
    }
    // Ensure minimum salary
    if (salary < 30000.0) {
        salary = 30000.0;
    }
    return true;
}

int main() {
    // Test multiple return values
    std::vector<double> employeeScores = {87.5, 92.0, 78.5, 95.0, 84.0, 89.5};
    EmployeeStats stats = calculateEmployeeStats(employeeScores);
    return 0;
}
