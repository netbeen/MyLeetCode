/*
 * CountPrimes.cpp
 *
 *  Created on: 2015年5月19日
 *      Author: netbeen
 */

/*
 * 返回小于n的素数的个数。
 * 一开始使用暴力法，结果超时。
 * 后来学会了埃氏筛法，每次排除每个素数的倍数，最后统计素数个数。
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int countPrimes(int n){
		if(n<=2){		//限制初始条件
			return 0;
		}

		vector<bool> isPrime(n);
		for(auto cur : isPrime){
			cur = true;
		}

		isPrime.at(0) = false;
		isPrime.at(1) = false;

		for(int divisor = 2; divisor * divisor < n; divisor++){	// 选择某个数
			if(isPrime.at(divisor) == false){	//若不是素数，直接跳过
				continue;
			}
			for(int factor = 2; factor * divisor < n; factor++){	//若是素数，将所有的倍数全部剔除
				isPrime.at(factor * divisor)=false;
			}
		}

		int result = 0;
		for(auto cur : isPrime){	//统计结果
			if(cur == true){
				result++;
			}
		}
		return result;
	}
};

int main(){
	Solution s;
	cout << s.countPrimes(2);
	return 0;
}

