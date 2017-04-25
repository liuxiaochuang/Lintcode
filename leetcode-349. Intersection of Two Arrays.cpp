#include <cstdio>
 #include <cstring>
 #include<algorithm>
 #include<math.h>
 #include<set>
 #include<vector>
 #include<stdlib.h>
 #include<iostream>
 #include<map>
 #include<vector>
 #define MAXN 2010
 #define INF 0x7fffffff
// thought : from the end to the start to start dynamic programming; dp[i][j] represents
typedef long long ll;
using namespace std;
int a[MAXN];
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1, set2, ret;
        for (auto i : nums1) {
            set1.insert(i);
        }
        for (auto i : nums2) {
            set2.insert(i);
        }
        for (auto i : set1) {
            if (set2.find(i) != set2.end()) {
                ret.insert(i);
            }
        }
        vector<int> res ;
        copy(ret.begin(), ret.end(), back_inserter(res));
        return res;

    }
};
