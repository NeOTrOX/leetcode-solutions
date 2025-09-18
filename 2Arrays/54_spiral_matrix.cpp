/*
Micro Notes:

Problem:
Given an m x n matrix, return all elements in spiral order.

Logic:
- Maintain four boundaries: top, bottom, left, right.
- Traverse in the following order while boundaries don't overlap:
    1. Left → Right (top row)
    2. Top → Bottom (right column)
    3. Right → Left (bottom row) if rows remain
    4. Bottom → Top (left column) if columns remain
- After each direction, move the corresponding boundary inward.
- Collect all elements into a result vector.

Time Complexity: O(m*n)
Space Complexity: O(1) extra space (excluding output)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
        int n = matrix.size();          // number of rows
        int m = matrix[0].size();       // number of columns

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        vector<int> ans;  // store the spiral order

        while (top <= bottom && left <= right) {

            // Step 1: Traverse from Left → Right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Step 2: Traverse from Top → Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Step 3: Traverse from Right → Left (if rows remain)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Step 4: Traverse from Bottom → Top (if columns remain)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;    
    }
};
