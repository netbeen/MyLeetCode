/*
 * PathSum.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */

/*
 * 判定是否存在一条从root到leaf的路径，节点的值的和=sum。
 *
 */

#include <iostream>

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
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL) {
			return false;
		}else if(root->val == sum && root->left == NULL && root->right == NULL) {
			return true;
		}else if (root->val != sum && root->left == NULL && root->right == NULL) {
			return false;
		} else {
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
		}
	}
};
