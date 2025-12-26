class Solution {
public:
    int bestClosingTime(string customers) {
        // int minP =INT_MAX ,ans = 0;
        // int n = customers.size();
        // for(int i =0 ; i<=n ; i++){
        //     int currP =0;
        //     for(int j =0 ; j<n ; j++){
        //         if(j < i){
        //             if(customers[j] == 'N'){
        //                 currP++;
        //             }
        //         }else if(j == i){
        //             if(customers[j] == 'Y'){
        //                 currP++;
        //             }
        //         }else{
        //             if(customers[j] == 'Y'){
        //                 currP++;
        //             }
        //         }
        //     }
        //     if(minP > currP){
        //         minP = currP;
        //         ans =i;
        //     }
        // }
        // return ans;

        // int currP =0 , n = customers.size();
        // for(int i =0 ; i<n ; i++){
        //     if(customers[i] == 'Y'){
        //         currP++;
        //     }
        // }
        // int minP = currP , earlistH = 0;

        // for(int i =0 ; i<=n ; i++){
        //     char ch = customers[i];

        //     if(ch == 'Y'){
        //         currP--;
        //     }else{
        //         currP++;
        //     }

        //     if(currP < minP){
        //         earlistH = i+1;
        //         minP = currP;
        //     }
        // }
        // return earlistH;

        int n = customers.size() , LN =0 , totalY =0;

        for(int i =0 ; i<n ; i++){
            totalY += (customers[i]=='Y');
        }

        int Y =0 , mpen = INT_MAX , ans =0;
        for(int i =0 ; i<n; i++){
            int RY = totalY - Y;
            int penalty = RY + LN;
            if(penalty < mpen){
                ans =i;
                mpen = penalty;
            }
            Y += (customers[i] == 'Y');
            LN += (customers[i] == 'N');
        }

        int RY = totalY - Y;
        int penalty = RY + LN;
        if(penalty < mpen){
            ans = n;
            mpen = penalty;
        }

        return ans;
    }
};