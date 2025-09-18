/*
Micro Notes:

Problem:
Given an array of integers and a target, return indices of the two numbers
such that they add up to the target.

Logic:
- Use a map to store number → index.
- Traverse the array:
    1. For each number, calculate "moreNeeded" = target - current number.
    2. If moreNeeded exists in map → found the pair → return indices.
    3. Otherwise, store current number with its index in map.
- If no pair found → return {-1, -1}.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp; // Map to store number -> index
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int num = nums[i];                 // current number
            int moreNeeded = target - num;     // number needed to reach target

            if (mpp.find(moreNeeded) != mpp.end()) {
                // Found the pair → return their indices
                return {mpp[moreNeeded], i};
            }

            // Store current number with its index
            mpp[num] = i;
        }

        // If no valid pair found
        return {-1, -1};
    }
};
