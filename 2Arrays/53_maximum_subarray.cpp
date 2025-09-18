/*
Micro Notes:

Problem:
Find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Logic:
- Use Kadane's Algorithm:
    1. Initialize sum = 0 (running sum) and maxi = INT_MIN.
    2. Traverse the array:
        a. Add current element to sum.
        b. Update maxi if sum > maxi.
        c. If sum < 0 → reset sum to 0 (negative prefix won't help future sums).
- Return maxi.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0;         // running sum of subarray
        int maxi = INT_MIN;        // store the maximum subarray sum found so far

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];        // include current element into sum

            if (sum > maxi) {
                maxi = sum;        // update maximum
            }

            if (sum < 0) {
                sum = 0;           // reset if running sum negative
            }
        }

        return maxi;               // maximum subarray sum
    }
};
