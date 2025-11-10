class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, prev = 0;
        for (int x : nums) {
            if (x > 0 && x > prev) ans++;
            prev = x;
            if (x == 0) prev = 0; // reset after zeros
        }
        return ans;
    }
};
