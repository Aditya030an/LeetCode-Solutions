class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int totalApple = 0;
        int totalCapacity = 0;
        int countBox = 0;
        for(int i =0 ; i< n ; i++){
            totalApple += apple[i];
        }
        for(int i =0 ; i< m ; i++){
            totalCapacity += capacity[i];
        }
        if(totalApple == totalCapacity)
        {
            return m;
        }
        else if(totalApple < totalCapacity){
            sort(capacity.begin() , capacity.end());
            int sum =0;
            for(int i = m-1 ; i>=0 ; i--){
                sum += capacity[i];
                if(sum >= totalApple){
                    countBox = i;
                    break;
                }
            }
            return m-countBox;
        }
        return 0;
    }
};