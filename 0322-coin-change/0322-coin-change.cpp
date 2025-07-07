class Solution {
public:

    int solve(int i,int n,int amt,vector<int>& arr,vector<vector<int>>&dp){
        if(amt<0) return 1e9;
        if(i==n) return 1e9;
        if(amt==0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];

        int not_pick= solve(i+1,n,amt,arr,dp);
        int pick= 1+solve(i,n,amt-arr[i],arr,dp);
        return dp[i][amt]=  min(not_pick,pick);
    }
    int coinChange(vector<int>& arr, int amt) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(amt+1,-1));
        int ans = solve(0,n,amt,arr,dp);
        if(ans>=1e9){
            return -1;
        }else{
            return ans;
        }
    }
};


// supply is 