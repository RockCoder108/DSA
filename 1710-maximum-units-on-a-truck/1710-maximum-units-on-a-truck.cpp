class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(auto &it:boxTypes){
            swap(it[0],it[1]);
        }
        sort(boxTypes.begin(),boxTypes.end());
        int sum=0;
        int size=boxTypes.size();
        for(int x=size-1;x>=0;x--){
            if(truckSize>0){
                if(boxTypes[x][1]<=truckSize){
                    sum+=boxTypes[x][1]*boxTypes[x][0];
                    truckSize=truckSize-boxTypes[x][1];
                }
                else if(boxTypes[x][1]>truckSize){
                    sum+=truckSize*boxTypes[x][0];
                    return sum;
                }
            }
        }
        return sum;
    }
};