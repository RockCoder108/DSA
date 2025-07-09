class Solution {
public:
    int solve(int i,int n,int prev,vector<int>& arr,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int a = solve(i+1,n,prev,arr,dp);
        int b = -1e9;
        if(prev==-1 or arr[i]>arr[prev]){
            b = 1+solve(i+1,n,i,arr,dp);
        }
        return dp[i][prev+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return solve(0,n,-1,arr,dp);
    }
};