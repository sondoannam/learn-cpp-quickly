#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* ptr = &x;

    cout << "x: " << x << endl;
    cout << "ptr: " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;

    *ptr = 99;
    cout << "x after *ptr=99: " << x << endl;

    // const int* means pointer can move but value cannot
    const int* cp = &x;
    // *cp = 10; // ❌ error (uncomment to see)
    x = 77; // ok, changing x itself
    cout << "x after changing x: " << x << endl;
    cout << "cp: " << cp << endl;
    cout << "*cp: " << *cp << endl;

    // int* const means pointer can't move but value can
    int y = 5;
    int* const fixedPtr = &y;
    *fixedPtr = 15; // ok
    // fixedPtr = &x; // ❌ error
    cout << "y after *fixedPtr=15: " << y << endl;
    cout << "fixedPtr: " << fixedPtr << endl;
    cout << "*fixedPtr: " << *fixedPtr << endl;
}
