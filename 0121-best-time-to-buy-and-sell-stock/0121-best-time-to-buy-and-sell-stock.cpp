class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,sell=0;
        for(int i=0;i<prices.size()-1;i++){
            if(buy>prices[i]){
                buy=prices[i];
            }else{
                sell = max(sell,prices[i]-buy);
            }
        }
        return sell;
    }
};