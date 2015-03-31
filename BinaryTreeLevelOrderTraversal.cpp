/*
 * BinaryTreeLevelOrderTraversal.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */

/*
 * 按照层序输出BST,用queue来进行存储.
 * 使用广度优先遍历.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > totalResult;
		if (root == NULL) 	return totalResult;
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);		//初始化推进一个root
		while (nodeQueue.empty() == false) {
			vector<int> levelResult;	//每一层的vector
			size_t nowQueueSize = nodeQueue.size();
			for (size_t i = 0; i < nowQueueSize; i++) {
				if (nodeQueue.front()->left != NULL) 	nodeQueue.push(nodeQueue.front()->left);	//左右子树入队
				if (nodeQueue.front()->right != NULL) 	nodeQueue.push(nodeQueue.front()->right);
				levelResult.push_back(nodeQueue.front()->val);	//值入vector
				nodeQueue.pop();	//出队
			}
			totalResult.push_back(levelResult);
		}
		return totalResult;
	}
};

int main() {
	Solution s;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int> > result = s.levelOrder(root);
	for(size_t i = 0; i < result.size();i++){
		cout << "[ ";
		for(size_t j = 0; j < result.at(i).size(); j++){
			cout << result.at(i).at(j) << ", ";
		}
		cout << " ]" << endl;
	}
	return 0;
}
