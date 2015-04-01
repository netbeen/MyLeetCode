/*
 * MergeSortedArray.cpp
 *
 *  Created on: 2015年4月1日
 *      Author: netbeen
 */

/*
 * 归并两个有序数组。
 * 为了防止从前往后整理的时候会造成其他元素移动，就从后往前整理。
 */

#include <iostream>

using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int cursor = m + n - 1;
		int tailA = m - 1;
		int tailB = n - 1;
		//归并开始
		while (tailA >= 0 && tailB >= 0) {
			if (A[tailA] > B[tailB]) {
				A[cursor] = A[tailA];
				tailA--;
				cursor--;
			} else {
				A[cursor] = B[tailB];
				tailB--;
				cursor--;
			}
		}

		while (tailA >= 0) {
			A[cursor] = A[tailA];
			tailA--;
			cursor--;
		}
		while (tailB >= 0) {
			A[cursor] = B[tailB];
			tailB--;
			cursor--;
		}
		return;
	}
};

int main() {
	Solution s;
	int A1[1000] = { 1, 3, 5, 7 };
	int B1[5] = { 0, 2, 4, 6, 8 };
	s.merge(A1, 4, B1, 5);
	cout << "A1[]=";
	for (int i = 0; i < 9; i++) {
		cout << A1[i] << " ";
	}
	cout << endl;

	/*int A2[0] = { };
	int B2[1] = { 1 };
	s.merge(A2, 0, B2, 1);
	cout <<"A2[]=";
	for (int i = 0; i < 1; i++) {
		cout << A2[i] << " ";
	}
	cout << endl;*/

	return 0;
}
