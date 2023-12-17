// https://www.codingninjas.com/studio/problems/good-numbers_625508?leftPanelTabValue=SUBMISSION
// Category : Easy

#include <bits/stdc++.h>
#include <vector>

class solution {
    public: 
        vector<int> goodNumbers(int a, int b, int digit) {
            vector<int> ans;
            
            for ( int i = a; i <= b; i++ ) {
                int sum = -1;
                int num = i;
                bool right = true;
                while ( num ) {
                    int curr = num % 10;
                    if ( curr == digit ) {
                        right = false;
                        break;
                    }

                    if ( curr <= sum ) {
                        right = false;
                        break;
                    }

                    num = num / 10;
                    if ( sum == -1 ) sum = curr;
                    else sum += curr;
                }
                if ( right ) ans.push_back(i);
            }

            return ans;
        }

};
