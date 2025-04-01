class Solution {
public:

    bool fun(vector<int>& piles, int mid, int h){
        int hours=0;

        for(auto x :  piles){
            hours += x/mid;
            if(x%mid != 0){
                hours++;
            }
        }
        return hours <= h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int low =1;
        int high = *max_element(piles.begin(), piles.end());

        while(low<high){
            int mid = low+ (high-low)/2;

            if(fun(piles, mid, h)){
                high=mid;
            }else{
                low=mid+1;
            }
        }

        return low;
        
    }
};