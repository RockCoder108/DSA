class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // int buy=INT_MAX,sell=0;
        // for(int i=0;i<prices.size();i++){
        //     if(buy>prices[i]){
        //         buy=prices[i];
        //     }else{
        //         sell = max(sell,prices[i]-buy);
        //     }
        // }
        // return sell;

        
        int n = arr.size();
        int ans =0;
        int mini = arr[0];
        for(int i=1;i<n;i++){
            int profit = arr[i]-mini;
            ans = max(ans,profit);
            mini = min(mini,arr[i]);
        }
        return ans;
    }
};