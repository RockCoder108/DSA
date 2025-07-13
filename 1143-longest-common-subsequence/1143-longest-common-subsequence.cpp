class Solution {
public:
    int solve(int i,int j,int n,int m,string&s1,string&s2,vector<vector<int>>&dp){
        if(i==n or j==m) return 0;
        int a = -1e9;
        int b = -1e9;
        int c = -1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            a = 1+solve(i+1,j+1,n,m,s1,s2,dp);
        }else{
            b = solve(i+1,j,n,m,s1,s2,dp);
            c = solve(i,j+1,n,m,s1,s2,dp);
        }
        return dp[i][j] = max({a,b,c});
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,s1,s2,dp);
    }
};

// refence 