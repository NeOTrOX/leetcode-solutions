/*
Micro Notes:

Problem:
Given an array nums containing n distinct numbers in the range [0, n], 
find the one number that is missing from the array.

Logic:
1. Calculate total sum of numbers from 0 to n using formula: total = n*(n+1)/2.
2. Calculate sum of given array.
3. Missing number = total - sum_of_array.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Total sum of numbers from 0 to n (formula of sum of first n numbers)
        int total = n * (n + 1) / 2;

        // Sum of given numbers
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // Missing number = total expected - actual sum
        return total - sum;
    }
};
