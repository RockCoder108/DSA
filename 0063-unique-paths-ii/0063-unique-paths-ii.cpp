class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i==n-1 and j==m-1) return 1;
        if(i==n or j==m) return 0;
        if(arr[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(i,j+1,n,m,arr,dp);
        int down=solve(i+1,j,n,m,arr,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        if(arr[0][0]==1 or arr[n-1][m-1]==1) return 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return solve(0,0,n,m,arr,dp);
    }
};