class Solution {
public:
    

    struct Trie {
        struct TrieNode {
            TrieNode() : terminal(false) {}
            map<char, TrieNode*> children;
            bool terminal;        
        };
        
        TrieNode* root;

        Trie() : root(new TrieNode()) {}

        void insert(string const& s) {
            TrieNode* node = root;
            for(char const& c : s) {
                if(!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->terminal = true;
        }
        
        TrieNode* search(string_view const& s) {
            auto node = root;
            for(char const& c : s) {
                if(!node->children.count(c)) {
                    return nullptr;
                }
                node = node->children[c];
            }
            return node->terminal ? node : nullptr;
        }

    };

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(string const& word : wordDict) {
            trie.insert(word);
        }

        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        string_view sv(s);
        for(int i = 1; i <= s.size() ; ++i) {
            for(int j=0; j < i && !dp[i]; ++j) {                
                dp[i] = dp[j] ? trie.search(sv.substr(j,i-j)) != nullptr : false;                
            } 
        }
        return dp[s.size()];
    }
};