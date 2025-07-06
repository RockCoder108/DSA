class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i==n-1 and j==m-1) return arr[i][j];
        if(i==n or j==m) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];

        int right =solve(i,j+1,n,m,arr,dp) + arr[i][j];
        int down =solve(i+1,j,n,m,arr,dp)+arr[i][j];

        return dp[i][j]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,arr,dp);
    }
};