//题目：算出一个“01”字符串mod3的余数
//思路：1、2、4、8、16、32·····；2的n次方加一
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<string>
//#include<string.h>

#include<algorithm>
using namespace std;

/*class Solution {
public:
    bool searchMatrix(vector<vector<int>> & matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0)
            return false;
        int rows= matrix.size();
        int clos = matrix[0].size();
        int i=rows-1, j=0;
        while (i>=0 && j<clos) {
            if (matrix[i][j] <target)
                j++;
            else if(matrix[i][j] >target)
                i--;
            else return true;
        }
        return false;
    }

};
*/ // 另一种版本，本来觉得这种严格下面大于上面，从左到右递增的情况是二分法好，没想到
//还是那种计算从左到右、从上到下的方法用时短；


class Solution {
public:
    bool searchMatrix(vector<vector<int>> & matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0)
            return 0;
        int low = 0, high=matrix.size()-1;
        int mid = low;
        while (low + 1< high) {
            mid = low +(high - low) / 2;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid;
            }

        }
        int row = low;
        if (matrix[high][0]<=target)
            row = high;
        cout<<low<<endl;
        low = 0, high = matrix[row].size() -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums1{1,3,5,7},nums2{10,11,16,20},nums3{23,30,34,50};
    vector<vector<int>> nums;
    nums.push_back(nums1);
    nums.push_back(nums2);
    nums.push_back(nums3);
    Solution sol;
    cout<<sol.searchMatrix(nums,30);
}

