//����㣺��̬�滮��
//˼·��dp[i]��ʾ��i��������i2,i3,i5�ֱ��ʾ������Ҫ����2��3��5��dp���±꣬ÿ��ѭ������Ҫ
//�ֱ��ж����ǳ�2��3��5��Ĵ�С����С��Ϊdp[i]�����ҽ���Ӧ���±��1��

//һ��ʼ������·����ɸ�ӷ������ҳ�����������ʱ�临�Ӷ�̫��
//��������dp���������������ж�ÿ�����Ƿ���ugly��O��n^2�����Ӷȣ�Ҳ����
//���ſ�����������DP��
//���飺ѧ����map��queue��stack��set

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
