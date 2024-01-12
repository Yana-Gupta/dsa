// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Status = Medium


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();

        vector<int> cummuSumFromFront(n+1, 0);
        vector<int> cummuSumFromBack(n+1, 0);

        sum = 0;
        for ( int i = 0; i < n; i++ ) {
            sum += cardPoints[i];
            cummuSumFromFront[i+1] = sum;
        }

        sum = 0;
        for ( int i = n - 1; i >= 0; i-- ) {
            sum += cardPoints[i];
            cummuSumFromBack[i] = sum;
        }

        sum = 0;

        reverse(cummuSumFromBack.begin(), cummuSumFromBack.end());

        for ( int i = 0; i <= k; i++ ) {
            sum = max( sum , (cummuSumFromBack[k-i] + cummuSumFromFront[i]) );
        }

        return sum;
    }
};