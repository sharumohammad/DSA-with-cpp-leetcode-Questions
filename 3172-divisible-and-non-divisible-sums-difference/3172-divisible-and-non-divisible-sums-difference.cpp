class Solution {
public:
    int differenceOfSums(int n, int m) {
        int tsum=n*(n+1)/2;
        int dCount=n/m;
        int dSum=m*dCount*(dCount+1)/2;
        return tsum-2*dSum;
    }
};