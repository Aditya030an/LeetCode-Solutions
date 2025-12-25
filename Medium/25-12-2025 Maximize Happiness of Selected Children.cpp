class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin() , happiness.end());
        int i =n-1;
        long long sum =0;
        while(i>=0 && k>0){
            int val = happiness[i]- ((n-1)-i);
                if(val == 0 && k>0){
                    break;
                }
            sum += val>0 ? val : 0;
            k--;
            i--;
        }
        return sum;
    }
};