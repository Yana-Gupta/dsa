// https://www.codingninjas.com/studio/problems/count-substring-with-abc_8160465?leftPanelTabValue=SUBMISSION
// Status : Easy

int countSubstring(string s){
    int counts[3] = {0, 0, 0};
    int left = 0;
    int ans = 0;

    for ( auto i = 0; i < s.length(); i++ ) {
        counts[s[i] - 'a']++;
        while ( counts[0] && counts[1] && counts[2] ) counts[s[left++] - 'a']--;

        ans += left;
    }

    return ans;
}