// https://leetcode.com/problems/maximum-good-subarray-sum/description/
// LeetCode Biweekly Contest 123


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, long long> mp;
        long long pre = 0;
        long long ans = LLONG_MIN;
        
        for ( auto i = 0; i < n; i++ ) {
            if ( !mp.count(nums[i]) ) {
                mp[nums[i]] = LLONG_MAX;
            }
            
            if ( mp.find(k + nums[i]) != mp.end() && mp[k+nums[i]] != LLONG_MAX ) {
                ans = max(ans, (long long)nums[i] + pre - mp[k+ nums[i]]);
            }
            
            if ( mp.find(-k + nums[i]) != mp.end() && mp[-k+nums[i]] != LLONG_MAX ) {
                ans = max(ans, (long long)nums[i] + pre - mp[-k + nums[i]]);
            }
            
            mp[nums[i]] = min(pre, mp[nums[i]]);
            
            
            pre += (long long)nums[i];

        }
        
        return ans == LLONG_MIN ? 0 : ans;
    }
};