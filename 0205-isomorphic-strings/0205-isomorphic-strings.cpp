class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0}; // mapping of each char of lang 's' to lang 't'
        bool istCharMapped[256] = {0}; // stores if t[i] char is already mapped with s[i].

        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]] == 0 && istCharMapped[t[i]] == 0){
                hash[s[i]] = t[i];
                istCharMapped[t[i]] = true;
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        return true;
    }
};