// https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    void solve ( string s, vector<string>& wordDict, vector<string>& ans, int idx, string temp ) {
        if ( idx == s.length() ) {
            if ( temp.length() ) ans.push_back(temp);
        }
        string x = "";
        for ( auto i = idx; i < s.length(); i++ ) {
            x += s[i];
            auto itr = find(wordDict.begin(), wordDict.end(), x);
            if ( itr != wordDict.end() ) {
                if ( temp.length() > 0 ) solve(s, wordDict, ans, i + 1, temp + " " + x);
                else solve(s, wordDict, ans, i + 1, x);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        solve(s, wordDict, ans, 0, "");
        return ans;
    }
};