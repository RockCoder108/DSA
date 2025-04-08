class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int left = 0;
        int right = n-1; 
        while(left<=right){
            if(vec[left].first+vec[right].first==target){
                return {vec[left].second,vec[right].second};
            }
            if(vec[left].first+vec[right].first>target){
                right--;
            }else{
                left++;
            }
        }
        return {};
    }
};