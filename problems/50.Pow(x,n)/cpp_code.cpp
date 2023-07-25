class Solution {
public:
    double myPow(double x, long int n) {
        if(n==1) return x;
        if(x==1.0 or n==0) return 1.0;
        if(n<0) return 1.0/myPow(x, -n);
        double ans = myPow(x,n/2);
        ans *= ans;
        if(n&1) ans *= x;
        return ans;
    }
};
