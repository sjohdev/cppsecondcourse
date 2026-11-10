#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159
#endif

/*
KEY POINTS: 
- Function overloading allows multiple functions with the same name but different parameter signatures
- The compiler automatically selects the correct overloaded function based on parameter types

Common mistakes to avoid: 
- Creating ambiguous function overloads that the compiler cannot distinguish
- Overloading functions with signatures that are too similar (causing compilation errors)
*/

double calcArea(double radius) {
    return M_PI * radius * radius;
}

double calcArea(double length, double height) {
    return length * height;
}

double calcSquareArea(double length) {
    return length * length;
}

// This function creates ambiguity with calcArea of circle!
// and will result in compilation error: 
/*double calcArea(double length) {
    return length * length;
}*/

int main() {
    std::cout << "Circle (radius 5): " << calcArea(5.0) << std::endl;
    std::cout << "square (length 5): " << calcSquareArea(5.0) << std::endl;
    return 0;
}
