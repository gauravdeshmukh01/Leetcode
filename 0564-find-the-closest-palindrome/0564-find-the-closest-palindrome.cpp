class Solution {
public:
    string nearestPalindromic(string n) {
      int length = n.size();
        if (n == "1") return "0";  
        
        long long first_half = stoll(n.substr(0, (length + 1) / 2));
        set<long long> candidates;
        
        candidates.insert(getPalindrome(first_half, length % 2));
        
        candidates.insert(getPalindrome(first_half + 1, length % 2));
        
        candidates.insert(getPalindrome(first_half - 1, length % 2));
        
        candidates.insert((long long)pow(10, length - 1) - 1);  
        candidates.insert((long long)pow(10, length) + 1);      
        
        long long min_diff = LLONG_MAX, result = -1, original_number = stoll(n);
        candidates.erase(original_number); 
        
        for (long long candidate : candidates) {
            long long diff = abs(candidate - original_number);
            if (diff < min_diff || (diff == min_diff && candidate < result)) {
                min_diff = diff;
                result = candidate;
            }
        }
        
        return to_string(result);
    }

private:
    long long getPalindrome(long long first_half, bool is_odd_length) {
        string first_half_str = to_string(first_half);
        string reversed_half = string(first_half_str.rbegin() + (is_odd_length ? 1 : 0), first_half_str.rend());
        return stoll(first_half_str + reversed_half);
    }
};