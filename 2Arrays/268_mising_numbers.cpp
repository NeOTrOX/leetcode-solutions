class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Total sum of numbers from 0 to n (formula of sum of first n numbers)
        int total = n * (n + 1) / 2;

        // Sum of given numbers
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // Missing number = total expected - actual sum
        return total - sum;
    }
};
