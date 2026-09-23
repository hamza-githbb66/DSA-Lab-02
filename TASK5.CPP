#include <iostream>
using namespace std;

// this function swaps the values using single pointers
void swapUsingPointers(int *pa, int *pb) {
    int temp = *pa;   // save the value pa is pointing to
    *pa = *pb;         // put b's value into a's spot
    *pb = temp;         // put the saved a value into b's spot
}

int main() {
    int a = 5, b = 10;
    int *pa = &a;   // pa holds address of a
    int *pb = &b;   // pb holds address of b

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    swapUsingPointers(pa, pb);   // pass the pointers so the function can change the real a and b

    cout << "After swap:  a = " << a << ", b = " << b << endl;

    return 0;
}