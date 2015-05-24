/*
 * ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
 *
 *  Created on: 2015年5月24日
 *      Author: netbeen
 */




/**
 * Definition for a binary tree node.*/

/*
 * 输入后续遍历和中序遍历，给出二叉树。
 *
 * 和之前的一题完全类似，注意内存swap大法。
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if (inorder.empty() == true) {
    				return NULL;
    			} else if (inorder.size() == 1) {
    				return new TreeNode(inorder.at(0));
    			} else {
    				//建立根节点
    				TreeNode* root = new TreeNode(postorder.back());

    				//查找根节点在中序中的位置
    				int rootIndex = 0;
    				for (int inorderElem : inorder) {
    					if (inorderElem == root->val) {
    						break;
    					}
    					rootIndex++;
    				}

    				//构建用于递归的子数组
    				vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootIndex);
    				vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
    				vector<int> rightPostorder(postorder.begin() + rootIndex, postorder.end()-1);
    				vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

    				//swap大法，用于降低递归时的内存消耗，避免leetcode报错Memory Limit Exceeded
    				{
    					vector<int> clear1;
    					postorder.swap(clear1);
    					vector<int> clear2;
    					inorder.swap(clear2);
    				}

    				//生成子节点
    				root->left = buildTree(leftInorder,leftPostorder);
    				root->right = buildTree( rightInorder,rightPostorder);

    				return root;
    			}

    }
};

int main() {

	Solution s;

	vector<int> inorder { 2,1};
	vector<int> postorder { 2,1};

	s.buildTree(inorder,inorder);
	cout << "DONE" << endl;
	return 0;
}
