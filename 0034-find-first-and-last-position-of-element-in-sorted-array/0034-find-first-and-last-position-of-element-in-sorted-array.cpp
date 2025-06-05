class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2);
        v[0]=-1;
        v[1]=-1;
        auto pos1=lower_bound(nums.begin(),nums.end(),target);
        auto pos2=upper_bound(nums.begin(),nums.end(),target);
        
        // if(pos1>0){
        //     v[0]=pos1-nums.begin();
        // }
        // if(pos2>0){
        //     v[1]=pos2-nums.begin();
        // }
        
        if (pos1 != nums.end() && *pos1 == target) {
        v[0] = pos1 - nums.begin();
        v[1] = pos2 - nums.begin() - 1;
    }




        //v[0]=pos1-nums.begin();
        //v[1]=pos2-nums.begin();
        return v;

    }
};