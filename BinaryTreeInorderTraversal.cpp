/*
 * BinaryTreeInorderTraversal.cpp
 *
 *  Created on: 2015年3月25日
 *      Author: netbeen
 */

/*
 * 经典中序遍历二叉树算法
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
	   vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if(root == NULL){
			return result;
		}
		if (root->left != NULL) {
			vector<int> tempVector = inorderTraversal(root->left);
			result.insert(result.end(),tempVector.begin(),tempVector.end());
		}
		result.push_back(root->val);
		if (root->right != NULL) {
			vector<int> tempVector = inorderTraversal(root->right);
			result.insert(result.end(),tempVector.begin(),tempVector.end());
		}
		return result;
	}
};

int main() {
	Solution s;
	s.inorderTraversal(NULL);
	return 0;
}
