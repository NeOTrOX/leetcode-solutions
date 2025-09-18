/*
Micro Notes:

Problem:
Sort an array containing only 0s, 1s, and 2s in-place in ascending order.

Logic (Dutch National Flag Algorithm):
1. Maintain three pointers:
   - l (left) → next position for 0
   - m (mid)  → current element
   - r (right) → next position for 2
2. Traverse while mid <= right:
   - If nums[m] == 0 → swap with nums[l], increment l and m
   - If nums[m] == 1 → just move m
   - If nums[m] == 2 → swap with nums[r], decrement r (don’t move m yet)
3. This ensures all 0s go to left, 1s in middle, 2s on right.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;                  // left pointer → position for 0
        int m = 0;                  // mid pointer → current element
        int r = nums.size() - 1;    // right pointer → position for 2

        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[l++], nums[m++]); // move 0 to left
            }
            else if (nums[m] == 1) {
                m++;                       // leave 1 in middle
            }
            else {
                swap(nums[m], nums[r--]);  // move 2 to right
            }
        }
    }
};
