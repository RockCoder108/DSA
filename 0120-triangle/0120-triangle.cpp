class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(i==n-1){
            return arr[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int down=arr[i][j]+solve(i+1,j,n,arr,dp);
        int downright= arr[i][j] + solve(i+1,j+1,n,arr,dp);
        return dp[i][j]=min(down,downright);
    }
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,n,arr,dp);
    }
};

// i+1,j
// i+1,j+1
// (i==n-1) arr[i][j] ya (i==n) return 0 not 1e9 this why 