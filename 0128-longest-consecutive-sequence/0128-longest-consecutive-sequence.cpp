class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans =0;
        for(int i:nums){
            int cnt=1;
            for(int left =i-1;s.find(left)!=s.end();left--)
                cnt++, s.erase(left);
            for(int right =i+1;s.find(right)!=s.end();right++)
                cnt++, s.erase(right);
            ans =max(ans, cnt);
        }
        return ans;
    }
};