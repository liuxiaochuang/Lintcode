//��Ŀ��leetcode153,Ѱ��ѭ����������С����
//˼·�����ַ���ע��ϸ�ھ���
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
#include<hash_map>
#include<memory>
#include<math.h>
//#include<string.h>

#include<algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        int low = 0;
        int high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid] ) {
                if (nums[low] <= nums[high]) {
                    return nums[low];
                } else {
                    low = mid + 1;
                }
            } else {
                high = mid ;
            }
        }
        return nums[low];
    }
};
int main() {
    Solution sol;
    vector<int> v{3, 1, 2};
    cout<<sol.findMin(v);
    return 0;
}

