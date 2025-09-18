/*
Micro Notes:

Problem:
Find all elements that appear twice in an array of integers where
1 ≤ nums[i] ≤ n (n = size of array).

Logic:
- Use index marking (sign trick):
    1. For each element nums[i], map it to index = abs(nums[i]) - 1.
    2. If nums[index] is negative → this number appeared before → it's a duplicate.
    3. Otherwise, mark nums[index] as negative to indicate it has been seen.
- Return all duplicates found.

Time Complexity: O(n)
Space Complexity: O(1)  // ignoring output vector
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> values;

        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;  // map value to index

            if(nums[index] < 0) {
                // Already visited → duplicate
                values.push_back(index + 1);
            } else {
                // Mark as visited
                nums[index] = -nums[index];
            }
        }

        return values;
    }
};
