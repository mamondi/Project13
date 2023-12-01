//Я спробував, з допомогою чатаГПТ, виконати це завдання з використанням vector, + втулив це все в менюшку

#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void displayArray(const vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void addRowToEnd(vector<vector<int>>& arr, const vector<int>& row) {
    arr.push_back(row);
}

void addRowToStart(vector<vector<int>>& arr, const vector<int>& row) {
    arr.insert(arr.begin(), row);
}

void addRowAtPosition(vector<vector<int>>& arr, const vector<int>& row, int position) {
    if (position >= 0 && position <= arr.size()) {
        arr.insert(arr.begin() + position, row);
    }
    else {
        cout << "Invalid position." << endl;
    }
}

void deleteRow(vector<vector<int>>& arr, int rowNumber) {
    if (rowNumber >= 0 && rowNumber < arr.size()) {
        arr.erase(arr.begin() + rowNumber);
    }
    else {
        cout << "Invalid row number." << endl;
    }
}

int main() {
    vector<vector<int>> array2D;

    for (int i = 0; i < ROWS; ++i) {
        vector<int> row;
        for (int j = 0; j < COLS; ++j) {
            row.push_back(i * COLS + j + 1);
        }
        array2D.push_back(row);
    }

    int choice;
    system("chcp 1251");
    system("cls");
    do {
        cout << "\n1. Додати рядок в кінець\n";
        cout << "2. Додати рядок на початок\n";
        cout << "3. Додати рядок на позицію\n";
        cout << "4. Видалити рядок за номером\n";
        cout << "5. Вивести масив\n";
        cout << "0. Вихід\n";
        cout << "Виберіть операцію: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            vector<int> newRow;
            cout << "Введіть рядок для додавання: ";
            for (int i = 0; i < COLS; ++i) {
                int element;
                cin >> element;
                newRow.push_back(element);
            }
            addRowToEnd(array2D, newRow);
            break;
        }
        case 2: {
            vector<int> newRow;
            cout << "Введіть рядок для додавання: ";
            for (int i = 0; i < COLS; ++i) {
                int element;
                cin >> element;
                newRow.push_back(element);
            }
            addRowToStart(array2D, newRow);
            break;
        }
        case 3: {
            vector<int> newRow;
            int position;
            cout << "Введіть рядок для додавання: ";
            for (int i = 0; COLS; ++i) {
                int element;
                cin >> element;
                newRow.push_back(element);
            }
            cout << "Введіть позицію для вставки: ";
            cin >> position;
            addRowAtPosition(array2D, newRow, position);
            break;
        }
        case 4: {
            int rowNumber;
            cout << "Введіть номер рядка для видалення: ";
            cin >> rowNumber;
            deleteRow(array2D, rowNumber);
            break;
        }
        case 5:
            cout << "Двовимірний масив:\n";
            displayArray(array2D);
            break;
        case 0:
            cout << "Дякую за використання програми!\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}