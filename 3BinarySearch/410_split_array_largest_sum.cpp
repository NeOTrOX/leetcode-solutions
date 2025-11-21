class Solution {
public:
    int countSubarrays(vector<int>& nums, int mid) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int x : nums) {
  
            if (currentSum + x > mid) {
                subarrays++;
                currentSum = x;
            } 
            else {
                currentSum += x;
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
 
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int subarrays = countSubarrays(nums, mid);

            if (subarrays > k) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return low;  
    }
};
