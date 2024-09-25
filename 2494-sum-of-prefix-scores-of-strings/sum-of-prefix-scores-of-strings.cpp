// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
//         int n = words.size();
//         unordered_map<string, int> mp;
//         string p = "";

//         vector<int> ans(n, 0);
//         for (int i = 0; i < n; i++) {
//             p = "";
//             for (int j = 0; j < words[i].size(); j++) {
//                 p += words[i][j];
//                 mp[p]++;
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             p = "";
//             for (int j = 0; j < words[i].size(); j++) {
//                 p += words[i][j];

//                 sum += mp[p];
//             }

//             ans[i] = sum;
//         }
//         return ans;
//     }
// };

// =============TLE--- So use Trie data
// structure=========

class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {
            nullptr};  // 26 letters for lowercase English characters
        int count = 0; // Stores how many times the prefix is encountered
    };
    class Trie {
    public:
        TrieNode* root;
        Trie() { root = new TrieNode(); }
        // insert a word into trie and upfate the count
        void insert(string word) {
            TrieNode* Node = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (!Node->children[index]) {
                    Node->children[index] = new TrieNode();
                }
                Node = Node->children[index];
                Node->count++; // Increment count for the current prefix
            }
        }

        int PrefixScore(string word) {
            TrieNode* Node = root;
            int score = 0;
            for (char ch : word) {
                int index = ch - 'a';
                if (!Node->children[index]) {
                    break;
                }
                Node = Node->children[index];
                score += Node->count; // Increment count for the current prefix
            }
            return score;
        }
    };

    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        for (auto word : words) {
            trie.insert(word);
        }
        vector<int> result;
        for (auto word : words) {
            result.push_back(trie.PrefixScore(word));
        }
        return result;
    }
};
