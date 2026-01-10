class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));

        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(s1[i] == s2[j]){
                    dp[i+1][j+1] = dp[i][j] + int(s1[i]);
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j] , dp[i][j+1]);
                }
            }
        }

        int total_ascii =0;
        for(char c : s1) total_ascii += c;
        for(char c : s2) total_ascii += c;

        return total_ascii - 2 * dp[n][m];
    }
};
