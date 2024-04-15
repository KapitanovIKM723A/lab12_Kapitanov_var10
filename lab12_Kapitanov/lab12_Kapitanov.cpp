#include <iostream>
#include <cstdlib>
#include <ctime>

const int ROWS = 10;
const int COLS = 15;

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void fillMatrixRandom(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}
void findMaxInColumns(int matrix[ROWS][COLS], int maxCols[COLS]) {
    for (int j = 0; j < COLS; j++) {
        maxCols[j] = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] > maxCols[j]) {
                maxCols[j] = matrix[i][j];
            }
        }
    }
}
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(0));

    int matrix[ROWS][COLS];
    int maxCols[COLS];

    fillMatrixRandom(matrix);
    std::cout << "Сгенерована матриця:" << std::endl;
    printMatrix(matrix);

    findMaxInColumns(matrix, maxCols);
    std::cout << "Макс. елемент в стовпцi" << std::endl;
    for (int j = 0; j < COLS; j++) {
        std::cout << maxCols[j] << " ";
    }
    std::cout << std::endl;

    sortArray(maxCols, COLS);
    std::cout << "Макс. елементи вiдсортованi" << std::endl;
    for (int j = 0; j < COLS; j++) {
        std::cout << maxCols[j] << " ";
    }
    std::cout << std::endl;

    return 0;
}
