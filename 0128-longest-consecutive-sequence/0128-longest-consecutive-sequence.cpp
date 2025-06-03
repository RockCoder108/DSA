class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int ans=0,count=0;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]==1 || nums[i+1]-nums[i]==0){
                if(nums[i+1]-nums[i]==1){
                    count++;
                }
            }else{
                count=0;
            }
            ans = max(ans,count);
        }
        return ans+1;
    }
};