/*
 * IntegerToRoman.cpp
 *
 *  Created on: 2015年4月14日
 *      Author: netbeen
 */

/*
 * int型转罗马数字
 * 利用STL的map
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	this->init();
    	string result;
    	while(num>0){
    		for(map<int, string>::reverse_iterator reverseIt = int2Rom.rbegin(); reverseIt != int2Rom.rend(); reverseIt++){	//由于默认的map是按照key升序，所以这里要使用reverse_iterator
    			if( num >= reverseIt->first){
    				result += reverseIt->second;
    				num -= reverseIt->first;
    				break;
    			}
    		}
    	}
    	return result;
    }
private:
    map<int, string> int2Rom;
    void init(){
    	int2Rom.insert(pair<int, string>(1000,"M"));
    	int2Rom.insert(pair<int, string>(900,"CM"));
    	int2Rom.insert(pair<int, string>(500,"D"));
    	int2Rom.insert(pair<int, string>(400,"CD"));
    	int2Rom.insert(pair<int, string>(100,"C"));
    	int2Rom.insert(pair<int, string>(90,"XC"));
    	int2Rom.insert(pair<int, string>(50,"L"));
    	int2Rom.insert(pair<int, string>(40,"XL"));
    	int2Rom.insert(pair<int, string>(10,"X"));
    	int2Rom.insert(pair<int, string>(9,"IX"));
    	int2Rom.insert(pair<int, string>(5,"V"));
    	int2Rom.insert(pair<int, string>(4,"IV"));
    	int2Rom.insert(pair<int, string>(1,"I"));
    }
};

int main(){
	Solution s;
	cout << s.intToRoman(999);
	return 0;
}
