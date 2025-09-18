/*
Micro Notes:

Problem:
Given an array nums, move all 0's to the end while maintaining 
the relative order of non-zero elements. Must do this in-place.

Logic (Two-pointer approach):
1. Initialize left pointer → position to place next non-zero element.
2. Traverse array with right pointer.
3. Whenever nums[right] != 0 → swap nums[right] with nums[left], then increment left.
4. This keeps non-zero elements at the front and pushes zeros to the end.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;   // Left pointer → position to place next non-zero element

        // Right pointer scans the array
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                // Swap non-zero element with left pointer
                swap(nums[right], nums[left]);
                left++;  // Move left pointer ahead
            }
        }
    }
};
