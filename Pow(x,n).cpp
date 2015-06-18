/*
 * Pow(x,n).cpp
 *
 *  Created on: 2015年6月18日
 *      Author: netbeen
 */


/*
 * 自己写一个Pow函数。
 * 注意几个点：如果n为负数，则返回1.0 / myPow(x, -n);
 * 如果n为奇数，则返回half*half*x;
 * 如果n为偶数，则返回half*half
 *
 * 利用二分法减少程序运行时间。
 */

class Solution {
public:
    double myPow(double x, long n) {
    	if(n == 0){
    		return 1.0;
    	}else if(n < 0){
    		return 1.0 / myPow(x, -n);
    	}else if(n % 2 == 0){
    		double half = myPow(x,n/2);
    		return half*half;
    	}else{
    		double half = myPow(x,n/2);
    		return half*half*x;
    	}
    }
};
