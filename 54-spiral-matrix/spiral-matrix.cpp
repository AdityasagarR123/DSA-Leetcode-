class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {

            // 1. Left → Right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // 2. Top → Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // 3. Right → Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // 4. Bottom → Top
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