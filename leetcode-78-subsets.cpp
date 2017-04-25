
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

    vector<vector<int>> subSet(vector<int> &nums) {
        vector<vector<int>> ret;
        vector<int> mid;
        process(ret, mid, nums, 0);
        return ret;
    }
    void process(vector<vector<int>> &ret, vector<int> mid, vector<int> &nums, int index) {

        if (index == nums.size()) {
            for (auto i : mid)
                cout<<i<<" ";
            cout<<endl;
            ret.push_back(mid);
            return;
        }
        process(ret, mid, nums, index + 1);
        mid.push_back(nums[index]);
        process(ret, mid, nums, index + 1);

    }

};

int main() {
    Solution sol;
    vector<int> v{1,2,3};
    vector<vector<int>> res;
    res = sol.subSet(v);

    return 0;
}


