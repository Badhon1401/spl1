#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
ifstream fn;
ofstream ft;
fstream fo;
struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
//private:
	//Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}
Node* root;
	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i<static_cast<int>(word.size()); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i <static_cast<int>(word.size()); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}
	// void trieUpdate(string word);
	// bool trieSearch(string word);

}tr;
void trieUpdate(string word){
	//fout.open("temp.dat",ios::binary);
	ft.open("tmp.dat",ios::binary);
    fn.open("trie.dat",ios::binary);
	fn.read((char*)&tr,sizeof(tr));
	tr.insert(word);
	ft.write((char*)&tr,sizeof(tr));
     fn.close();
     ft.close();
     remove("trie.dat");
     rename("tmp.dat","trie.dat");
}
bool trieSearch(string word){
	fn.open("trie.dat",ios::binary);
	fn.read((char*)&tr,sizeof(tr));
	bool b=tr.search(word);;
	fn.close();
	// fo.open("trie.dat",ios::binary|ios::out|ios::in);
	// fo.read((char*)&tr,sizeof(tr));
	// fo.close();
	return b;
}