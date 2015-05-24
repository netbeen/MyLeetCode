/*
 * RotateImage.cpp
 *
 *  Created on: 2015年5月24日
 *      Author: netbeen
 */

/*
 * 将n*n的矩阵进行顺时针90度旋转。要求就地旋转。
 * 由于不能使用额外的空间，正常的图形学中的旋转矩阵乘法无法使用。
 *
 * 找规律：右旋90度=先转置，再水平反转。
 */

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	if(matrix.size() < 2){
    		return;
    	}
    	for(size_t i = 0; i < matrix.size(); i++){
    		for(size_t j = 0; j < i; j++){
    			swap(matrix.at(i).at(j), matrix.at(j).at(i));
    		}
    	}
    	for(vector<int>& rowVector : matrix){
    		std::reverse(rowVector.begin(), rowVector.end());
    	}

    }
};
