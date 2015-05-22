/*
 * SortList.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: netbeen
 */




/**
 * Definition for singly-linked list.*/

/*
 * 链表排序算法
 * 运用归并排序，由于数组形式的归并排序本身有序，则可以免去归并环节。
 * 该算法分成两块：
 * 划分：将链表分成均匀的两段，使用快慢指针进行划分。（每一步快指针走2步，慢指针走一步，最后在慢指针后面断链）
 * 归并：两个有序链表的归并，简单。
 */

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	ListNode* fastPrt = head;
    	ListNode* slowPrt = head;

    	//处理空节点（直接返回），或者只有一个节点（即是鲁棒性条件，也是递归终结条件）
    	if(head == NULL || head->next == NULL){
    		return head;
    	}

    	//快慢指针划分链表
    	while(fastPrt->next != NULL && fastPrt->next->next != NULL){
    		fastPrt = fastPrt->next->next;
    		slowPrt = slowPrt->next;
    	}

    	//链表断链
    	ListNode* head2 = slowPrt->next;
    	slowPrt->next = NULL;

    	//递归划分
    	head = sortList(head);
    	head2 = sortList(head2);

    	//归并链表
    	return mergeTwoList(head, head2);
    }

private:
    ListNode* mergeTwoList(ListNode* head1, ListNode* head2){
    	//设置头节点，统一操作。
    	ListNode* dummyHead = new ListNode(-1);
    	ListNode* cursor = dummyHead;
    	while(head1 != NULL && head2 != NULL){
    		if(head1->val < head2->val){
    			cursor->next = head1;
    			cursor = head1;
    			head1 = head1->next;
    		}else{
    			cursor->next = head2;
    			cursor = head2;
    			head2 = head2->next;
    		}
    	}
    	if(head1 != NULL){
    		cursor->next = head1;
    	}else{
    		cursor->next = head2;
    	}
    	return dummyHead->next;
    }
};

int main(){
	ListNode* head = new ListNode(2);
	/*head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(1);*/

	ListNode* cursor = head;

	while(cursor != NULL){
		cout << cursor->val << "->";
		cursor = cursor->next;
	}

	Solution s;
	cursor = head = s.sortList(head);

	cout << endl;

	while(cursor != NULL){
			cout << cursor->val << "->";
			cursor = cursor->next;
		}

	return 0;

}
