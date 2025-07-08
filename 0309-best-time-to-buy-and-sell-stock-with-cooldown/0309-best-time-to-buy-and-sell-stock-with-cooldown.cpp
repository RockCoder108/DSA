class Solution {
public:
    int solve(int i,int n,int buy, vector<int>&arr,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy == 0){
            int a = -arr[i]+solve(i+1,n,1,arr,dp);
            int b= solve(i+1,n,0,arr,dp);
            return dp[i][buy]=max(a,b);
        }else{
            int a = arr[i]+solve(i+2,n,0,arr,dp);
            int b = solve(i+1,n,1,arr,dp);
            return dp[i][buy]=max(a,b);
        }
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,0,arr,dp);
    }
};


// i = i+2