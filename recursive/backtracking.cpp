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
void subsetBacktrack(vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &result)
{
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

    for (int i = start; i < nums.size(); i++)
    {
        current.push_back(nums[i]);
        // cout << "i = " << i << ", current: [ ";
        // for (int num : current) {
        //     cout << num << " ";
        // }
        // cout << "]\n";
        subsetBacktrack(nums, i + 1, current, result);
        current.pop_back();
        // cout << "Finished backtracking for i = " << i << ", current: [ ";
        // for (int num : current) {
        //     cout << num << " ";
        // }
        // cout << "]\n";
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    subsetBacktrack(nums, 0, current, result);

    return result;
}

// 46. Permutations
// Example: Given nums = [1,2,3], return all permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]
// Idea:
// 1. Use a loop with each index of the array (n times, n is the length of the array)
// 2. For each index, mark it as used and add it to the current permutation
// 3. Recursively call the function to fill the next index
void permuteBacktrack(vector<int> &nums, int start, vector<bool> &used, vector<int> &current, vector<vector<int>> &result)
{
    if (current.size() == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        if (used[i])
            continue;   // Skip if already used
        used[i] = true; // Mark as used
        current.push_back(nums[i]);
        permuteBacktrack(nums, 0, used, current, result);
        current.pop_back(); // Backtrack
        used[i] = false; // Unmark as used
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    vector<int> current;
    permuteBacktrack(nums, 0, used, current, result);

    return result;
}

int main()
{
    // 78. Subsets
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);

    cout << "Subsets of [1, 2, 3]:\n";
    for (const auto &subset : result)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    // 46. Permutations
    vector<int> numsPerm = {1, 2, 3};
    vector<vector<int>> resultPerm = permute(numsPerm);
    cout << "Permutations of [1, 2, 3]:\n";
    for (const auto &perm : resultPerm)
    {
        cout << "[ ";
        for (int num : perm)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }


    return 0;
}
