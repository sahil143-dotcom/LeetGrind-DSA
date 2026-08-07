class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),
         n = matrix[0].size();
        bool col0 = false;

        // PASS 1: Mark — scan every cell, set markers in first row/col
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) col0 = true;       // col 0 gets its own flag
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;                  // mark: this row has a zero
                    matrix[0][j] = 0;                  // mark: this col has a zero
                }
            }
        }

        // PASS 2: Zero cells using markers (bottom to top, skip first row & col)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0) matrix[i][0] = 0;                // handle col 0 using flag
        }
    }
};