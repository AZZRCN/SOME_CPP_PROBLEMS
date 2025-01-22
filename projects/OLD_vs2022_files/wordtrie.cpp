#include <deque>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class LwordNode {
public:
	LwordNode* next_[26];
	bool end_;
	LwordNode(void) {
		memset(next_, 0, sizeof(next_)); end_ = false;
	}
};
class LwordTrie {
public:
	LwordNode* root;
	LwordTrie() { root = new LwordNode(); }
	void insert(std::string word) {
		LwordNode* p = root;
		for (int cur = 0; cur < word.length(); cur++) {
			if (p->next_[word[cur] - 'a'] == nullptr) {p->next_[word[cur] - 'a'] = new LwordNode();}
			p = p->next_[word[cur] - 'a'];}
		p->end_ = true;
	}
	LwordNode* operator[](std::string word) {
		LwordNode* p = root;
		for (char c : word) {if (p->next_[c - 'a'] == nullptr) { return nullptr; }p = p->next_[c - 'a'];}
		return p;
	}
	bool search(std::string word) {
		LwordNode* p = root;
		for (char c : word) {if (p->next_[c - 'a'] == nullptr) {return false;}p = p->next_[c - 'a'];}
		return p->end_;
	}
	void del(std::string word) {
		LwordNode* p = root;
		for (char c:word) {if (p->next_[c - 'a'] == nullptr) {return ;}p = p->next_[c - 'a'];}
		p->end_ = false;
	}
};
class IONode {
public:
	IONode* next_[2];
	bool end_;
	IONode(void) {
		memset(next_, 0, sizeof(next_)); end_ = false;
	}
};
class intTrie {
public:
	IONode* root;
	int length = 32;
	intTrie() { root = new IONode(); }
	void set_long(int O) { length = O; }
	void insert(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		IONode* p = root;
		for (int cur = 0; cur < word.length(); cur++) {
			if (p->next_[word[cur] - '0'] == nullptr) { p->next_[word[cur] - '0'] = new IONode(); }
			p = p->next_[word[cur] - '0'];
		}
		p->end_ = true;
	}
	bool search(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		IONode* p = root;
		for (char c : word) { if (p->next_[c - '0'] == nullptr) { return false; }p = p->next_[c - '0']; }
		return p->end_;
	}
	void del(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		IONode* p = root;
		for (char c : word) { if (p->next_[c - '0'] == nullptr) { return; }p = p->next_[c - '0']; }
		p->end_ = false;
	}
	unsigned int search_max_xor_num(std::string word) {
		reverse(word.begin(), word.end());
		word.resize(32, '0');
		reverse(word.begin(), word.end());
		//cout << word << endl;
		IONode* p = root;
		unsigned int n = 0;
		int cur = 32;
		int else_num;
		bool else_invalid, this_invalid, flag;
		for (char c : word) {
			cur--;
			else_num = '1' - c;
			else_invalid = p->next_[else_num] != nullptr;
			this_invalid = p->next_[!else_num] != nullptr;
			//cout << else_num << " " << else_invalid << " " << this_invalid << endl;
			if (else_invalid) {
				p = p->next_[else_num];
			}
			else {
				p = p->next_[!else_num];
			}
			//this ^ else = 1
			//None
			//这一位是1，else可用->0
			//不可用->1
			//0,else ->1
			//0,!else->0
			if ((c - '0') ^ else_invalid)
			{
				n |= (1 << cur);
			}
		}
		return n;
	}
};
class MultiNode {
public:
	MultiNode* father;
	vector<MultiNode*> fathers;//fathers[i] = (2^i)th father
	vector<MultiNode*> sons;
	MultiNode(void) {
		father = nullptr;
	}
	MultiNode(MultiNode* O) {
		father = O;
	}
};
class MultiTrie {
public:
	MultiNode* root;
	MultiTrie() { root = nullptr; }
	unordered_map<int, MultiNode*> UM;
	//实现在UM中插入一个边
	//son & father
	void insert(int O1, int O2) {
		unordered_map<int, MultiNode*>::iterator it1 = UM.find(O1);
		unordered_map<int, MultiNode*>::iterator it2 = UM.find(O2);
		MultiNode* p2, * p1;
		if (it2 == UM.end()) {
			p2 = new MultiNode();
			UM.insert(make_pair(O2, p2));
		}
		else {
			p2 = it2->second;
		}
		if (it1 == UM.end()) {
			p1 = new MultiNode(p2);
			UM.insert(make_pair(O1, p1));
		}
		else {
			p1 = it1->second;
			p1->father = p2;
		}
		p2->sons.push_back(p1);
		if (root == nullptr) { root = p2; }
		while (root->father != nullptr) { root = root->father; }
	}
	//void init() {
	//	dfs(root);
	//}
	//void dfs(MultiNode* node) {
	//	node->fathers.push_back(node->father);
	//	int i = 1;
	//	//while (node->fathers[i - 1] != nullptr && node->fathers[i - 1]->fathers[i - 1] != nullptr) {
	//	while (node->fathers.size() >= i && node -> fathers[i-1] != nullptr && node->fathers[i - 1]->fathers.size() >= i && node->fathers[i-1]->fathers[i-1] != nullptr) {
	//		node->fathers.push_back(node->fathers[i - 1]->fathers[i - 1]);
	//		i++;
	//	}
	//	for (auto k:node->sons) {
	//		dfs(k);
	//	}
	//}
};