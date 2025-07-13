#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }

    cout << "Dynamic array contents: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}
