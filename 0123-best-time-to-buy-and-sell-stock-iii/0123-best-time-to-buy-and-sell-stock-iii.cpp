class Solution {
public:
    int solve(int i,int n,int buy,int tras, vector<int>&arr,vector<vector<vector<int>>>&dp){
        if(tras==2) return 0;
        if(i==n) return 0;
        if(dp[i][buy][tras]!=-1) return dp[i][buy][tras];
        if(buy == 0){
            int a = -arr[i]+solve(i+1,n,1,tras,arr,dp);
            int b= solve(i+1,n,0,tras,arr,dp);
            return dp[i][buy][tras]=max(a,b);
        }else{
            int a = arr[i]+solve(i+1,n,0,tras+1,arr,dp);
            int b = solve(i+1,n,1,tras,arr,dp);
            return dp[i][buy][tras]=max(a,b);
        }
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,n,0,0,arr,dp);
    }
};

// n*2*3