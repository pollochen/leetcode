// Runtime: 91 ms, faster than 77.35% of C++ online submissions for Design Authentication Manager.
// Memory Usage: 30.2 MB, less than 65.65% of C++ online submissions for Design Authentication Manager.
class AuthenticationManager {
private:
    int m_ttl;
    unordered_map<string, int> umap; // id, expire
public:
    AuthenticationManager(int timeToLive) {
        m_ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        umap[tokenId] = currentTime + m_ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if (umap.count(tokenId) == 0) {
            return;
        }
		// If there are no unexpired tokens with the given tokenId, the request is ignored, and nothing happens.
        if (umap[tokenId] > currentTime) {
            umap[tokenId] = currentTime + m_ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto &x : umap) {
            if (x.second > currentTime) count++;
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */