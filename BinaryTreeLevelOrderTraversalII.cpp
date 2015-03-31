/*
 * BinaryTreeLevelOrderTraversalII.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */

/*
 * 按照从底向上的顺序层序输出BST,在原本广度优先遍历的基础上,在加入一个栈来倒装即可。
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > totalResult;
		stack<vector<int> > totalStack;
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
			totalStack.push(levelResult);
		}
		while(totalStack.empty() ==false){
			totalResult.push_back(totalStack.top());
			totalStack.pop();
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
	vector<vector<int> > result = s.levelOrderBottom(root);
	for(size_t i = 0; i < result.size();i++){
		cout << "[ ";
		for(size_t j = 0; j < result.at(i).size(); j++){
			cout << result.at(i).at(j) << ", ";
		}
		cout << " ]" << endl;
	}
	return 0;
}
