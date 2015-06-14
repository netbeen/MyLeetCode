/*
 * Anagrams.cpp
 *
 *  Created on: 2015年6月14日
 *      Author: netbeen
 */

/*
 * 输入个vector<string>，要求返回其中所有符合换序构词法的string。假设其中只有一个解。
 *
 * 构造一个哈希表<string, int>，存储着字符串和第一次出现的位置。
 *
 * 将每个字符串排序，然后再查找哈希表，如果没找到，则添加
 * 如果找到了，要查看其值是否为-1,（为-1表示第一个元素已经进入结果集，只要放入当前字符串即可）
 * 若值不为-1,则说明，值还表示着第一次出现的位置，应该将第一次出现的string放入结果集，同时放入当前string，再将值置为-1
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
    	vector<string> result;
    	unordered_map<string, int> stringToIndex;
    	for(size_t index = 0; index < strs.size();index++){
    		string tempStr = strs.at(index);
    		sort(tempStr.begin(),tempStr.end());
    		unordered_map<string,int>::iterator it = stringToIndex.find(tempStr);
    		if(it == stringToIndex.end()){
    			stringToIndex.insert(pair<string, int>(tempStr,index));
    		}else if(it->second == -1){
    			result.push_back(strs.at(index));
    		}else{
    			result.push_back(strs.at(stringToIndex.at(tempStr)));
    			result.push_back(strs.at(index));
    			it->second=-1;
    		}
    	}
    	return result;
    }
};
