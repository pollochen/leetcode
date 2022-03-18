class Solution {
public:
    string interpret(string command) {
        int len = command.length();
        string result ="";
        int i = 0;
        while (i < len) {
            if (command[i] == 'G') result += string(1, 'G');
            else if (command[i] == '(') {
                if (command[i+1] == ')') {
                    result += string(1, 'o');
                    i++;
                } else {
                    result += "al";
                    i += 2;
                }
            }
            i++;
        }
        return result;
    }
};