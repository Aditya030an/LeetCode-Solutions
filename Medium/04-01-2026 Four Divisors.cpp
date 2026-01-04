class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       int sum = 0;
       for(int i =0 ; i<nums.size() ; i++) {
        int count =0 , tempSum =0;
        for(int j =1 ; j<=nums[i] ; j++){
            if(nums[i] % j == 0){
               tempSum += j;
                count++;
            }
            if(count > 5)break;
        }
        if(count == 4){
            sum += tempSum;
        }
       }
       return sum;
    }
};