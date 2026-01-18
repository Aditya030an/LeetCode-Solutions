class Solution {
public:
    bool allSumEqual(int sr, int sc, int size, vector<vector<int>>& grid) {
        int target = 0;

        // first row sum
        for (int j = sc; j < sc + size; j++) {
            target += grid[sr][j];
        }

        // check all rows
        for (int i = sr; i < sr + size; i++) {
            int rowSum = 0;
            for (int j = sc; j < sc + size; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != target)
                return false;
        }

        // check all columns
        for (int j = sc; j < sc + size; j++) {
            int colSum = 0;
            for (int i = sr; i < sr + size; i++) {
                colSum += grid[i][j];
            }
            if (colSum != target)
                return false;
        }

        // main diagonal
        int d1Sum = 0;
        for (int i = 0; i < size; i++) {
            d1Sum += grid[sr + i][sc + i];
        }
        if (d1Sum != target)
            return false;

        // anti-diagonal
        int d2Sum = 0;
        for (int i = 0; i < size; i++) {
            d2Sum += grid[sr + i][sc + size - 1 - i];
        }
        if (d2Sum != target)
            return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int maxSize = min(m - i, n - j);
                for (int size = 2; size <= maxSize; size++) {
                    if (allSumEqual(i, j, size, grid)) {
                        k = max(k, size);
                    }
                }
            }
        }
        return k;
    }
};