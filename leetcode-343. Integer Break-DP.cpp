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
 #define MAXN 100005
 #include<stack>
 #define INF 0x7fffffff
 #include<fstream>
 #include<time.h>
 //#define lxc
 using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        int dp[n+2];
        dp[0] = 1;
        dp[1] = 1;
        if (n == 2)
            return 1;
        //dp[2] = 2;
        for (int i=2; i<=n; i++) {
            int max1 = i-1;
            for (int j=1; j<=i/2; j++) {
                int temp = max(dp[j],j) * max(dp[i-j], i-j);

                    if (temp > max1)
                        max1 = temp;
            }
            dp[i] = max1;
        }
        return dp[n];
    }
};
int main()
{
    Solution sol;
    int a = sol.integerBreak(4);
}
