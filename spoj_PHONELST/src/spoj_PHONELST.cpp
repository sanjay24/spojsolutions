#include <vector>
#include <map>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define ALPHABET_SIZE (10)
#define CHAR_TO_INDEX(c) ((int)c - (int)'0')

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isLeaf;
}Trie;

TrieNode* getNode() {
	TrieNode* node = NULL;
	node = (TrieNode*)malloc(sizeof(TrieNode));
	if(node) {
		for(int i=0; i<ALPHABET_SIZE; ++i) {
			node->children[i] = NULL;
		}
		node->isLeaf = false;
	}

	return node;
}

bool insert(TrieNode* root, string& key) {
	TrieNode* curr = root;
	TrieNode* ptr = root;
	bool prefixFound = false;
	bool newInserted = false;
	for(int i=0; i<key.length(); ++i) {
		int idx = CHAR_TO_INDEX(key[i]);
		if(!curr->children[idx]) {
			//cout<<"inserting "<<key[i]<<endl;
			curr->children[idx] = getNode();
			newInserted = true;
		} else if(curr->isLeaf) {
			prefixFound = true;
		}

		if(i == (key.length() - 1 )) {
			curr->isLeaf = true;
		}
		curr = curr->children[idx];
	}
	if(!newInserted){
		prefixFound = true;
	}

	//cout<<"returing "<<prefixFound<<endl;
	return prefixFound;
}

bool search(TrieNode* root, string& key) {
	TrieNode* curr = root;
	bool found = true;;
	for(int i=0; i<key.length(); ++i) {
		int idx = CHAR_TO_INDEX(key[i]);

		if(curr && curr->children[idx]) {
			curr =  curr->children[idx];
		} else {
			found = false;
			break;
		}
	}
	if(curr->isLeaf) {
		found = true;
	} else {
		found = false;
	}
	return found;
}

int main() {
//	TrieNode* root = getNode();
	//string str = "911";
	//insert(root, str);
	int t;
	cin>>t;
	while(t--) {
		TrieNode* root = getNode();

		int n;
		cin>>n;
		bool pfound = false;
		for(int i=0;i<n; ++i) {
			string str;
			cin>>str;
			if(insert(root, str)) {
				pfound = true;
			}
		}
		if(pfound) {
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	}
	return 0;
}
