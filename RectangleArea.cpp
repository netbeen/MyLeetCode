/*
 * RectangleArea.cpp
 *
 *  Created on: 2015年6月16日
 *      Author: netbeen
 */

/*
 * 给定两个矩形（AB是矩形1的左下角坐标，CD是矩形1的右上角坐标，ED是矩形2的左下角坐标，GH是矩形2的右上角坐标）
 * 要求计算两个矩形覆盖的总面积。
 *
 *思路：矩形1面积+矩形2面积-重叠面积。
 * 重点是重叠面积：分X方向上和Y方向上，分别计算。画图，6种情况。
 * 情况1:
 * ----
 *         ------
 *
 *  情况2:
 *         ------
 *  ------
 *
 *  情况3:
 *      ------
 *  ------
 *
 *  情况4:
 *  ------
 *      ------
 *
 *  情况5:
 *  ----------
 *     -----
 *
 *  情况6:
 *     ------
 *  -----------
 */

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int xOverlap = this->calcOverlap(A,C,E,G);
    	int yOverlap = this->calcOverlap(B,D,F,H);
    	int area1 = (C-A)*(D-B);
    	int area2 = (G-E)*(H-F);
    	return area1 + area2 - xOverlap*yOverlap;
    }

private:
    int calcOverlap(int line1Start, int line1End, int line2Start, int line2End){
    	if(line1End <= line2Start || line2End <= line1Start){
    		return 0;
    	}else if(line1Start <= line2Start){
    		if(line1End <= line2End){
    			return line2Start-line1End;
    		}else{
    			return line2Start-line2End;
    		}
    	}else{
    		if(line1End <= line2End){
    			return line1Start-line1End;
    		}else{
    			return line1Start-line2End;
    		}
    	}
    }
};
