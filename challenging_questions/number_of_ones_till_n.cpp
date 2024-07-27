// https://leetcode.com/problems/number-of-digit-one/description/


// Non - DP version 
// Time Complexity - O(no of digits)
// Space Complexity - O(1)

class Solution {
public:
    int dp[10];
    double ncr(int n, int i) {
        if ( n == i || i == 0 ) return 1;
        return (((double)n/(double)i)*ncr(n-1, i-1));
    }
    int solve(int i) {
        int n = i;
        int res = 0;
        for ( auto k = 1; k <= n; k++ ) {
            int temp = ncr(n-1, k-1)*pow(9, n-k);
            if ( k != n )
                temp += ncr(n-1, k)*8*pow(9, n-k-1);
            temp = temp*k;
            res += temp;
        }
        return res;
    }
    pair<int, int> countdigits(int n) {
        int d = 0;
        int t = 0;
        while ( n ) {
            t = n%10; n = n /10;
            d++;
        }
        return {d, t};
    }
    int solve1(int n ) {
        if ( n < 10 ) return n > 0;
        auto it = countdigits(n);
        int d = it.first, t = it.second;

        int res = dp[d-1];
        
        if ( t == 1 ) res += n%(int)pow(10, d-1) + 1;
        else res += pow(10, d-1);

        res += (t-1)*dp[d-1];

        res += solve1(n%(int)pow(10, d-1));
        return res;
    }
    int countDigitOne(int n) {
        if ( n < 10 ) return n > 0;
        dp[1] = 1;
        dp[2] = 20;
        for ( auto i = 3; i <= 9; i++ ) {
            dp[i] += dp[i-1] + solve(i);
        }

        return solve1(n);
    }
};


// Dynamic Programming Solution 
class Solution {
public:
    int dp[11][11][2];
    int solve(string &s, int idx,int cnt, bool flag){
        if(idx == s.size())
            return cnt;
        
        if(dp[idx][cnt][flag]!=-1) return dp[idx][cnt][flag];
        char ub = '9';
        if (flag) ub = s[idx];
        int count = 0;
        for(char x = '0'; x <= ub; x++){
            bool new_flag = flag & (x == ub);
            int new_cnt = cnt;
            if(x == '1') new_cnt++;
            count += solve(s, idx+1, new_cnt, new_flag);
        }
        return dp[idx][cnt][flag] = count;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        return solve(s,0,0,true);
    }
};
