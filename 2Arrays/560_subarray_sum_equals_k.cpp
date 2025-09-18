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
