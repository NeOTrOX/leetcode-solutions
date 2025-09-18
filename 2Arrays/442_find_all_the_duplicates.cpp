/*
Micro Notes:

Problem:
Given an array nums of integers where 1 ≤ nums[i] ≤ n (n = size of array), 
some elements appear twice. Find all duplicates in O(n) time & O(1) extra space.

Logic (Index Marking Trick):
1. Traverse array. For each number nums[i], map it to index = abs(nums[i]) - 1.
2. If nums[index] < 0 → number already visited → duplicate → add index+1 to result.
3. Else → mark nums[index] as visited by making it negative.
4. Return list of duplicates.

Time Complexity: O(n)
Space Complexity: O(1) extra (ignoring output)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> values;

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;  // map number → index (1-based → 0-based)

            // If already visited, then it's a duplicate
            if (nums[index] < 0) {
                values.push_back(index + 1);
            } else {
                // Mark as visited by making it negative
                nums[index] = -nums[index];
            }
        }

        return values;
    }
};
