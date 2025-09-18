/*
Micro Notes:

Problem:
Given an integer array, check if it can be sorted in ascending order by rotating it
(i.e., array is sorted but may be rotated).

Logic (Inversion Counting):
1. Initialize count = 0 to track "inversions" → places where nums[i-1] > nums[i].
2. Traverse array from 1 to n-1:
   - If nums[i-1] > nums[i] → increment count.
3. Check wrap-around: if nums[n-1] > nums[0] → increment count.
4. If count <= 1 → array is sorted and rotated, else not.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;   // counts the number of "inversions"

        // Count how many times current element is smaller than previous
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
            }
        }

        // Check last element with first (circular rotation)
        if (nums[n - 1] > nums[0]) {
            count++;
        }

        // Array is sorted & rotated if there is at most 1 inversion
        return count <= 1;
    }
};
