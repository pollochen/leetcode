// frequency map
// Runtime: 3 ms, faster than 88.18% of C++ online submissions for Bulls and Cows.
// Memory Usage: 6.5 MB, less than 74.09% of C++ online submissions for Bulls and Cows.
class Solution {
public:
    string getHint(string secret, string guess) {
        int map[10];
        memset(map, 0, sizeof(map));
        
		// build digit frequency map for secret
        int len = secret.length();
        for (int i = 0; i < len; i++) {
            map[secret[i] - '0']++;
        }
        
        int bull = 0;
        int cow = 0;
		// we need to scan for bull first
        for (int i = 0; i < len; i++) {
            if (guess[i] == secret[i]) {
                bull++;
                map[secret[i] - '0']--;
            }
        }
		// we need to scan for cow
        for (int i = 0; i < len; i++) {
            if (guess[i] != secret[i]) {
				// only when the frequency of the digit is available
                if (map[guess[i] - '0'] > 0) {
                    cow++;
                    map[guess[i] - '0']--;
                }
            }
        }        
        string result = to_string(bull) + "A" + to_string(cow) + "B";
        return result;
    }
};