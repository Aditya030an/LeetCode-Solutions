class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // sorted[i] = true means strs[i] <= strs[i+1] is already confirmed
        vector<bool> sorted(n - 1, false);
        int deletions = 0;

        for (int col = 0; col < m; col++) {
            bool needDelete = false;

            // Check if current column breaks ordering
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }

            // If broken, delete this column
            if (needDelete) {
                deletions++;
                continue;
            }

            // Update sorted pairs
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                    sorted[i] = true;
                }
            }
        }

        return deletions;
    }
};
