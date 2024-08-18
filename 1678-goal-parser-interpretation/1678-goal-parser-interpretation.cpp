class Solution {
public:
    string interpret(string command) {
        int n = command.length();
        string str;
        for (int i = 0; i < n; i++) {
            if (command[i] == 'G') {
                str.push_back('G');
            }
            else if (command[i] == '(' && i + 1 < n && command[i + 1] == ')') {
                str.push_back('o');
                i++; 
            }
            else if (i + 3 < n && command.substr(i, 4) == "(al)") {
                str.append("al");
                i += 3; 
            }
        }
        return str;
    }
};
