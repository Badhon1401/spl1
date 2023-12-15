#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    bool removeRecursive(TrieNode* current, const string& str, size_t depth) {
    if (depth == str.length()) {
        if (current->isEndOfWord) {
            current->isEndOfWord = false;
            return current->children.empty();  
        }
        return false;
    }

    char ch = str[depth];
    if (current->children.find(ch) != current->children.end()) {
        bool shouldRemoveChild = removeRecursive(current->children[ch], str, depth + 1);
        if (shouldRemoveChild) {
            delete current->children[ch];
            current->children.erase(ch);
            return current->children.empty() && !current->isEndOfWord;
        }
    }

    return false;
}


public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& str) {
        TrieNode* current = root;
        for (char ch : str) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const string& str) {
        TrieNode* current = root;
        for (char ch : str) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    void remove(const string& str) {
        if (str.empty()) {
            return;
        }
        removeRecursive(root, str, 0);
    }
}product_id_Trie,product_data_Trie,user_id_Trie,user_data_Trie;
