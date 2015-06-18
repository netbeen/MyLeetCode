/*
 * InvertBinaryTree.cpp
 *
 *  Created on: 2015年6月18日
 *      Author: netbeen
 */




/**
 * Definition for a binary tree node.*/

/*
 * 给一个树，要求反转。例如：
 *      4
   /   \
  2     7
 / \   / \
1   3 6   9

反转后输出为
     4
   /   \
  7     2
 / \   / \
9   6 3   1

首先反转左子树，再反转右子树，最后交换左右子树。简单。
 */

#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(root == NULL){
    		return root;
    	}else{
    		this->invertTree(root->left);
    		this->invertTree(root->right);
    		swap(root->left,root->right);
    	}
    	return root;
    }
};
