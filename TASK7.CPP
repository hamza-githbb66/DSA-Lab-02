#include <iostream>
using namespace std;

int main() {
    int n;

    // read n between 1 and 10
    do {
        cout << "Enter number of existing marks (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    // allocate n marks and read them in
    int *marks = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter mark " << (i + 1) << ": ";
        cin >> *(marks + i);
    }

    // step 1: allocate a bigger block, size n+1
    int *newMarks = new int[n + 1];

    // step 2: copy old values into the new block using pointer notation
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }

    // step 3: read the new mark into the last slot
    int newMark;
    cout << "Enter new mark: ";
    cin >> newMark;
    *(newMarks + n) = newMark;

    // step 4: free the old block, we don't need it anymore
    delete[] marks;

    // step 5: point marks at the new block and update the size
    marks = newMarks;
    n = n + 1;

    // display everything
    cout << "Updated marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;

    // release the final block exactly once
    delete[] marks;
    marks = nullptr;

    return 0;
}