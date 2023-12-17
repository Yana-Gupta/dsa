// https://www.codingninjas.com/studio/problems/print-subsequences_8416366?leftPanelTabValue=SUBMISSION
// Category : Medium

void generate (int idx, string temp, vector<string>& ans, string s, int n) {
    if ( idx == n ) {
        ans.push_back(temp);
        return;
    }
    // I am not taking
    generate( idx+1, temp, ans, s, n);

    // I am taking

    temp += string(1, s[idx]);
    generate( idx+1, temp, ans, s, n);

}

vector<string> generateSubsequences(string s) {
    vector<string> ans;
    string temp = "";

    generate(0, temp, ans, s, s.length());
    return ans;
}