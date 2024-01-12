// https://www.codingninjas.com/studio/problems/the-celebrity-problem_982769?leftPanelTabValue=SUBMISSION
// https://leetcode.com/problems/find-the-celebrity/

#include <bits/stdc++.h> 

int findCelebrity(int n) {
    queue<int> ids;
    int left = 0;

    while ( left < n ) {
        while ( !ids.empty() && knows( ids.front(), left ) ) {
            ids.pop();
        }
        ids.push(left);
        left++;
    }

    int top = ids.front();
    

    for ( int i = 0; i < n; i++ ) {
        if ( i != top &&( knows( top, i ) || !(knows ( i , top ))) ) return -1;
    }

    return top;
}