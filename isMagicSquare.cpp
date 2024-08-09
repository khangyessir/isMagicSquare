class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() < 3 || grid[0].size() < 3) return ans;
        for(int i = 0; i <= grid.size() - 3; i++) {
            for(int j = 0; j <= grid[0].size() - 3; j++) {
                if(isMagicSquare(grid, i, j)) ans++;
            }
        }
        return ans;

    }
private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        vector<int> value;
        for(int i = row; i < row + 3; i++) {
            for(int j = col; j < col + 3; j++) {
                if(grid[i][j] < 1 || grid[i][j] > 9) return false;
                value.push_back(grid[i][j]);
            }
        }
        sort(value.begin(), value.end());
        for(int i = 0; i < 9; i++) {
            if(value[i] != i + 1) return false;
        }
        int row1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int row2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int row3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];
        if(row1 != row2 || row2 != row3) return false;
        int col1 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int col2 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int col3 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];
        if(col1 != col2 || col2 != col3) return false;
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        return diag1 == diag2 && diag1 == row1;
    }
};
