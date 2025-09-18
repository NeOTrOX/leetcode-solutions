/*
Micro Notes:

Problem:
Given a binary array, find the maximum number of consecutive 1s.

Logic:
1. Initialize `count` to track current streak of 1s.
2. Initialize `maxi` to track maximum streak found so far.
3. Traverse the array:
   - If nums[i] == 1 → increment count and update maxi.
   - Else → reset count to 0.
4. Return maxi at the end.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;   // stores maximum consecutive 1s
        int count = 0;  // current streak of 1s

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;                    // increase streak
                maxi = max(maxi, count);    // update answer
            } else {
                count = 0;  // reset streak when we hit a 0
            }
        }

        return maxi;
    }
};
