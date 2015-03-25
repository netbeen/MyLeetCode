/*
 * BinaryTreePreorderTraversal.cpp
 *
 *  Created on: 2015年3月25日
 *      Author: netbeen
 */

/**
 * Definition for binary tree*/


/*
 * 基本的前序遍历输出算法
 */
#include <iostream>
#include <vector>

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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		if(root == NULL){
			return result;
		}
		result.push_back(root->val);
		if (root->left != NULL) {
			vector<int> tempVector = preorderTraversal(root->left);
			result.insert(result.end(),tempVector.begin(),tempVector.end());
		}
		if (root->right != NULL) {
			vector<int> tempVector = preorderTraversal(root->right);
			result.insert(result.end(),tempVector.begin(),tempVector.end());
		}
		return result;
	}
};

int main() {
	Solution s;
	s.preorderTraversal(NULL);
	return 0;
}
