/*
 * RemoveElement.cpp
 *
 *  Created on: 2015年4月1日
 *      Author: netbeen
 */

/*
 * 删除array中的val==elem的元素。
 * 用两个游标（指针），一个指向头，一个指向尾。
 * 头指针意义：当前处理的元素
 * 尾指针意义：尾指针以后（不包括尾指针所指元素），都为要删除的元素
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if (n == 0) {
			return 0;
		}
		int ptrHead = 0;
		int ptrTail = n - 1;
		while (ptrHead <= ptrTail) {
			if(A[ptrHead] != elem){	//如果头指针指向的元素不用删除
				ptrHead++;
			}else{		//如果肉指针指向的元素要删除
				if(A[ptrTail] != elem){	//又如果尾指针的元素不用删除
					int swap = A[ptrHead];
					A[ptrHead] = A[ptrTail];
					A[ptrTail] = swap;
					ptrHead++;
					ptrTail--;
				}else{		//又如果尾指针的元素也要删除
					ptrTail--;
				}
			}
		}
		return ptrTail+1;
	}
};

int main() {
	Solution s;
	cout << "Hello" << endl;
	int A1[] = {1};
	int newA1Len = s.removeElement(A1, sizeof(A1) / sizeof(int), 1);
	cout << newA1Len << endl;
	for (int i = 0; i < newA1Len; i++) {
		cout << A1[i] << " ";
	}
	cout << endl;
	return 0;
}
