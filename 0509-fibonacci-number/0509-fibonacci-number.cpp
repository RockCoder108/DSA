class Solution {
public:
    int solve(int n){
        if(n<=1) return n;
        //if(dp[n]!=-1) return dp[n];
        int a = solve(n-1);
        int b= solve(n-2);
        return a+b;
    }
    int fib(int n) {
        //vector<int>dp(n+1,-1);
        return solve(n);
    }
};


// 