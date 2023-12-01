#include <iostream>
#include <Windows.h>

const int ROWS = 3;
const int COLS = 3;

void displayArray(int arr[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addColumnAtPosition(int arr[][COLS], int rows, int cols, int column[], int position) {
    if (position >= 0 && position <= cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = cols; j > position; --j) {
                arr[i][j] = arr[i][j - 1];
            }
            arr[i][position] = column[i];
        }
    }
    else {
        std::cout << "Invalid position." << std::endl;
    }
}

void deleteColumn(int arr[][COLS], int rows, int cols, int colNumber) {
    if (colNumber >= 0 && colNumber < cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = colNumber; j < cols - 1; ++j) {
                arr[i][j] = arr[i][j + 1];
            }
            arr[i][cols - 1] = 0;
        }
    }
    else {
        std::cout << "Invalid column number." << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int array2D[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            array2D[i][j] = i * COLS + j + 1;
        }
    }

    int choice;
    do {
        std::cout << "\n1. ������ �������� �� �������\n";
        std::cout << "2. �������� �������� �� �������\n";
        std::cout << "3. ������� �����\n";
        std::cout << "0. �����\n";
        std::cout << "������� ��������: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int newColumn[ROWS];
            std::cout << "������ �������� ��� ���������: ";
            for (int i = 0; i < ROWS; ++i) {
                std::cin >> newColumn[i];
            }
            int position;
            std::cout << "������ ������� ��� �������: ";
            std::cin >> position;
            addColumnAtPosition(array2D, ROWS, COLS, newColumn, position);
            break;
        }
        case 2: {
            int colNumber;
            std::cout << "������ ����� ������� ��� ���������: ";
            std::cin >> colNumber;
            deleteColumn(array2D, ROWS, COLS, colNumber);
            break;
        }
        case 3:
            std::cout << "���������� �����:\n";
            displayArray(array2D, ROWS, COLS);
            break;
        case 0:
            std::cout << "����� � ��������.\n";
            break;
        default:
            std::cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 0);

    return 0;
}