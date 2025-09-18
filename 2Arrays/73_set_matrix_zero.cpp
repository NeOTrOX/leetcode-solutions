/*
Micro Notes:

Problem:
Given an m x n matrix, if an element is 0, set its entire row and column to 0 in-place.

Logic:
1. Use first row and first column as markers:
    - Traverse matrix:
        - If matrix[i][j] == 0:
            - Mark first element of row i and column j as 0.
            - Use separate flags fr, fc for first row & column.
2. Traverse matrix again (excluding first row & column):
    - Set matrix[i][j] = 0 if row or column marked.
3. Handle first row & first column separately if flagged.

Time Complexity: O(m*n)
Space Complexity: O(1) // in-place
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();       // number of rows
        int n = matrix[0].size();    // number of columns
        bool fr = false, fc = false; // flags for first row & first column

        // Step 1: Mark rows and columns that need to be zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) fr = true;   // zero found in first row
                    if (j == 0) fc = true;   // zero found in first column
                    matrix[0][j] = 0;        // mark column
                    matrix[i][0] = 0;        // mark row
                }
            }
        }

        // Step 2: Use marks to set zeroes (skip first row & col for now)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row separately (if flagged earlier)
        if (fr) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column separately (if flagged earlier)
        if (fc) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
