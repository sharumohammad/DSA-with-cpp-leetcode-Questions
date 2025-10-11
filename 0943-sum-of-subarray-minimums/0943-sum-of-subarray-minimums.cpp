class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> ple(n),nle(n);
        stack<int> s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>=arr[i]) s1.pop();
            if(!s1.empty()) ple[i]=s1.top();
            else ple[i]=-1;
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>arr[i]){
                s2.pop();
            }
            if(!s2.empty()){
                nle[i]=s2.top();
            }
            else nle[i]=n;
            s2.push(i);
        }
        long long sum=0;
        int MOD=1e9+7;
        for(int i=0;i<n;i++){
            long long lcount=i-ple[i];
            long long rcount=nle[i]-i;
            long long subarray=(lcount*rcount)%MOD;
            long long cont=(subarray*arr[i])%MOD;
            sum=(sum+cont)%MOD;
        }
        return sum;
    }
};