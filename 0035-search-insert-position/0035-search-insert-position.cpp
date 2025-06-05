class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n =nums.size();
        int low=0,high=n-1;
        int ans=0;
        if(nums[n-1]<target){
            return n;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=target){
                ans=mid;
                high = mid-1;
            }else{
                //ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};