#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 350. Intersection of Two Arrays II
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // 1. using unordered_map
    // unordered_map<int, int> countMap;
    // vector<int> result;

    // // assign counts from nums1
    // for (int num : nums1)
    // {
    //     countMap[num]++;
    // }

    // // find intersection with nums2
    // for (int num : nums2)
    // {
    //     if (countMap[num] > 0)
    //     {
    //         result.push_back(num);
    //         countMap[num]--;
    //     }
    // }

    // 2. using sorting and two pointers
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> result;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            result.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

// 217. Contains Duplicate
bool containsDuplicate(vector<int> &nums)
{
    // 1. using set
    // set<int> seen;

    // for (int num : nums)
    // {
    //     if (seen.count(num))
    //     {
    //         return true;
    //     }
    //     seen.insert(num);
    // }

    // 2. using unordered_map
    // unordered_map<int, int> countMap;
    // for (int num : nums)
    // {
    //     countMap[num]++;
    //     if (countMap[num] > 1)
    //     {
    //         return true;
    //     }
    // }

    // 2.5. using unordered_set
    unordered_set<int> seen;
    for (int num : nums)
    {
        if (seen.count(num))
        {
            return true;
        }
        seen.insert(num);
    }

    // 3. using normal approach
    // for (size_t i = 0; i < nums.size(); i++)
    // {
    //     for (size_t j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums[i] == nums[j])
    //         {
    //             return true;
    //         }
    //     }
    // }

    // 4. chunking approach
    // devide the array into chunks and check each chunk for duplicates
    // int chunkSize = 1000; // Example chunk size
    // int partitions = (nums.size() + chunkSize - 1) / chunkSize; // Calculate number of chunks
    // for (int i = 0; i < partitions; i++)
    // {
    //     set<int> seen;
    //     int start = i * chunkSize;
    //     int end = min(start + chunkSize, (int)nums.size());
    //     for (int j = start; j < end; j++)
    //     {
    //         if (seen.count(nums[j]))
    //         {
    //             return true;
    //         }
    //         seen.insert(nums[j]);
    //     }
    // }

    // 5. using advanced chunking with set
    // if (nums.size() < 100)
    // {
    //     set<int> seen(nums.begin(), nums.end());
    //     return seen.size() < nums.size(); // If size is less, duplicates exist
    // }

    // int chunkSize = 100;
    // int partitions = (nums.size() + chunkSize - 1) / chunkSize;

    // for (int i = 0; i < partitions; i++)
    // {
    //     int start = i * chunkSize;
    //     int end = min(start + chunkSize, (int)nums.size());
    //     if (set<int>(nums.begin() + start, nums.begin() + end).size() < (end - start))
    //     {
    //         return true; // Found duplicates in this chunk
    //     }
    // }

    // 6. trying my best imagination
    // Take a look at the constraints of the problem
    // Constraints:
    // 1 <= nums.length <= 10^5
    // -10^9 <= nums[i] <= 10^9
    // ... I think currently I cannot think of any more efficient way than using a set or map or sorting methods

    return false;
}

// 169. Majority Element
int majorityElement(vector<int> &nums)
{
    // 1. using sorting with map
    // sort(nums.begin(), nums.end());
    // map<int, int> countMap;
    // for (int num : nums)
    // {
    //     countMap[num]++;
    //     if (countMap[num] > nums.size() / 2)
    //     {
    //         return num;
    //     }
    // }

    // 2. using sorting only
    // sort(nums.begin(), nums.end());
    // return nums[nums.size() / 2]; // The majority element will always be at the middle after sorting

    // 3. using Boyer-Moore Voting Algorithm
    // Simple explanation:
    // - Maintain a count and a candidate
    // - If count is 0, set the current number as candidate
    // - If the current number is the same as candidate, increment count
    // - If it's different, decrement count
    // - The candidate at the end will be the majority element
    // - The idea is that in an array, when counting an element, if there is a different element, that means the current element lost a place by that different element
    // - So, if we keep track of the count, we can find the majority element
    int count = 0, candidate = -1;
    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main()
{
    cout << "=== VECTOR DEMO ===\n";
    vector<int> nums = {10, 20, 30};
    nums.push_back(40); // Add element
    nums.pop_back();    // Remove last
    cout << "Vector contents: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";

    cout << "\n=== MAP DEMO ===\n";
    map<string, int> ages;
    ages["Son"] = 21;
    ages["Bro"] = 99;
    for (auto pair : ages)
    {
        cout << pair.first << " is " << pair.second << " years old\n";
    }

    cout << "\n=== UNORDERED_MAP DEMO ===\n";
    unordered_map<int, string> idName;
    idName[101] = "Son";
    idName[202] = "Best Bro";
    for (auto [id, name] : idName)
    {
        cout << "ID " << id << " → " << name << "\n";
    }

    cout << "\n=== SET DEMO ===\n";
    set<int> uniqueNums;
    uniqueNums.insert(10);
    uniqueNums.insert(5);
    uniqueNums.insert(10); // Duplicate ignored
    cout << "Set contents (sorted, unique): ";
    for (int num : uniqueNums)
    {
        cout << num << " ";
    }
    cout << "\n";

    cout << "\n=== BONUS: Check for duplicates using SET ===\n";
    vector<int> checkDup = {1, 2, 3, 2};
    set<int> seen;
    bool hasDup = false;
    for (int x : checkDup)
    {
        if (seen.count(x))
        {
            hasDup = true;
            break;
        }
        seen.insert(x);
    }
    cout << (hasDup ? "Duplicates found\n" : "No duplicates\n");

    return 0;
}
