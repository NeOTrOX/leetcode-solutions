class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;   // Left pointer → position to place next non-zero element

        // Right pointer scans the array
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                // Swap non-zero element with left pointer
                swap(nums[right], nums[left]);
                left++;  // Move left pointer ahead
            }
        }
    }
};
