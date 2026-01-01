class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int n = digits.size() - 1;
        for(int j = n ; j>=0 ; j--){
            if(digits[j] < 9){
                digits[j]++;
                return digits;
            }
            digits[j] = 0;
        }
        vector<int> ans;
        ans.push_back(1);

        for(int i = 0 ; i<n+1 ; i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }
};