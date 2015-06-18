/*
 * Sqrt(x).cpp
 *
 *  Created on: 2015年6月18日
 *      Author: netbeen
 */


/*
 * 手动写一个sqrt函数。
 * 要求输入输出都是int。如果不能整除，就是下取整。，比如sqrt(5)=2,sqrt(9)=3
 *
 * 注意几点：
 * 为了节省时间采用二分法。
 * 判断条件使用x/mid==mid？来进行，因为如果使用mid*mid==x容易导致溢出。
 * last_mid就是用来保存最后一个mid的，因为是下取整，所以low游标移动前，要保存mid，以便进行下取整。
 */

class Solution {
public:
    int mySqrt(int x) {
    	if(x < 2){
    		return x;
    	}
    	int low = 0;
    	int high = x;
    	int last_mid = 0;
    	while(low <= high){
    		int mid = (low+high)/2;
    		if(x / mid > mid){
    			low = mid+1;
    			last_mid = mid;
    		}else if(x / mid < mid){
    			high = mid-1;
    		}else{
    			return mid;
    		}
    	}
    	return last_mid;
    }
};
