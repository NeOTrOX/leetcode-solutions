class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;   // stores maximum consecutive 1s
        int count = 0;  // current streak of 1s

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;                    // increase streak
                maxi = max(maxi, count);    // update answer
            } else {
                count = 0;  // reset streak when we hit a 0
            }
        }

        return maxi;
    }
};
