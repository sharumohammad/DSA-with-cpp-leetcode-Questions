class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> cur(col + 1, 0);
        vector<int> next(col + 1, 0);
        int maxi = 0;
        for(int i = row - 1; i >= 0; i--) {
            for(int j = col - 1; j >= 0; j--) {
                int right = cur[j + 1];
                int diag = next[j + 1];
                int down = next[j];

                if(matrix[i][j] == '1') {
                    cur[j] = 1 + min({right, down, diag});
                    maxi = max(maxi, cur[j]);
                } else {
                    cur[j] = 0;
                }
            }
            next = cur;
        }
        
        return maxi * maxi;
    
    }
};