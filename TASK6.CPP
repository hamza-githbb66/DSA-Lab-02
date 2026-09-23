#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // ask how many students (rows) and subjects (cols), keep asking if invalid
    do {
        cout << "Enter number of students (rows): ";
        cin >> rows;
    } while (rows <= 0);

    do {
        cout << "Enter number of subjects (cols): ";
        cin >> cols;
    } while (cols <= 0);

    // step 1: make the array of row pointers
    int **marks = new int*[rows];

    // step 2: give each row its own array of cols ints
    for (int r = 0; r < rows; r++) {
        marks[r] = new int[cols];
    }

    // read marks using pointer notation (two hops: row, then column)
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Enter mark for student " << (r + 1)
                 << ", subject " << (c + 1) << ": ";
            cin >> *(*(marks + r) + c);
        }
    }

    // print the whole matrix
    cout << "\nMarks Matrix:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << "\t";
        }
        cout << endl;
    }

    // add up each student's marks, keep track of the best one so far
    int bestTotal = 0, bestStudent = 1;
    for (int r = 0; r < rows; r++) {
        int total = 0;
        for (int c = 0; c < cols; c++) {
            total += marks[r][c];
        }
        cout << "Student " << (r + 1) << " total: " << total << endl;

        // only update the best if this total is actually higher (keeps first on ties)
        if (r == 0 || total > bestTotal) {
            bestTotal = total;
            bestStudent = r + 1;
        }
    }
    cout << "\nHighest total: Student " << bestStudent
         << " with " << bestTotal << " marks" << endl;

    // cleanup: free each row first, then the row-pointer array itself
    for (int r = 0; r < rows; r++) {
        delete[] marks[r];
    }
    delete[] marks;
    marks = nullptr;

    return 0;
}