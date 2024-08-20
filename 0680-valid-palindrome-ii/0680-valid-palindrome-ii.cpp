class Solution {
public:
    bool checkpalindrome(string s, int i, int j) {
        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return checkpalindrome(s, i + 1, j) ||
                       checkpalindrome(s, i, j - 1);
            }
        }
        return true;
    }
};