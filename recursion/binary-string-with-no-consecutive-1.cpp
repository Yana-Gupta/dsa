// https://www.codingninjas.com/studio/problems/-binary-strings-with-no-consecutive-1s._893001?leftPanelTabValue=PROBLEM
// Category : Medium

void generate (int N, string &str, int ind, vector<string> &ans) {
    if ( ind == N ) {
        ans.push_back(str);
        return;
    }

    if ( str[ind - 1] == '1' ) {
        str[ind] = '0';
        generate(N, str, ind + 1, ans);
    }

    if (str[ind - 1] == '0') {
        str[ind] = '1';
        generate(N, str, ind + 1, ans);
        str[ind] = '0';
        generate(N, str, ind + 1, ans);
    }
}

vector<string> generateString(int N) {
    vector<string> ans;
    if ( N == 0 ) return ans;
    string str(N, '0');
    str[0] = '0';
    generate(N, str, 1, ans);

    str[0] = '1';
    generate(N, str, 1, ans);
    sort(ans.begin(), ans.end());

    return ans;
}