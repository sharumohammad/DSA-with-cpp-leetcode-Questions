class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
       int t=0;
       for(int i : batteryPercentages){
        if((i-t)>0) t++;
       } 
       return t;
    }
};