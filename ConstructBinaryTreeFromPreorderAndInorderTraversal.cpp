/*
 * ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
 *
 *  Created on: 2015年5月24日
 *      Author: netbeen
 */

/**
 * Definition for a binary tree node.*/

/*
 * 输入一个先序遍历和中序遍历，给出二叉树。
 *
 * 模拟正常的遍历转二叉树过程，采用递归实现。唯一需要注意的是，递归使用vector切分以后会造成Memory Limit Exceeded
 * 解决方法，在一个作用域内，声明一个空的temp vector，然后与perorder进行交换，然后离开作用域以后，temp vector就被清除了。
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() == true) {
			return NULL;
		} else if (preorder.size() == 1) {
			return new TreeNode(preorder.at(0));
		} else {
			//建立根节点
			TreeNode* root = new TreeNode(preorder.at(0));

			//查找根节点在中序中的位置
			int rootIndex = 0;
			for (int inorderElem : inorder) {
				if (inorderElem == root->val) {
					break;
				}
				rootIndex++;
			}

			//构建用于递归的子数组
			vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
			vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
			vector<int> rightPreorder(preorder.begin() + rootIndex + 1, preorder.end());
			vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

			//swap大法，用于降低递归时的内存消耗，避免leetcode报错Memory Limit Exceeded
			{
				vector<int> clear1;
				preorder.swap(clear1);
				vector<int> clear2;
				inorder.swap(clear2);
			}

			//生成子节点
			root->left = buildTree(leftPreorder, leftInorder);
			root->right = buildTree(rightPreorder, rightInorder);

			return root;
		}
	}
};

int main() {

	/*vector<int> test{0, 1,2,3,4};
	 vector<int> test2(test.begin()+1,test.begin());
	 for(int i : test2){
	 cout << i << " ";
	 }
	 cout << "------------" << endl;*/

	Solution s;
	vector<int> preorder { 1, 2 };
	vector<int> inorder { 1, 2 };
	s.buildTree(preorder, inorder);
	cout << "DONE" << endl;
	return 0;
}
