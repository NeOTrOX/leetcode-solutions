class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];       // Store the minimum price so far (best buy point)
        int maxProfit = 0;          // Store maximum profit found so far
        int n = prices.size();

        for (int i = 1; i < n; i++) {
            int cost = prices[i] - mini;          // Profit if we sell today
            maxProfit = max(maxProfit, cost);     // Update maximum profit
            mini = min(mini, prices[i]);          // Update minimum price (buy cheaper if possible)
        }

        return maxProfit;   // Return the best profit possible
    }
};
