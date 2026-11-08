#include <iostream>
#define N 3
#define M 4

void addMatrices(int A[N][M], int B[N][M], int C[N][M]) {
    // Matrix addition
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            C[row][col] = A[row][col] + B[row][col];
        }
    }
}

int main() {
    // Create 5x5 matrix
    const int rowsz = N;
    const int colsz = M;
    int matrix[rowsz][colsz] = {
        {0, 1, 1, 0}, 
        {1, 0, 0, 0}, 
        {0, 0, 1, 0}
    };
    
    // Row-major traversal (row by row)
    std::cout << "Row-major traversal (row by row):" << std::endl;
    for (int row = 0; row < rowsz; row++) {
        std::cout << "Row " << (row + 1) << ": ";
        for (int col = 0; col < colsz; col++) {
        std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
    
    // Sum matrix with itself
    int sumMat[rowsz][colsz] = {{0}};
    addMatrices(matrix, matrix, sumMat);
    
    // Display sum of matrix with itself (row by row)
    std::cout << "Row-major traversal (row by row):" << std::endl;
    for (int row = 0; row < rowsz; row++) {
        std::cout << "Row " << (row + 1) << ": ";
        for (int col = 0; col < colsz; col++) {
        std::cout << sumMat[row][col] << " ";
        }
        std::cout << std::endl;
    }
    
    // Check size of matrix: 
    int matElements = sizeof(matrix) / sizeof(matrix[0][0]);
    int matCols = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int matRows = matElements / matCols;
    
    std::cout << "Matrix dimensions: " << std::endl;
    std::cout << "Elements: " << matElements << std::endl;
    std::cout << "Rows: " << matRows << std::endl;
    std::cout << "Columns: " << matCols << std::endl;
    return 0;
}
