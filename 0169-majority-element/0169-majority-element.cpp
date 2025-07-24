class Solution {
public:
    int majorityElement(vector<int>& arr) {
        // int element=nums[0], count=1;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]!=element){
        //         count--;
        //         if(count==0){
        //             element=nums[i];
        //             count++;
        //         }
        //     }else{
        //         count++;
        //     }
        // }
        // return element;

        int n =arr.size();
        int num = arr[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(arr[i]==num){
                count++;
            }else{
                count--;
                if(count==0){
                    num = arr[i];
                    count++;
                }
            }
        }
        return num;
    }
};

