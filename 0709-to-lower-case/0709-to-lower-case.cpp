class Solution {
public:
    string toLowerCase(string s) {
        string str;
        int n = s.length();
        int ans;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                ans = s[i] - 'A' + 'a';
                str.push_back(ans);
            } else
                str.push_back(s[i]);
        }

        return str;
    }
};
