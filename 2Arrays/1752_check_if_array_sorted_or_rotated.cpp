class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;   // counts the number of "inversions"

        // Count how many times current element is smaller than previous
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
            }
        }

        // Check last element with first (circular rotation)
        if (nums[n - 1] > nums[0]) {
            count++;
        }

        // Array is sorted & rotated if there is at most 1 inversion
        return count <= 1;
    }
};
