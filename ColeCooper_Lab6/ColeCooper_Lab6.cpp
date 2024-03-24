#include <iostream>
#include <fstream>
#include <iomanip>

// Function prototypes
void readMatrixFromFile(int**& matrix, int& size);
void printMatrix(int** matrix, int size);
void addMatrices(int** matrix1, int** matrix2, int**& result, int size);
void multiplyMatrices(int** matrix1, int** matrix2, int**& result, int size);
void subtractMatrices(int** matrix1, int** matrix2, int**& result, int size);
void updateElement(int** matrix, int row, int col, int newValue, int size);
int getMaxValue(int** matrix, int size);
void transposeMatrix(int** matrix, int**& result, int size);
void deleteMatrix(int** matrix, int size);

int main() {
    int** matrix1, ** matrix2, ** result;
    int size1, size2;

    // Read matrices from file
    readMatrixFromFile(matrix1, size1);
    readMatrixFromFile(matrix2, size2);

    // Display matrices
    std::cout << "Matrix 1:\n";
    printMatrix(matrix1, size1);

    std::cout << "\nMatrix 2:\n";
    printMatrix(matrix2, size2);

    // Add matrices
    addMatrices(matrix1, matrix2, result, size1);
    std::cout << "\nMatrix 1 + Matrix 2:\n";
    printMatrix(result, size1);

    // Multiply matrices
    multiplyMatrices(matrix1, matrix2, result, size1);
    std::cout << "\nMatrix 1 * Matrix 2:\n";
    printMatrix(result, size1);

    // Subtract matrices
    subtractMatrices(matrix1, matrix2, result, size1);
    std::cout << "\nMatrix 1 - Matrix 2:\n";
    printMatrix(result, size1);

    // Update element
    updateElement(matrix1, 1, 1, 100, size1);
    std::cout << "\nMatrix 1 after updating element at (1, 1):\n";
    printMatrix(matrix1, size1);

    // Get max value
    std::cout << "\nMax value in Matrix 1: " << getMaxValue(matrix1, size1) << std::endl;

    // Transpose matrix
    transposeMatrix(matrix1, result, size1);
    std::cout << "\nTranspose of Matrix 1:\n";
    printMatrix(result, size1);

    // Clean up
    deleteMatrix(matrix1, size1);
    deleteMatrix(matrix2, size2);
    deleteMatrix(result, size1);

    return 0;
}

void readMatrixFromFile(int**& matrix, int& size) {
    std::ifstream file("matrix_input.txt");
    file >> size;

    matrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close();
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void addMatrices(int** matrix1, int** matrix2, int**& result, int size) {
    result = new int* [size];
    for (int i = 0; i < size; ++i) {
        result[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(int** matrix1, int** matrix2, int**& result, int size) {
    result = new int* [size];
    for (int i = 0; i < size; ++i) {
        result[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrices(int** matrix1, int** matrix2, int**& result, int size) {
    result = new int* [size];
    for (int i = 0; i < size; ++i) {
        result[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void updateElement(int** matrix, int row, int col, int newValue, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    }
}

int getMaxValue(int** matrix, int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

void transposeMatrix(int** matrix, int**& result, int size) {
    result = new int* [size];
    for (int i = 0; i < size; ++i) {
        result[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
}

void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}