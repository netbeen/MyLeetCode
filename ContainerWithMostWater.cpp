/*
 * ContainerWithMostWater.cpp
 *
 *  Created on: 2015年4月14日
 *      Author: netbeen
 */

/*
 * 依次排开的不同高度的木板，选取两个作为水桶，所装的水最多的体积是多少。
 * 题眼：桶的有效高度取决于两块板的最小值，宽度为两块板的距离。
 *
 * 本题确实可以使用动态规划求解，不过对于求最大值的问题用动态规划会造成大量的冗余计算。
 * 这里采用最优化求解。即，如果左板比右板短，则往左移动右板是一定不会变好的，只能往右移左板。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
    	int maxV = 0;
    	if(height.size() < 2){
    		return maxV;
    	}
    	int cursorLow = 0;
    	int cursorHigh = height.size()-1;
    	while(cursorLow < cursorHigh){
    		maxV = max(maxV, min(height.at( cursorLow ), height.at( cursorHigh ) )*( cursorHigh-cursorLow ) );
    		if(height.at(cursorLow) < height.at(cursorHigh)){
    			cursorLow++;
    		}else{
    			cursorHigh--;
    		}
    	}
    	return maxV;
    }
};

int main(){
	int array[] = {1, 2, 13, 14, 5, 6};
	vector<int> height = vector<int>(array, array+sizeof(array)/sizeof(int));
	Solution s;
	cout << s.maxArea(height);
}
