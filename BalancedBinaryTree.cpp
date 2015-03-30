/*
 * BalancedBinaryTree.cpp
 *
 *  Created on: 2015年3月31日
 *      Author: netbeen
 */




/**
 * Definition for binary tree*/



/*
 * 判定二叉树是否为平衡树的算法。
 * 计算左右子树的深度差，若不符合，则直接判false
 * 若符合，则进一步验证左右子树是否平衡，若全部平衡，返回true
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
	int treeDepth(TreeNode* root){
		if(root == NULL){
			return 0;
		}
		return max(treeDepth(root->left),treeDepth(root->right))+1;
	}

    bool isBalanced(TreeNode *root) {
    	if(root == NULL){
    		return true;
    	}
    	int diff = abs( treeDepth(root->left)-treeDepth(root->right));
    	if(diff > 1){
    		return false;
    	}else{
    		return (isBalanced(root->left) && isBalanced(root->right));
    	}
    }
};

int main(){
	Solution s;
	TreeNode *root = new TreeNode(1);
	s.isBalanced(root);
	return 0;
}
