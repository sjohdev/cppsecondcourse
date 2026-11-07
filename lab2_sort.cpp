#include <iostream>
#include <array>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <iomanip>  // For formatting output
#include <chrono> // For measuring execution time

float mediancarray(auto *array_ptr, const int length) {
    float c_median = 0;
    int middleIndex = (length / 2) - 1;
    if ((length % 2) == 0) {
        // Even number of elements in array: median = average of two middle-most elements
        c_median = static_cast<float>(array_ptr[middleIndex] + array_ptr[middleIndex + 1]) / 2;
    }else {
        // Odd number of elements in array: median = middle
        c_median = static_cast<float>(array_ptr[middleIndex + 1]);
    }
    return c_median;
}

float medianstdarray(auto& std_array) {
    float std_median = 0;
    int middleIndex = (std_array.size() / 2) - 1;
    if ((std_array.size() % 2) == 0) {
        // Even number of elements in array: median = average of two middle-most elements
        std_median = static_cast<float>(std_array[middleIndex] + std_array[middleIndex + 1]) / 2;
    }else {
        // Odd number of elements in array: median = middle
        std_median = static_cast<float>(std_array[middleIndex + 1]);
    }
    return std_median;
}

float averagecarray(int *array_ptr, const int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array_ptr[i];
    }
    return static_cast<float>(sum) / length;
}

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

void bubblesortcarray(int *array_ptr, const int length) {
    bool isOutOfOrder = false;
    int temp = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1; j++) {
            temp = array_ptr[j];
            if (array_ptr[j] > array_ptr[j+1]) {
                isOutOfOrder = true;
                array_ptr[j] = array_ptr[j+1];
                array_ptr[j+1] = temp;
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
}

int main() {
    // Initialize C-style array
    int c_array[20] = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76, 3, 8, 6, 1, 4, 3, 9, 5, 45, 0};
    // Initialize std::array
    std::array<int, 20> std_array = {72, 75, 68, 80, 77, 73, 69, 82, 78, 76, 3, 8, 6, 1, 4, 3, 9, 5, 45, 0};
    
    /* Bubble sort on the C-style array: swap places between adjacent pairs 
    if they are in wrong order. Continue until all pairs are ordered */
    const int c_length = sizeof(c_array)/sizeof(c_array[0]);
    auto start = std::chrono::high_resolution_clock::now();
    bubblesortcarray(c_array, c_length);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    // Display sorted C-style array
    std::cout << "C-style array after sorting: " << std::endl;
    printCarray(c_array, c_length);
    std::cout << "Execution time: " << duration.count() << "ms" << std::endl;
    
    // Sort std::array using standard library
    auto start2 = std::chrono::high_resolution_clock::now();
    std::sort(std_array.begin(), std_array.end());
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    
    // Display sorted std::array
    std::cout << "std::array after sorting: " << std::endl;
    printStdarray(std_array);
    std::cout << "Execution time: " << duration2.count() << "ms" << std::endl;
    
    // std::array: calculate mean
    int std_sum = std::accumulate(std_array.begin(), std_array.end(), 0);
    float std_mean = static_cast<float>(std_sum) / std_array.size();
    //int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout << std::fixed << std::setprecision(1); // One decimal in result
    std::cout << "Average of std::array: " << std_mean << std::endl;
    
    // std::array: calculate mean
    float c_mean = averagecarray(c_array, c_length);
    std::cout << "Average of C-style array: " << c_mean << std::endl;
    
    // std::array: calculate median
    float std_median = medianstdarray(std_array);
    std::cout << "Median of std::array: " << std_median << std::endl;
    
    // std::array: calculate median
    float c_median = mediancarray(c_array, c_length);
    std::cout << "Median of C-style array: " << c_median << std::endl;
    
    return 0;
}

