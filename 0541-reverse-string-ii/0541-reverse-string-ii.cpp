class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();

        for (int i = 0; i < n; i += 2 * k) {
            int j = min(i + k - 1, n - 1);

            int start = i, end = j;
            while (start < end) {
                swap(s[start++], s[end--]);
            }
        }

        return s;
    }
};
