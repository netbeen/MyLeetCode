/*
 * MinimumDepthOfBinaryTree.cpp
 *
 *  Created on: 2015年3月29日
 *      Author: netbeen
 */




/**
 * Definition for binary tree*/

/*
 * 求树的最小高度：注意：本题的最小高度是指，从根节点走到最近的叶子节点的的距离，因此如果是[1,2,#]这样的树，最小高度为2,而不是1.因为根节点不是叶子节点了，它有分支。
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
    int minDepth(TreeNode *root) {
    	if(root == NULL){
    		return 0;
    	}
    	int leftMinDepth = minDepth(root->left);
    	int rightMinDepth = minDepth(root->right);
    	if((leftMinDepth != 0) && (rightMinDepth != 0)){	//若左右两子树不空，则选最小的深度+1,并返回
    		return min(leftMinDepth, rightMinDepth)+1;
    	}else if(leftMinDepth == 0){	//若左子树为空，则返回右子树的深度+1。若左右子树都为空也在这个选项，其本身就是叶子节点，返回那个深度都一样，都是0
    		return rightMinDepth+1;
    	}else{	//若右子树为空，则返回左子树的深度+1
    		return leftMinDepth+1;
    	}
    }
};

int main(){
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	cout << s.minDepth(root);

	return 0;
}
