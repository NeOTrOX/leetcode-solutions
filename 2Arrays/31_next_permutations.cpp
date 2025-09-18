/*
Micro Notes:

Problem:
Rearrange numbers into the lexicographically next greater permutation.
If such arrangement is not possible, rearrange as the lowest possible order (ascending).

Logic:
1. Traverse from right to find first index "k" where nums[k] < nums[k+1] → breakpoint.
2. If no breakpoint found → array is descending → reverse the array.
3. Otherwise:
    a. Traverse from right to find index "l" such that nums[l] > nums[k].
    b. Swap nums[k] and nums[l].
    c. Reverse elements from k+1 to end → get next smallest lexicographic permutation.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k, l;

        // Step 1: Find the breakpoint from right
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }

        // Step 2: If no breakpoint, reverse the whole array
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // Step 3: Find index l such that nums[l] > nums[k]
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }

            // Step 4: Swap nums[k] and nums[l]
