class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k, l;

        // Step 1: Find the first index "k" from the right 
        // where nums[k] < nums[k+1].
        // This is the "breakpoint".
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }

        // Step 2: If no breakpoint found, array is in descending order.
        // Just reverse it to get the smallest permutation.
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // Step 3: Find index "l" from right such that nums[l] > nums[k].
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }

            // Step 4: Swap nums[k] and nums[l].
            swap(nums[k], nums[l]);

            // Step 5: Reverse elements from k+1 to end 
            // to get the next smallest lexicographic permutation.
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
