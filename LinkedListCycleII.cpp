/*
 * LinkedListCycleII.cpp
 *
 *  Created on: 2015年3月29日
 *      Author: netbeen
 */




/**
 * Definition for singly-linked list.*/


/*
 * 链表找环并找出环的起始节点：
 * 还是用快慢指针，找出是否有环，如果有环，则将快指针返回头节点，与慢指针同时同速前进，相遇即是环的起始节点。
 * 证明：画一个带环链表，头节点至环起始处距离为a，环起始处距快慢指针交汇出距离为b，快慢指针交汇处距离环起始点距离为c。
 * 相遇时，快指针里程为a+b+c+b=a+2b+c，慢指针里程为a+b，时间相同，速度快指针是慢指针的两倍。列方程a+2b+c=2(a+b)，解得a=c，因此算法成立。
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
    ListNode *detectCycle(ListNode *head) {
    	ListNode* slow = head;
    	ListNode* fast = head;
    	if((head == NULL)   ||   (head->next==NULL)  )	return NULL;
    	while((fast->next != NULL) && (fast->next->next != NULL)){
    		fast = fast->next->next;
    		slow = slow->next;
    		if(fast == slow){
    			fast = head;
    			while(fast != slow){
    				fast	 = fast->next;
    				slow = slow->next;
    			}
    			return fast;
    		}
    	}
    	return NULL;
    }
};
