#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Leetcode twosum problem
vector<int> twoSum(vector<int>& nums, int target) {
    // define a map to store the indices of the numbers
    unordered_map<int, int> num_map;
    
    // 1. using 2 pass
    // // set the map with the numbers and their indices
    // for (int i = 0; i < nums.size(); i++) {
    //     num_map[nums[i]] = i;
    // }


    // for (int i = 0; i < nums.size(); i++) {
    //     int complement = target - nums[i];
    //     // check if the complement exists in the map
    //     if (num_map.find(complement) != num_map.end()) {
    //         // check if the indices are not the same
    //         if (num_map[complement] != i) {
    //             // if they are different, return the indices
    //             return {i, num_map[complement]};
    //         }
    //     }
    // }

    // 2. using 1 pass
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        // check if the complement exists in the map
        if (num_map.find(complement) != num_map.end()) {
            // if it exists, return the indices
            return {num_map[complement], i};
        }
        // store the current number and its index in the map
        num_map[nums[i]] = i;
    }

    // if no solution is found, return an empty vector
    return {};
}

// Leetcode valid palindrome problem
bool isPalindrome(const string s) {
    // Remove non-alphanumeric characters and convert to lowercase
    string filtered;
    for (char c : s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }

    // 1. using while loop
    // int left = 0;
    // int right = filtered.size() - 1;
    // while (left < right) {
    //     if (filtered[left] != filtered[right]) {
    //         return false;
    //     }
    //     left++;
    //     right--;
    // }

    // 2. using for loop
    for (int i = 0; i < filtered.size() / 2; i++) {
        if (filtered[i] != filtered[filtered.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

// Optimized valid palindrome check
bool isPalindromeOptimized(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

// Function to return the square of a number
int square(int x) {
    return x * x;
}

int main() {
    // Declare variables
    int a, b;

    // Input
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // Output
    cout << "Sum: " << a + b << endl;
    cout << "Product: " << a * b << endl;
    cout << "Square of first: " << square(a) << endl;

    // Conditionals
    if (a > b) {
        cout << a << " is greater than " << b << endl;
    } else if (a == b) {
        cout << "Both are equal" << endl;
    } else {
        cout << b << " is greater than " << a << endl;
    }

    // Loops
    cout << "Countdown from " << a << ": ";
    for (int i = a; i >= 0; i--) {
        cout << i << " ";
    }
    cout << endl;

    // twoSum example
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Input array: ";
    for (int num : nums) {
        cout << num << (num != nums.back() ? ", " : "");
    }
    cout << endl;
    cout << "Find two indices for target " << target << " :";
    if (!result.empty()) {
        cout << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found" << endl;
    }

    // isPalindrome example
    string test_str = "A man, a plan, a canal: Panama";
    cout << "Is the string a palindrome? " << (isPalindrome(test_str) ? "Yes" : "No") << endl;

    return 0;
}
