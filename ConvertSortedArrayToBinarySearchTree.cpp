/*
 * ConvertSortedArrayToBinarySearchTree.cpp
 *
 *  Created on: 2015年4月7日
 *      Author: netbeen
 */

/*
 * 将一个排好序的数组vector组织成一个平衡二叉树。
 * 利用中序遍历的思想，根节点的左边是比根节点小的，根节点右边是比根节点大的。
 * 利用二分递归思想完成。
 */

#include <vector>
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
    	if(num.empty() == true){
    		return NULL;
    	}else if(num.size() == 1){
    		return (new TreeNode(num.at(0)));
    	}else{
    		TreeNode* root = new TreeNode(num.at(num.size()/2));
    		vector<int> leftVector(num.begin(), num.begin() + num.size()/2);	// 用vector的迭代器来对vector进行切片
    		vector<int> rightVector(num.begin() + num.size()/2+1, num.end());
    		root->left = sortedArrayToBST(leftVector);	//递归调用
    		root->right = sortedArrayToBST(rightVector);
    		return root;
    	}
    }
};
