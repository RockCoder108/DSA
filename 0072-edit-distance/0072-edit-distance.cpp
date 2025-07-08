class Solution {
public:
    int solve(int i,int j,int n,int m,string&s1,string&s2,vector<vector<int>>&dp){
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!= -1) return dp[i][j];
        if(s1[i]==s2[j]){
            int a = solve(i+1,j+1,n,m,s1,s2,dp);
            return dp[i][j]=a;
        }else{
            int a = 1+solve(i+1,j+1,n,m,s1,s2,dp);
            int b = 1+solve(i+1,j,n,m,s1,s2,dp);
            int c = 1+solve(i,j+1,n,m,s1,s2,dp);
            return dp[i][j]=min({a,b,c});
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,n,m,s1,s2,dp);
    }
};