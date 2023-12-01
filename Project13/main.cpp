//� ���������, � ��������� �������, �������� �� �������� � ������������� vector, + ������ �� ��� � �������

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
        cout << "\n1. ������ ����� � �����\n";
        cout << "2. ������ ����� �� �������\n";
        cout << "3. ������ ����� �� �������\n";
        cout << "4. �������� ����� �� �������\n";
        cout << "5. ������� �����\n";
        cout << "0. �����\n";
        cout << "������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            vector<int> newRow;
            cout << "������ ����� ��� ���������: ";
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
            cout << "������ ����� ��� ���������: ";
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
            cout << "������ ����� ��� ���������: ";
            for (int i = 0; COLS; ++i) {
                int element;
                cin >> element;
                newRow.push_back(element);
            }
            cout << "������ ������� ��� �������: ";
            cin >> position;
            addRowAtPosition(array2D, newRow, position);
            break;
        }
        case 4: {
            int rowNumber;
            cout << "������ ����� ����� ��� ���������: ";
            cin >> rowNumber;
            deleteRow(array2D, rowNumber);
            break;
        }
        case 5:
            cout << "���������� �����:\n";
            displayArray(array2D);
            break;
        case 0:
            cout << "����� �� ������������ ��������!\n";
            break;
        default:
            cout << "������� ����. ��������� �� ���.\n";
        }
    } while (choice != 0);

    return 0;
}