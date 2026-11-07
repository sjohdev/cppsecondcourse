#include <iostream>
#include <array>
#include <stdexcept>
#include <algorithm>

void printCarray(auto *array_ptr, const int length) {
    std::cout << "[ ";
    for (int i = 0; i < length; i++) {
        std::cout << array_ptr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void printStdarray(auto& array) {
    std::cout << "[ ";
    for (auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // Initialize C-style array
    int c_array[20] = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76, 3, 8, 6, 1, 4, 3, 9, 5, 45, 0};
    // Initialize std::array
    std::array<int, 20> std_array = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76, 3, 8, 6, 1, 4, 3, 9, 5, 45, 0};
    
    /* Bubble sort on the C-style array: swap places between adjacent pairs 
    if they are in wrong order. Continue until all pairs are ordered */
    const int c_length = sizeof(c_array)/sizeof(c_array[0]);
    bool isOutOfOrder = false;
    int temp = 0;
    for (int i = 0; i < c_length - 1; i++) {
        for (int j = 0; j < c_length - 1; j++) {
            temp = c_array[j];
            if (c_array[j] > c_array[j+1]) {
                isOutOfOrder = true;
                c_array[j] = c_array[j+1];
                c_array[j+1] = temp;
            }
        }
        if (isOutOfOrder) {
            // reset and enter nex loop
            isOutOfOrder = false;
        } else {
            // array is sorted, break
            break;
        }
    }
    // Display sorted C-style array
    std::cout << "C-style array after sorting: " << std::endl;
    printCarray(c_array, c_length);
    
    // Sort std::array using standard library
    std::sort(std_array.begin(), std_array.end());
    
    // Display sorted std::array
    std::cout << "std::array after sorting: " << std::endl;
    printStdarray(std_array);
    return 0;
}
