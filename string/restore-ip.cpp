// https://leetcode.com/problems/restore-ip-addresses/
#include<string>
#include<vector>

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        restoreIP(s, ans, 0, "", 0);
        return ans;
    }

    void restoreIP(string ip, vector<string> &ans, int idx, string res, int count) {
        if (count > 4)
            return;
        if (count == 4 && idx == ip.length())
            ans.push_back(res);

        for (int i = 1; i < 4; i++) {
            if (idx + i > ip.length())
                break;
            string s = ip.substr(idx, i);
            if ((s[0] == '0' && s.length() > 1) || (i == 3 && s >= "256"))
                continue;
            restoreIP(ip, ans, idx + i, res + s + (count == 3 ? "" : "."), count + 1);
        }
    }
};
