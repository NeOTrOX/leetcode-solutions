/*
Micro Notes:

Problem:
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

Logic:
1. Initialize xor1 = 0.
2. XOR all elements in the array.
   - XOR properties:
     - a ^ a = 0
     - a ^ 0 = a
     - XOR is commutative & associative
3. All duplicate numbers cancel out → remaining number is the single one.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;   // Initialize result

        // XOR all elements
        for (int i = 0; i < nums.size(); i++) {
            xor1 = xor1 ^ nums[i];
        }

        return xor1;    // The remaining number is the single one
    }
};
