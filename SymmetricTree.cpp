/*
 * SymmetricTree.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */


/*
 * 判定一个树是否为对称树。
 * 另外建立一个双参数的isSymmetric，在保证左右子树非空的情况下，
 * 判定leftRoot->left和rightRoot->right是否对称
 * 判定leftRoot->right和rightRoot->left是否对称
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
	bool isSymmetric(TreeNode *leftRoot, TreeNode *rightRoot) {
		if (leftRoot == NULL && rightRoot == NULL)
			return true;
		if(leftRoot == NULL || rightRoot == NULL)
			return false;
		return (leftRoot->val == rightRoot->val) && (isSymmetric(leftRoot->left,rightRoot->right)) && (isSymmetric(leftRoot->right,rightRoot->left));

	}

	bool isSymmetric(TreeNode *root) {
		if (root == NULL)
			return true;
		return isSymmetric(root->left,root->right);
	}
};
