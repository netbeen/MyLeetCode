/*
 * InsertionSortList.cpp
 *
 *  Created on: 2015年5月22日
 *      Author: netbeen
 */




/**
 * Definition for singly-linked list.*/

/*
 * 将插入排序应用到链表上，没啥技术含量就是模拟一下链表操作。
 * 给input链表和result链表都加上dummyHead，保证操作的一致性。
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
    ListNode* insertionSortList(ListNode* head) {
    	if(head == NULL || head->next == NULL){
    		return head;
    	}
    	ListNode* dummyHeadInput = new ListNode(-1);
    	dummyHeadInput->next = head;

    	ListNode* dummyHeadResult = new ListNode(-1);



    	while(dummyHeadInput->next != NULL){
    		ListNode* cursor = dummyHeadInput->next;
    		dummyHeadInput->next = dummyHeadInput->next->next;

    		ListNode* sortedCursor = dummyHeadResult;
    		while(sortedCursor->next != NULL && sortedCursor->next->val < cursor->val){
    			sortedCursor = sortedCursor->next;
    		}
    		cursor->next = sortedCursor->next;
    		sortedCursor->next = cursor;
    	}

    	return dummyHeadResult->next;

    }
};
