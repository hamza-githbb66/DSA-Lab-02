#include <iostream>
using namespace std;

// this function swaps the values using double pointers
void swapUsingDoublePointers(int **ppa, int **ppb) {
    int temp = **ppa;   // go two hops down to get a's actual value, save it
    **ppa = **ppb;        // put b's value into a's spot
    **ppb = temp;           // put the saved a value into b's spot
}

int main() {
    int a = 5, b = 10;
    int *pa = &a;     // pa holds address of a
    int *pb = &b;     // pb holds address of b
    int **ppa = &pa;   // ppa holds address of pa (pointer to pointer)
    int **ppb = &pb;   // ppb holds address of pb

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    swapUsingDoublePointers(ppa, ppb);   // pass the double pointers so it can dig down and swap the real values

    cout << "After swap:  a = " << a << ", b = " << b << endl;

    return 0;
}