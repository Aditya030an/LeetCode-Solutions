class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // only map for 1->9 , if grater 9 key regect the window
        unordered_map<int, int> mp;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        if (n * m < 9)
            return 0;

        for (int row = 0; row + 2 < n; row++) {
            for (int col = 0; col + 2 < m; col++) {
                if (isMagicSquare(grid, row, col)) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        bool seen[10] = {false};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9)
                    return false;
                if (seen[num])
                    return false;

                seen[num] = true;
            }
        }

        int d1 =
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int d2 =
            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
        if (d1 != d2)
            return false;

        // check all row
        int r1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int r2 = grid[row + 1][col] + grid[row + 1][col + 1] +
                 grid[row + 1][col + 2];
        int r3 = grid[row + 2][col] + grid[row + 2][col + 1] +
                 grid[row + 2][col + 2];

        if (!(r1 == d1 && r2 == d1 && r3 == d1)) {
            return false;
        }

        // col
        int c1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int c2 = grid[row][col + 1] + grid[row + 1][col + 1] +
                 grid[row + 2][col + 1];
        int c3 = grid[row][col + 2] + grid[row + 1][col + 2] +
                 grid[row + 2][col + 2];

         if (!(c1 == d1 && c2 == d1 && c3 == d1)) {
            return false;
        }

        return true;
    }
};