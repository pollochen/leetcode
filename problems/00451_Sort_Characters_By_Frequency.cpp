// priority queue with frequency map
// Runtime: 8 ms, faster than 94.68% of C++ online submissions for Sort Characters By Frequency.
// Memory Usage: 8.5 MB, less than 40.70% of C++ online submissions for Sort Characters By Frequency.
class Solution {
public:
    string frequencySort(string s) {
        int freqs[128];
        memset(&freqs, 0, sizeof(freqs));
        for (int i = 0; i < s.length(); i++) {
            freqs[s[i]]++;
        }
        
        // pair< freq, char>
        priority_queue<pair<int, char>> pq; // max heap sorted by frequency
        for (int i = 0; i < 128; i++) {
            if (freqs[i] > 0) {
                pq.push({freqs[i], i});
            }
        }
        string result;
        while (pq.empty() == false) {
            char ch = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            for (int i = 0; i < freq; i++) {
                result += ch;
            }
        }
        return result;
    }
};