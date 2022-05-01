// brute forace with 1 hash map
// Runtime: 6 ms, faster than 44.57% of C++ online submissions for Encode and Decode TinyURL.
// Memory Usage: 7.4 MB, less than 12.86% of C++ online submissions for Encode and Decode TinyURL.
class Solution {
    unordered_map<string, string> m_umap_dec;
    string    m_string;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (m_string.length() == 0) {
            m_string = "A";
        } else {
            int len = m_string.length();
            if (m_string[len - 1] != 'Z') {
                m_string[len - 1]++;
            } else {
                m_string += "A";
            }
        }
        m_umap_dec[m_string] = longUrl;
        return m_string;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m_umap_dec[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));