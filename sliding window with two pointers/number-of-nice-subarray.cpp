// https://leetcode.com/problems/count-number-of-nice-subarrays/
// https://www.codingninjas.com/studio/problems/count-distinct-subarrays-with-at-most-k-odd-elements_1069335

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0; 
        int odd = 0;
        int count = 0;
        int total = 0;
        int right = 0;
        int n = nums.size();

        while ( right < n ) {

            if ( nums[right] & 1 ) {
                odd++;
                if ( odd >= k ) {
                    count = 1;
                    while ( !( nums[j++] & 1 ) ) {
                        count++;
                    }
                    total += count;
                }
            } else if ( odd >= k ) {
                total += count;
            }
            right++;
        }

        return total;
        
    }
};    