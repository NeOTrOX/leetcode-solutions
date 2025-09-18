class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> values;

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;  // map number → index (1-based → 0-based)

            // If already visited, then it's a duplicate
            if (nums[index] < 0) {
                values.push_back(index + 1);
            } else {
                // Mark as visited by making it negative
                nums[index] = -nums[index];
            }
        }

        return values;
    }
};
