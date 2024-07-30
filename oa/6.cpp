// Count the number of subarray where whose product has odd number of divisors

// Constrains - n = 2*10^5
// A[i] <= 200


#include <bits/stdc++.h>

using namespace std;
int main(){
    vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long> b(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<prime.size();j++){
            int cnt=0;
            while(a[i]%prime[j]==0){
                cnt+=1;
                a[i]/=prime[j];
            }
            if(cnt%2) b[i]|=(1LL<<j); 
        }
    }
    map<long long,int> cnt;
    cnt[0]+=1;
    long long res=0, sum=0;
    for(int i=0;i<n;i++){
        res += cnt[b[i]];
        sum^=b[i];
        cnt[sum]+=1;
    }
    cout<<res;
    return 0;
}