/*
 * PopulatingNextRightPointersInEachNode.cpp
 *
 *  Created on: 2015年4月6日
 *      Author: netbeen
 */

/*
 * 利用广度优先遍历的策略，指定一个previousHead指向上一行的头，previousCursor作为上一行的游标。
 * 一行一行执行，执行完毕就返回
 */

#include <iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) :
			val(x), left(NULL), right(NULL), next(NULL) {
	}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if(root == NULL){
			return;
		}
		TreeLinkNode* previousHead = root;
		while(previousHead->left != NULL){
			TreeLinkNode* previousCursor = previousHead;
			while(previousCursor != NULL){
				previousCursor->left->next = previousCursor->right;
				if(previousCursor->next != NULL){
					previousCursor->right->next = previousCursor->next->left;
				}
				previousCursor = previousCursor->next;
			}
			previousHead = previousHead->left;
		}
	}
};

