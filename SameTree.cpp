/*
 * SameTree.cpp
 *
 *  Created on: 2015年3月24日
 *      Author: netbeen
 */

#include <iostream>

/**
 * Definition for binary tree*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
 * 主要采用深度优先遍历的方法，检测所有false事件，如果全部通过，则给予true的标记。
 */
class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL) {		//两颗树都为空
			return true;
		}else if(p == NULL || q == NULL){		//任意一棵树为空
			return false;
		}
		return   (isSameTree(p->left,q->left)) && (p->val == q->val) && (isSameTree(p->right,q->right));	//递归中序遍历+判断
	}
};

int main() {
	TreeNode* p = new TreeNode(0);
	TreeNode* q = new TreeNode(0);
	Solution s;
	std::cout << s.isSameTree(p, q);
}
