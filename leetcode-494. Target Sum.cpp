#include <cstdio>
#include <cstring>
#include<algorithm>
#include<math.h>
#include<set>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<utility>
#include<stack>
#define INF 0x7fffffff
#include<fstream>
#include<time.h>
//#define lxc
using namespace std;
class Solution {
public:
    int ret;
    int findTargetSumWays(vector<int>& nums, int S) {
        ret = 0;
        int len = nums.size();
        if (len == 0)
            return ret;
        dfs(nums, 0, 0, S);
        return ret;
    }
    void dfs(vector<int> &nums, int cur, int sum, int target) {
        if (cur == nums.size()) {
            if (sum == target) {
                ret++;
                return;
            } else {
                return;
            }
        }
        dfs(nums, cur+1, sum+nums[cur], target);
        dfs(nums, cur+1, sum-nums[cur], target);
    }
};

//DP
class Solution {
public:
    int dp[21][2002];
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(dp, 0, sizeof(dp));
        int len = nums.size();
        int sum = 0;
        for (int i : nums)
            sum+=i;
        dp[0][1000] = 1;
        if (S<(-sum) || S>sum)
            return 0;
        for (int i=1; i<=len; i++) {
            for (int j = 1000-sum; j<=1000 + sum; j++) {
                if (dp[i-1][j] != 0) {
                    //cout<<dp[i-1][j]<<" j="<<j<<" i="<<i<<endl;
                    dp[i][j - nums[i-1]] += dp[i-1][j];
                    dp[i][j + nums[i-1]] += dp[i-1][j];
                }
            }
        }
        return dp[len][S+1000];
    }
};
