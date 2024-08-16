class Solution {
public:
    bool isPalindrome(string s) {
        string filtered_str;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {
                if (c >= 'A' && c <= 'Z') {
                    c = c - 'A' + 'a';
                }
                filtered_str.push_back(c);
            }
        }

        int i = 0;
        int j = filtered_str.length() - 1;
        while (i < j) {
            if (filtered_str[i] != filtered_str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
