
#include <iostream>

//Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 
class Solution {
public:
    int maxDepth(TreeNode *root) {
    	if(root == NULL){		//若根节点为空，最大深度为0
    		return 0;
    	}
    	int maxLevel = 0;	//初始化最大深度
    	if(root->left != NULL){
    		int leftLevel = maxDepth(root->left);	//递归遍历左子树
    		maxLevel = (leftLevel  > maxLevel)?leftLevel:maxLevel;
    	}
    	if(root->right != NULL){
    		int rightLevel = maxDepth(root->right);	//递归遍历右子树
    		maxLevel = (rightLevel  > maxLevel)?rightLevel :maxLevel;
    	}
    	return maxLevel +1;	//返回最大深度，+1是为了加上根节点自身的深度
    }
};

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(1);
	root->right = new TreeNode(1);
	Solution s;
	std::cout << s.maxDepth(root);
	return 0;
}
