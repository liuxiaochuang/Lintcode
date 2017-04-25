//考察点：动态规划，
//思路：dp[i]表示第i个丑数，i2,i3,i5分别表示接下来要乘以2，3，5的dp的下标，每次循环，都要
//分别判断他们乘2，3，5后的大小，最小的为dp[i]，并且将相应的下标加1；

//一开始走了歧路：用筛子法，先找出质数，后处理，时间复杂度太高
//后来看到dp，但是用了依次判断每个数是否是ugly，O（n^2）复杂度，也不行
//最后才看到这个巧妙的DP法
//经验：学会用map，queue，stack，set

#include<iostream>
#include<limits.h>
#include<map>
#include<set>

using namespace std;
class Solution{
public:
    bool isUgly(int n) {
        while ((n&1) == 0) n >>= 1;
       // cout<<n<<endl;
        while (n%3 == 0) n /= 3;
       // cout<<n<<endl;
        while (n%5 == 0) n /= 5;
        //cout<<n<<endl;
        return n == 1;
    }
    int nthUglyNumber(int n){
        const int MAX = 1700;
        int dp[MAX];//dp[i] is the i'th ugly number
        dp[0] = 0;
        dp[1] = 1;
        int i2=1, i3=1, i5=1;
        int re2, re3, re5;
        for (int i=2; i<=n; i++) {
            re2 = dp[i2]*2;
            re3 = dp[i3]*3;
            re5 = dp[i5]*5;
            dp[i] = min(re2, min(re3,re5));
            if (dp[i] == re2)
                i2++;
            if (dp[i] == re3)
                i3++;
            if (dp[i] == re5)
                i5++;

        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    int res = sol.uglyNumber2(1690);
    cout<<res<<endl;
    //cout<<sol.isUgly(12)<<endl;



}
