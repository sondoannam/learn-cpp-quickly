#include <iostream>
#include <vector>

using namespace std;

// BACKTRACKING

// 78. Subsets
// Example: Given nums = [1,2,3], return all subsets:
// [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
// Idea:
// 1. Loop with each length of array
// 2. For each length, generate combinations of that length
// 3. Store each combination in result
void backtrack(vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &result) {
    result.push_back(current);
    // cout << "Backtracking at start = " << start << endl;
    // cout << "Current subset: [ ";
    // for (int num : current) {
    //     cout << num << " ";
    // }
    // cout << "]\n";
    // cout << "Result so far: \n";
    // for (const auto& subset : result) {
    //     cout << "[ ";
    //     for (int num : subset) {
    //         cout << num << " ";
    //     }
    //     cout << "]\n";
    // }
    // cout << "------------------------\n";

    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        // cout << "i = " << i << ", current: [ ";
        // for (int num : current) {
        //     cout << num << " ";
        // }
        // cout << "]\n";
        backtrack(nums, i + 1, current, result);
        current.pop_back();
        // cout << "Finished backtracking for i = " << i << ", current: [ ";
        // for (int num : current) {
        //     cout << num << " ";
        // }
        // cout << "]\n";
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, 0, current, result);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
