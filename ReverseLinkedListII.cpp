/*
 * ReverseLinkedListII.cpp
 *
 *  Created on: 2015年4月5日
 *      Author: netbeen
 */


/*
 * 在一段单链表中反转指定区间的节点。利用4个指针来固定反转区间的头尾，然后在调用反转函数来反转。
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL) {
            return head;
        }
        ListNode* previousReverseHead = NULL;
        ListNode* reverseHead = head;
        ListNode* reverseTail;
        ListNode* nextReverseTail = NULL;
        int reverseHeadMove = m - 1;
        int reverseLength = n - m;
        if (reverseHeadMove == 0) {
            ;
        } else {
            for (int i = 0; i < reverseHeadMove; i++) {
                previousReverseHead = reverseHead;
                reverseHead = reverseHead->next;
            }
        }
        if (reverseLength == 0) {
            return head;
        } else {
            reverseTail = reverseHead;
            for (int i = 0; i < reverseLength; i++) {
                reverseTail = reverseTail->next;
            }
            if (reverseTail->next != NULL) {
                nextReverseTail = reverseTail->next;
            }
        }

        reverseTotal(reverseHead, reverseTail);

        if (previousReverseHead != NULL) {
            previousReverseHead->next = reverseTail;
        }else{
            head = reverseTail;
        }
        if (nextReverseTail != NULL) {
            reverseHead->next = nextReverseTail;
        }else{
        	reverseHead->next = NULL;
        }

        return head;
    }

    //reverseTotal函数，用来调换head和tail之间的节点的链接方向，不包括改变head的next所指，这应该放到外层调用者控制。
    ListNode* reverseTotal(ListNode* const head, ListNode* const tail) {
        ListNode* cursor = head;
        while (true) {
            ListNode* left;
            ListNode* right;
            if (cursor == head) {
                right = cursor->next;
            } else if (cursor == tail) {
                cursor->next = left;
                break;
            } else {
                right = cursor->next;
                cursor->next = left;
            }
            left = cursor;
            cursor = right;
        }
        return head;
    }
};

int main() {
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    head = s.reverseBetween(head,2, 3);

    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    return 0;
}
