class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;                  // left pointer → position for 0
        int m = 0;                  // mid pointer → current element
        int r = nums.size() - 1;    // right pointer → position for 2

        // Process the array until mid crosses right
        while (m <= r) {
            if (nums[m] == 0) {
                // If current element is 0, swap with left
                swap(nums[l++], nums[m++]);
            }
            else if (nums[m] == 1) {
                // If current element is 1, just move mid
                m++;
            }
            else {
                // If current element is 2, swap with right
                swap(nums[m], nums[r--]);
                // Don’t move mid here → because swapped element could be 0 or 1
            }
        }
    }
};
