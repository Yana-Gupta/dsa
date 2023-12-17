// https://leetcode.com/problems/powx-n/
// Category : Easy


class Solution {
public:
    double myPow(double x, int n) {

        double ans = 1;
        long N = n;

        bool flag = false;
        if ( n < 0 ) {
            flag = true;
            N = -1.0*long(n);
        }

        while ( N > 0 ) {
            if ( N % (2) == 1 ) {
                ans = (ans)*(x);
            }
            N = N / 2;
            x = x*x;
        }

        if ( flag ) ans = 1.0 / ans;

        return ans;
    }
};