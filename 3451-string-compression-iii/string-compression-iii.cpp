class Solution {
public:
    string compressedString(string word) {
        if (word.empty()) return "";
        
        string comp = "";
        int count = 1;
        
        for (int i = 0; i < word.length(); i++) {
            if (i == word.length() - 1 || word[i] != word[i + 1] || count == 9) {
                comp.push_back('0' + count);
                comp.push_back(word[i]);
                count = 1;
            } else {
                count++;
            }
        }
        
        return comp;
    }
};