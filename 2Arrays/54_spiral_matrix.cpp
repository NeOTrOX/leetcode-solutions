class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
    int n = matrix.size();          // number of rows
    int m = matrix[0].size();       // number of columns

    // Define boundaries
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    vector<int> ans;  // store the spiral order

    // Traverse until boundaries overlap
    while (top <= bottom && left <= right) {

        // Step 1: Traverse from Left → Right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;  // move top boundary down

        // Step 2: Traverse from Top → Bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;  // move right boundary left

        // Step 3: Traverse from Right → Left (if rows remain)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;  // move bottom boundary up
        }

        // Step 4: Traverse from Bottom → Top (if columns remain)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;  // move left boundary right
        }
    }

    return ans;    
    }
};
