class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0;         // running sum of subarray
        int maxi = INT_MIN;        // store the maximum subarray sum found so far

        // Step 1: Traverse the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];        // include current element into sum

            // Step 2: Update maximum if current sum is greater
            if (sum > maxi) {
                maxi = sum;
            }

            // Step 3: If sum becomes negative, reset it to 0
            // (because a negative prefix will only reduce future sums)
            if (sum < 0) {
                sum = 0;
            }
        }

        // Step 4: Return the maximum subarray sum
        return maxi;
    }
};
