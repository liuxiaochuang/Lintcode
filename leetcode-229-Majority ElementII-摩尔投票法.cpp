
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
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return nums;
        vector<int> res;
        int count1=0, candidate1=0, count2=0, candidate2=1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == candidate1) {
                count1++;
            } else if (nums[i] == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        int a = count(nums, candidate1);
        int b = count(nums, candidate2);
        if ((double)a/(double)nums.size() > 1.0/3.0)
            res.push_back(candidate1);
        if ((double)b/(double)nums.size() > 1.0/3.0)
            res.push_back(candidate2);
        return res;

    }
    int count(vector<int> &nums, int a) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            if (a == nums[i])
                res++;
        }
        return res;
    }
};
int main() {


}

