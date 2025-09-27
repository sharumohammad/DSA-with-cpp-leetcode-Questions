class Solution {
public:
    int fib(int n){
    //     if(n==0 || n==1) return n;
    

    //   int f1=fibo(n-1);
    //   int f2=fibo(n-2);
    //   int ans=f1+f2;
    //   return ans;  
    // }
    // int fib(int n) {
    //     int r=fibo(n);
    //     return r;
    //}
    if(n<=1) return n;
    int a=0;
    int b=1;
    for(int i=2;i<=n;i++){
        int sum=a+b;
        a=b;
        b=sum;
    }
    return b;

    }
};