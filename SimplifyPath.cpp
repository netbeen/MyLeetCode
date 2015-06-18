/*
 * SimplifyPath.cpp
 *
 *  Created on: 2015年6月18日
 *      Author: netbeen
 */

/*
 * 简化目录：将
 * path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

注意，会有连续的//，要排除干扰。
会有根目录下的..，要忽略。

先用一个函数来将path换成vector，顺带忽略掉//
再用一个函数来遍历vector，解决..的问题
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> pathVector;
		convert2Vector(path, pathVector);
		vector<string> simplePathVector;
		convert2SimplePath(pathVector, simplePathVector);

		string result;
		result += '/';

		for (string elem : simplePathVector) {
			result += elem;
			result += '/';
		}
		if(result.size() > 1 && result.back()=='/'){
			result.pop_back();
		}
		return result;
	}

private:
	void convert2SimplePath(const vector<string>& pathVector, vector<string>& simplePathVector){
		for(string elem : pathVector){
			if(elem.compare(".") == 0){
				continue;
			}else if(elem.compare("..") == 0){
				if(simplePathVector.empty() == false){
					simplePathVector.pop_back();
				}
			}else{
				simplePathVector.push_back(elem);
			}
		}
	}

	void convert2Vector(const string path, vector<string>& pathVector) {
		string currentItem;
		for (size_t index = 0; index < path.size(); index++) {
			if (path.at(index) == '/') {
				if (currentItem.empty() == false) {
					pathVector.push_back(currentItem);
					currentItem.clear();
				}
			} else {
				currentItem += path.at(index);
			}
		}
		if (currentItem.empty() == false) {
			pathVector.push_back(currentItem);
		}
	}
};

int main() {
	Solution s;
	cout << s.simplifyPath("/..//home/yy/..//.//121");

}
