/*
Micro Notes:

Problem:
Given an array nums of size n, find the majority element (appears more than n/2 times). 
Assume that a majority element always exists.

Logic (Boyer-Moore Voting Algorithm):
1. Initialize count = 0, candidate = 0.
2. Traverse the array:
   - If count == 0 → pick current number as new candidate.
   - If num == candidate → increment count.
   - Else → decrement count.
3. At the end, candidate holds the majority element.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;       // Tracks balance between candidate and others
        int candidate = 0;   // Stores the potential majority element
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;   // Pick new candidate
            }
            
            if (num == candidate) {
                count++;           // Same as candidate → increase balance
            } else {
                count--;           // Different from candidate → decrease balance
            }
        }
        
        return candidate;   // Candidate is guaranteed majority (problem statement ensures it)
    }
};
