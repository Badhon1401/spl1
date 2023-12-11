#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode() : isEnd(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& key) {
        TrieNode* current = root;
        for (char ch : key) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEnd = true;
    }

    bool search(const string& key) const {
        TrieNode* current = root;
        for (char ch : key) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current != nullptr && current->isEnd;
    }

    bool remove(const string& key) {
        TrieNode* current = root;
        TrieNode* parent = nullptr;
        char lastChar = '\0';

        for (char ch : key) {
            if (current->children.find(ch) == current->children.end()) {
                return false; 
            }
            parent = current;
            current = current->children[ch];
            lastChar = ch;
        }

        if (current != nullptr && current->isEnd) {
            if (current->children.empty()) {
                delete current;
                parent->children.erase(lastChar);
            } else {
                current->isEnd = false;
            }
            return true; 
        }

        return false; 
    }
}tpg,tpfb,tpel,tpbs,tpfsb,tph,tpha,trieUser;