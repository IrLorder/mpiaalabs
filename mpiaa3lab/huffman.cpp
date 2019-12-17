#include "huffman.h"

#include <vector>
#include <map>
#include <queue>

using HuffmanTable = std::map<char, std::string>;

namespace {

	struct TreeNodeWeightCompare {
		bool operator()(const TreeNode *t1, const TreeNode *t2) const {
			return t1->weight > t2->weight;
		}
	};

	void addToTable(const TreeNode *tree, HuffmanTable &table, const std::string &code) {
		if (!tree) {
			return;
		}
		if (tree->isLeaf()) {
			table[tree->symbol] = code;
			return;
		}
		addToTable(tree->left, table, code + '0');
		addToTable(tree->right, table, code + '1');
	}

	HuffmanTable buildHuffmanTable(const TreeNode *tree) {
		HuffmanTable table;
		addToTable(tree, table, "");
		return table;
	}

}

TreeNode* buildTree() {
	std::priority_queue<TreeNode*, std::vector<TreeNode*>, TreeNodeWeightCompare> nodes;
	for (char c = 'a'; c <= 'z'; c++) {
		nodes.push(new TreeNode(c, 5));
	}
	for (char c = 'A'; c <= 'Z'; c++) {
		nodes.push(new TreeNode(c, 2));
	}
	for (char c : std::string(" \"'0123456789!?@#$%^&*()-+,.~<>`\t\n\r")) {
		nodes.push(new TreeNode(c, 1));
	}
	while (nodes.size() > 1) {
		auto *n1 = nodes.top();
		nodes.pop();
		auto *n2 = nodes.top();
		nodes.pop();
		nodes.push(new TreeNode(0, n1->weight + n2->weight, n1, n2));
	}
	return nodes.top();
}

void deleteTree(const TreeNode *root) {
	if (!root) {
		return;
	}
	if (root->left) {
		deleteTree(root->left);
	}
	if (root->right) {
		deleteTree(root->right);
	}
	delete root;
}

std::string encode(const TreeNode *tree, const std::string &str) {
	const auto table = buildHuffmanTable(tree);
	std::string result = "";
	for (auto c : str) {
		try {
			result += table.at(c);
		}
		catch (const std::out_of_range&) {
			throw std::runtime_error(std::string("Cannot encode character ") + c);
		}
	}
	return result;
}


std::string decode(const TreeNode *tree, std::string &code_str, std::string &decoded) {
	std::string temp_code_str = code_str;
	auto *root = tree;
	int i = 0;
	while (tree->symbol == 0) {
		if (temp_code_str[i] == '0')
			tree = tree->left;
		else if (temp_code_str[i] == '1')
			tree = tree->right;
		i++;
	}
	decoded += tree->symbol;
	if (temp_code_str.size() != i) {
		temp_code_str.erase(0, i);
		return decode(root, temp_code_str, decoded);
	}
	return decoded;
}

void build_dict(std::string &input) {
	char ch;
	for (int i = 65; i < 91; i++) {
		ch = i;
		input += ch;
	}
	for (int i = 97; i < 123; i++) {
		ch = i;
		input += ch;
	}
	input += 32;
}
