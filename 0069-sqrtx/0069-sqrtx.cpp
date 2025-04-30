class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l=1;
        int r= x/2;
        int ans=0;
        while(l<=r){
            long long  mid=l+(r-l)/2;
            long long s=mid*mid;
           if (s == x) {
                return mid;
            } else if (s < x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};