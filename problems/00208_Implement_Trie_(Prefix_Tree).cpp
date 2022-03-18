// https://ithelp.ithome.com.tw/articles/10248152
class Trie {
private:
    Trie *children[26];
    bool  is_leaf;
public:
    Trie() {
        memset(children, 0, sizeof(children));
        is_leaf = false;
    }

    void insert(string word) {
        Trie *t = this;
        int idx;
        for (int i = 0; i < word.length(); i++) {
            idx = word[i] - 'a';
            if (t->children[idx] == NULL) {
                t->children[idx] = new Trie();
            }
            t = t->children[idx];
        }
        t->is_leaf = true;
    }

    bool search(string word) {
        Trie *t = this;
        int idx;
        for (int i = 0; i < word.length(); i++) {
            idx = word[i] - 'a';
            if (t->children[idx] == NULL) {
                return false;
            }
            t = t->children[idx];
        }
        return (t != NULL && t->is_leaf == true);
    }

    bool startsWith(string prefix) {
        Trie *t = this;
        int idx;
        for (int i = 0; i < prefix.length(); i++) {
            idx = prefix[i] - 'a';
            if (t->children[idx] == NULL) {
                return false;
            }
            t = t->children[idx];
        }
        return true;
    }
};