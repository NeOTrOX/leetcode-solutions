/*
Micro Notes:

Problem:
Given an array prices where prices[i] is the price of a stock on day i, 
find the maximum profit you can achieve by choosing a single day to buy 
and a different day in the future to sell.

Logic:
1. Track the minimum price seen so far (mini).
2. For each day:
   - Calculate profit if sold today: prices[i] - mini.
   - Update maxProfit if this profit is higher.
   - Update mini if prices[i] is smaller.
3. Return maxProfit.

Time Complexity: O(n)
Space Complexity: O(1)
*/

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
