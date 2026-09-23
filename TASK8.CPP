#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int *values = new int[n];      // allocated with new[]

    for (int i = 0; i < n; i++) {  // fixed: only valid indexes 0 to n-1
        cin >> values[i];
    }

    for (int i = 0; i < n; i++) {  // display all three integers
        cout << values[i] << " ";
    }
    cout << endl;

    delete[] values;               // fixed: matching delete[] for new[]
    values = nullptr;              // reset pointer after freeing

    return 0;
}