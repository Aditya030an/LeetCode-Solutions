class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count =0 , n = grid.size() , m = grid[0].size();
        int i=0 , j = m-1;
        while(i<n && j>=0){
            if(grid[i][j] < 0){
                count = count + (n-i);
                j--;
            }else{
                i++;
            }
        }
        return count;
    }
};