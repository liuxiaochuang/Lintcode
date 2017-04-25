
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
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> mid;
        help(mid, nums, nums.size()-1);
       // vector<vector<int>> ret;
        //move(mid.begin(), mid.end(), back_inserter(ret));
        return mid;
    }
    void help(vector<vector<int>> & mid, vector<int> &nums, int n) {
        if (n == 0){
            mid.push_back(nums);
            return ;
        }

        for (int i=n; i>=0; i--) {
            swap(nums[n], nums[i]);
            help(mid, nums, n-1);
            swap(nums[n], nums[i]);
        }
    }
};



int main() {
    Solution sol;
    set<vector<int>> set1;
    vector<int> v1{1,3,2};
    set1 = sol.permutation2(v1);
    for (auto i : set1) {
        for (auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}


