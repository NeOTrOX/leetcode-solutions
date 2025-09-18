class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1 = 0;   // Initialize result

        // XOR all elements
        for (int i = 0; i < nums.size(); i++) {
            xor1 = xor1 ^ nums[i];
        }

        return xor1;    // The remaining number is the single one
    }
};
