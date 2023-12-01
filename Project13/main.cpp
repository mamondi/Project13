#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

void displayMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void generateMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 9 + 1; 
        }
    }
}

void cyclicShiftRows(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int shiftCount, bool right) {
    for (int i = 0; i < rows; ++i) {
        for (int s = 0; s < shiftCount; ++s) {
            if (right) {
                int temp = matrix[i][cols - 1];
                for (int j = cols - 1; j > 0; --j) {
                    matrix[i][j] = matrix[i][j - 1];
                }
                matrix[i][0] = temp;
            }
            else {
                int temp = matrix[i][0];
                for (int j = 0; j < cols - 1; ++j) {
                    matrix[i][j] = matrix[i][j + 1];
                }
                matrix[i][cols - 1] = temp;
            }
        }
    }
}

void cyclicShiftColumns(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols, int shiftCount, bool down) {
    for (int j = 0; j < cols; ++j) {
        for (int s = 0; s < shiftCount; ++s) {
            if (down) {
                int temp = matrix[rows - 1][j];
                for (int i = rows - 1; i > 0; --i) {
                    matrix[i][j] = matrix[i - 1][j];
                }
                matrix[0][j] = temp;
            }
            else {
                int temp = matrix[0][j];
                for (int i = 0; i < rows - 1; ++i) {
                    matrix[i][j] = matrix[i + 1][j];
                }
                matrix[rows - 1][j] = temp;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(static_cast<unsigned>(time(0)));

    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols, shiftCount;
    bool right, down;

    cout << "¬вед≥ть к≥льк≥сть р€дк≥в матриц≥ (не б≥льше " << MAX_ROWS << "): ";
    cin >> rows;

    cout << "¬вед≥ть к≥льк≥сть стовпц≥в матриц≥ (не б≥льше " << MAX_COLS << "): ";
    cin >> cols;

    generateMatrix(matrix, rows, cols);

    cout << "¬вед≥ть к≥льк≥сть зсув≥в: ";
    cin >> shiftCount;

    cout << "¬вед≥ть напр€мок зсуву дл€ р€дк≥в (0 - вл≥во, 1 - вправо): ";
    cin >> right;

    cout << "¬вед≥ть напр€мок зсуву дл€ стовпц≥в (0 - вверх, 1 - вниз): ";
    cin >> down;

    cyclicShiftRows(matrix, rows, cols, shiftCount, right);
    cyclicShiftColumns(matrix, rows, cols, shiftCount, down);

    cout << "ћатриц€ п≥сл€ цикл≥чного зсуву:\n";
    displayMatrix(matrix, rows, cols);

    return 0;
}