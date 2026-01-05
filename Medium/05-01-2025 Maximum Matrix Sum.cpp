class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum =0;
        int mini = INT_MAX;
        int c =0 , n  = matrix.size() , m= matrix[0].size();

        for( int i =0 ; i<n ; i++){
            for(int j =0 ; j< m ; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) c++;
                mini = min(mini , abs((matrix[i][j])));
            }
        }
        if(c%2) sum -= 2 * mini;

        return sum;
    }
};