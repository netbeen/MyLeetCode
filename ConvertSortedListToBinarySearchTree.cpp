/*
 * ConvertSortedListToBinarySearchTree.cpp
 *
 *  Created on: 2015年4月10日
 *      Author: netbeen
 */

/*
 * 将一个有序的链表改造成一个BST，还是二叉树的中序遍历的思想。
 * 主要问题是，现在的对象是链表，所以不能直接访问到中间元素，只能遍历。
 * 这样的话，只能达到O（nlogn）的时间复杂度。
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
    	if(head == NULL){
    		return NULL;
    	}
    	int count = 0;
    	ListNode* cursor = head;
    	while(cursor != NULL){
    		count++;
    		cursor = cursor->next;
    	}
    	return sortedListToBSTWithSize(head, count);
    }

    TreeNode* sortedListToBSTWithSize(ListNode* head, int size){
    	if(size <= 0){
    		return NULL;
    	}else{
    		ListNode* midCursor = head;
    		for(int i = 0; i < size/2; i++){
    			midCursor = midCursor->next;
    		}
    		TreeNode* root = new TreeNode(midCursor->val);
    		root->left = sortedListToBSTWithSize(head, size/2);
    		root->right = sortedListToBSTWithSize(midCursor->next, size - size/2 -1);
    		return root;
    	}
    }
};

int main(){
	ListNode* head = new ListNode(0);
	Solution s;
	TreeNode* root = s.sortedListToBST(head);
	cout << root->val << endl;
	return 0;
}
