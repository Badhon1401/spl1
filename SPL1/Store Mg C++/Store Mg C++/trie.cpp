#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    bool flag = false;

    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < static_cast<int>(word.size()); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < static_cast<int>(word.size()); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

     void remove(string word) {
        Node* node = root;
        for (int i = 0; i < static_cast<int>(word.size()); i++) {
            if (!node->containKey(word[i])) {
                cout << "Word not found in the Trie." << endl;
                return;
            }
            node = node->get(word[i]);
        }
        if (node->isEnd()) {
            node->setEnd();  // Mark the end of word as false (deleted)
            cout << "Word \"" << word << "\" deleted from the Trie." << endl;
        } else {
            cout << "Word not found in the Trie." << endl;
        }
    }

}tr;
