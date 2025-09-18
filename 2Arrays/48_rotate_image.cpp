/*
Micro Notes:

Problem:
Rotate an n x n 2D matrix (image) 90 degrees clockwise in-place.

Logic:
1. Transpose the matrix:
    - Swap matrix[i][j] with matrix[j][i] for all i < j.
2. Reverse each row:
    - After transpose, reversing each row gives the 90-degree rotated matrix.

Time Complexity: O(n^2)
Space Complexity: O(1) // in-place
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
