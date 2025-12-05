class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long total = 0;
        for (int x : nums)
            total += x;
        return (total % 2 == 0) ? (nums.size() - 1) : 0;
    }
};