class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store number -> index
        map<int, int> mpp; 
        int n = nums.size();

        // Step 1: Traverse the array
        for (int i = 0; i < n; i++) {
            int num = nums[i];                 // current number
            int moreNeeded = target - num;     // the number we need to reach target

            // Step 2: Check if "moreNeeded" already exists in map
            if (mpp.find(moreNeeded) != mpp.end()) {
                // Found the pair -> return their indices
                return {mpp[moreNeeded], i};
            }

            // Step 3: Otherwise, store current number with its index
            mpp[num] = i;
        }

        // Step 4: If no valid pair found, return -1,-1
        return {-1, -1};
    }
};
