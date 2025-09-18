/*
Micro Notes:

Problem:
Given an array nums, rotate it to the right by k steps, where k is non-negative.

Logic (Three-step Reverse Trick):
1. Reduce k modulo n → k = k % n (rotation larger than array size wraps around).
2. Reverse the whole array.
3. Reverse first k elements.
4. Reverse remaining n-k elements.
5. This achieves the rotation in-place.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;   // In case k > n, reduce it to valid rotation

        // Step 1: Reverse the whole array
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse remaining (n-k) elements
        reverse(nums.begin() + k, nums.end());
    }
};
