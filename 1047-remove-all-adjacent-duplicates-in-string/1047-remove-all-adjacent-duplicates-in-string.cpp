class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string str = "";
        for (int i = 0; i < n; i++) {
            if (str.empty() || str[str.length() - 1] != s[i]) {
                str.push_back(s[i]);
            } else {
                str.pop_back();
            }
        }
       return str;
    }
};