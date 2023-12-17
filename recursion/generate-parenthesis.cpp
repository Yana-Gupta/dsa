// https://www.codingninjas.com/studio/problems/generate-all-parenthesis_920445?leftPanelTabValue=SUBMISSION

void generate(int n, int idx, int open, string& str, vector<string>& ans) {
    if (idx == n && open == 0) {
        ans.push_back(str);
        return;
    }

    if (open == 0) {
        str[idx] = '(';
        open++;
        generate(n, idx + 1, open, str, ans);
    } else if (open > 0) {
        open--;
        str[idx] = ')';
        generate(n, idx + 1, open, str, ans);
        open++;  // Restore the original value of open before the next recursive call

        if (n - idx > open) {
            str[idx] = '(';
            open++;
            generate(n, idx + 1, open, str, ans);
        }
    }
}

vector<string> validParenthesis(int n) {
    vector<string> ans;
    if (n == 0) return ans;

    string temp(2 * n, ' ');
    temp[0] = '(';
    generate(2 * n, 1, 1, temp, ans);

    return ans;
}
