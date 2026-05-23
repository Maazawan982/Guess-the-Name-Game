#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

void displayGrid(const vector<vector<char> >& grid) {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char caseChoice;
    cout << "Grid kis case mein chahiye?" << endl;
    cout << "1. Lower case (a-z)" << endl;
    cout << "2. Upper case (A-Z)" << endl;
    cout << "Apni choice enter karein (1 ya 2): ";
    cin >> caseChoice;

    while (caseChoice != '1' && caseChoice != '2') {
        cout << "Invalid choice! Sirf 1 ya 2 enter karein: ";
        cin >> caseChoice;
    }

    char startLetter;
    if (caseChoice == '1') {
        startLetter = 'a';
        cout << "\nLower case grid selected." << endl;
    } else {
        startLetter = 'A';
        cout << "\nUpper case grid selected." << endl;
    }

    vector<vector<char> > grid(6, vector<char>(5));
    char letter = startLetter;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((caseChoice == '1' && letter <= 'z') ||
                (caseChoice == '2' && letter <= 'Z')) {
                grid[i][j] = letter++;
            } else {
                grid[i][j] = ' ';
            }
        }
    }

    cout << "\nInitial Grid:" << endl;
    displayGrid(grid);

    int nameLength;
    cout << "\nHow many characters are in your name? ";
    cin >> nameLength;

    vector<vector<char> > nameArrays(nameLength);
    cout << "\nEnter the column numbers (0-4) where each character of your name occurs in sequence:" << endl;
    vector<int> selectedColumns(nameLength);
    set<int> uniqueColumns;

    for (int i = 0; i < nameLength; ++i) {
        cout << "Column for character " << (i + 1) << ": ";
        cin >> selectedColumns[i];
        uniqueColumns.insert(selectedColumns[i]);
    }

    for (int i = 0; i < nameLength; ++i) {
        int col = selectedColumns[i];
        for (int row = 0; row < 6; ++row) {
            nameArrays[i].push_back(grid[row][col]);
        }
    }

    cout << "\nInitial Arrays:" << endl;
    for (int i = 0; i < nameLength; ++i) {
        cout << "Array " << (i + 1) << ": ";
        for (size_t j = 0; j < nameArrays[i].size(); ++j) {
            cout << nameArrays[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<char> > selectedGrid(6, vector<char>(uniqueColumns.size()));
    int colIndex = 0;
    set<int>::iterator sit;
    for (sit = uniqueColumns.begin(); sit != uniqueColumns.end(); ++sit) {
        int col = *sit;
        for (int row = 0; row < 6; ++row) {
            selectedGrid[row][colIndex] = grid[row][col];
        }
        ++colIndex;
    }

    cout << "\nNew Grid from Selected Columns:" << endl;
    displayGrid(selectedGrid);

    cout << "\nEnter the row numbers (0-5) for the next round of grid selection in sequence:" << endl;
    vector<int> selectedRows(nameLength);
    for (int i = 0; i < nameLength; ++i) {
        cout << "Row for character " << (i + 1) << ": ";
        cin >> selectedRows[i];
    }

    for (int i = 0; i < nameLength; ++i) {
        int row = selectedRows[i];
        for (size_t col = 0; col < uniqueColumns.size(); ++col) {
            nameArrays[i].push_back(selectedGrid[row][col]);
        }
    }

    cout << "\nUpdated Arrays:" << endl;
    for (int i = 0; i < nameLength; ++i) {
        cout << "Array " << (i + 1) << ": ";
        for (size_t j = 0; j < nameArrays[i].size(); ++j) {
            cout << nameArrays[i][j] << " ";
        }
        cout << endl;
    }

    string guessedName = "";
    for (int i = 0; i < nameLength; ++i) {
        map<char, int> freqMap;
        for (size_t j = 0; j < nameArrays[i].size(); ++j) {
            freqMap[nameArrays[i][j]]++;
        }
        char mostFrequentChar = ' ';
        int maxFreq = 0;
        map<char, int>::iterator it;
        for (it = freqMap.begin(); it != freqMap.end(); ++it) {
            if (it->second > maxFreq) {
                mostFrequentChar = it->first;
                maxFreq = it->second;
            }
        }
        guessedName += mostFrequentChar;
    }

    cout << "\nGuessed Name: " << guessedName << endl;
    return 0;
}
