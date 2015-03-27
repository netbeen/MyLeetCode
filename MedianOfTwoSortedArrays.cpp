/*
 * MedianOfTwoSortedArrays.cpp
 *
 *  Created on: 2015年3月26日
 *      Author: netbeen
 */

/*
 * 两个有序数组找中位数。要求时间复杂度在log(m+n)。
 * 运用一个查找第k大元素的算法。每一次定位A和B两个数组的第k/2个元素，若相同，则该值就是第K大的元素。
 * 若不同，则每次可以抛弃K/2个元素。缩小范围。例如：A[k/2-1] > B[k/2-1]，则删除B数组的前k/2个。
 * 本算法时间复杂度为logk，在求中位数的情况下，k=(m+n)/2，时间复杂度为log(m+n)
 *
 */
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
	double findTheKthElement(int A[], int m, int B[], int n, int k) {
		if (m < n) {// 假设A数组一定大于等于B数组，若不是，则自动调整
			return findTheKthElement(B, n, A, m, k);
		} else if (n == 0) {	//若小数组为空，则直接取大数组的第K个
			return A[k - 1];
		}else if (k == 1) {	//若k=1,取两个数组头部的最小值
			return min(A[0], B[0]);
		}

		int pb = min(k / 2, n);	//对小数组要注意溢出处理
		int pa = k - pb;

		if (A[pa - 1] > B[pb - 1]) {
			return findTheKthElement(A, m, B + pb, n - pb, k - pb);
		} else if (A[pa - 1] < B[pb - 1]) {
			return findTheKthElement(A + pa, m - pa, B, n, k - pa);
		} else {
			return A[pa - 1];
		}
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;
		if (total % 2 == 0) {
			return (findTheKthElement(A, m, B, n, total / 2) + findTheKthElement(A, m, B, n, total / 2 + 1)) / 2;
		} else {
			return findTheKthElement(A, m, B, n, total / 2 + 1);
		}
	}
};

int main() {
	int A[0] = { };
	int B[5] = { 1, 2, 3, 4, 5 };
	Solution s;
	std::cout << s.findMedianSortedArrays(A, sizeof(A) / 4, B, sizeof(B) / 4);
	return 0;
}
