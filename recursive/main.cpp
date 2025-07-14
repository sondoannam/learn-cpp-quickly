#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printReverse(int n) {
    if (n == 0) return;
    cout << n << " ";
    printReverse(n - 1);
}

bool isPalindrome(const string& s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return isPalindrome(s, left + 1, right - 1);
}

string reverseString(const string& s) {
    if (s.length() <= 1) return s;
    return reverseString(s.substr(1)) + s[0];
}

int main() {
    cout << "Factorial of 5: " << factorial(5) << endl;

    cout << "Fibonacci of 10: " << fibonacci(10) << endl;

    cout << "Print numbers in reverse from 5: ";
    printReverse(5);
    cout << endl;

    string str = "racecar";
    cout << "Is '" << str << "' a palindrome? " << (isPalindrome(str, 0, str.length() - 1) ? "Yes" : "No") << endl;

    string toReverse = "hello";
    cout << "Reversed string of '" << toReverse << "': " << reverseString(toReverse) << endl;

    return 0;
}
