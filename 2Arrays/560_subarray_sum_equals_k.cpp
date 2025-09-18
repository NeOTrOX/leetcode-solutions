/*
Micro Notes:

Problem:
Given an integer array nums and integer k, return the total number of continuous 
subarrays whose sum equals to k.

Logic (Prefix Sum + HashMap):
1. Maintain prefix sum `preSum` as we traverse the array.
2. Use hashmap `mpp` to store frequency of prefix sums seen so far.
3. At each step:
   - preSum = sum(nums[0..i])
   - If (preSum - k) exists in hashmap → there exists a subarray ending at i with sum = k
   - Add its frequency to answer.
4. Update hashmap with current prefix sum frequency.
5. Return total count.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;  // stores frequency of prefix sums
        mpp[0] = 1;                  // base case: prefix sum 0 occurs once
        int preSum = 0;               // current prefix sum
        int cnt = 0;                  // count of subarrays with sum = k

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];             // update prefix sum
            int remove = preSum - k;       // check if there exists a prefix sum to remove
            cnt += mpp[remove];            // add frequency of that prefix sum
            mpp[preSum] += 1;              // update frequency of current prefix sum
        }

        return cnt;        
    }
};
