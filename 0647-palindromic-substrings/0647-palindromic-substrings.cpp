class Solution {
public:
    int ExpandAroundIndex(string s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalcount = 0;
        int n = s.length();

        for (int center = 0; center < n; center++) {
            // odd
            int oddkaans = ExpandAroundIndex(s, center, center);
            totalcount = totalcount + oddkaans;
            // even
            int evenkaans = ExpandAroundIndex(s, center, center+1);
            totalcount = totalcount + evenkaans;
        }

        return totalcount;
    }
};