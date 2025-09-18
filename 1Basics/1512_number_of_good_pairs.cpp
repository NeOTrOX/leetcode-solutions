/*
Micro Notes:

Problem:
Count the number of good pairs in an array.
A pair (i, j) is good if nums[i] == nums[j] and i < j.

Logic:
- Use a hash map to store the frequency of each number seen so far.
- Iterate through the array:
    1. If nums[i] has been seen before (pairs[nums[i]] > 0):
        - Add the frequency to count → each previous occurrence forms a good pair with current.
    2. Increment the frequency of nums[i].
- Return total count.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> pairs; // store frequency of numbers
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pairs.find(nums[i]) != pairs.end()) {
                count += pairs[nums[i]];  // each previous occurrence forms a good pair
            }
            pairs[nums[i]] = pairs[nums[i]] + 1; // increment frequency
        }

        return count;        
    }
};
