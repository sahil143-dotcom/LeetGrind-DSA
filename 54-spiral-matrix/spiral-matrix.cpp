class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            // Move 1: left → right across top row
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;

            // Move 2: top → bottom down right col
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            // Guard: if top crossed bottom, no bottom row to walk
            if (top > bottom) break;

            // Move 3: right → left across bottom row
            for (int j = right; j >= left; j--)
                result.push_back(matrix[bottom][j]);
            bottom--;

            // Guard: if left crossed right, no left col to walk
            if (left > right) break;

            // Move 4: bottom → top up left col
            for (int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;
        }
        return result;
    }
};