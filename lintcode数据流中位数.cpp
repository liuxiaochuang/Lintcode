
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<iomanip>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<string>
#include<hash_map>
#include<memory>
#include<random>
#include<sstream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> ret;
        if (nums.size() == 0 || nums.size() == 1)
            return nums;
        vector<int> temp;
        for (int i=0; i<nums.size(); i++) {

            insert(temp, nums[i]);
            ret.push_back(temp[(temp.size()-1)/2]);
        }
        return ret;
    }

    //insert函数还可以改为二分查找的方式，那样时间复杂度就不是O(n^2)，是O(nlog(n))了。
    void insert(vector<int>& temp, int num) {
        cout<<"insert:"<<num<<endl;
        temp.push_back(num);
        int len = temp.size();
        for (int i=0; i<len; i++) {
            if(temp[i] > num) {
                int aa = num;
                for (int j = len - 1; j>i; j--) {
                        //cout<<
                    temp[j] = temp[j - 1];
                }
                temp[i] = aa;
                break;
            }
        }
        for (auto i : temp) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Solution sol;
    vector<int> v{4,5,1,3,2,6,0};
    vector<int> res;
    res = sol.medianII(v);
    for (auto i : res) {
        cout<<i << " ";
    }
    return 0;
}


