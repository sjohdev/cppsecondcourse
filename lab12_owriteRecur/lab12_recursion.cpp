#include <iostream>
#include <chrono>
#include <vector>

/*
KEY POINTS: 
- Function overloading allows multiple functions with the same name but different parameter signatures
- Recursion requires both a base case (to stop) and a recursive step (to continue)
- Recursive solutions are often more elegant and closer to mathematical definitions
- Iterative solutions are typically more efficient in terms of time and memory
- Deep recursion can cause stack overflow errors

Common mistakes to avoid: 
- Forgetting the base case in recursive functions, causing infinite recursion
- Using recursion for problems where iteration is significantly more efficient
- Not considering stack depth limitations for recursive solutions
- 
*/

// Function to measure execution time
template<typename Function> 
void measureTime(const std::string& description, Function func) {
    auto start = std::chrono::high_resolution_clock::now();
    auto result = func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << description << ": " << result
        << " Time: " << duration.count() << " [microsec]" << std::endl; 
}

// Recursive Fibonacci (inefficient - exponential time O(n^2))
long long fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
// Iterative Fibonacci (efficient - linear time O(n))
long long fibonacciIterative(int n) {
    if (n <= 1) return n;
    long long prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    std::cout << "=== Performance Comparison ===" << std::endl;
    // Compare Fibonacci implementations
    int fibNumber = 35; // Try 35 first, then maybe 40 if you're patient!
    std::cout << "Fibonacci(" << fibNumber << "):" << std::endl;
    measureTime("Recursive", [=]() { return fibonacciRecursive(fibNumber); });
    measureTime("Iterative", [=]() { return fibonacciIterative(fibNumber); });
    
    return 0;
}

