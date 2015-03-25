/*
 * ExcelSheetColumnNumber.cpp
 *
 *  Created on: 2015年3月25日
 *      Author: netbeen
 */

/*
 * n进制转10进制的题目：比如8进制56转10进制 = 6*(8^0)+5*(8^1)
 */

//#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
    	int sum = 0;
    	for(int i = s.size(); i > 0; i--){
    		int tempNum = static_cast<int>(s.at(i-1)) - 65 + 1;
    		sum += tempNum * pow(26, s.size()-i);
    	}
    	return sum;
    }
};

int main(){
	Solution s;
	cout << s.titleToNumber("AB");
}
