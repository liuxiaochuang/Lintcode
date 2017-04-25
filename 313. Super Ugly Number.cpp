//����㣺��ѧ��dp��ϸ��
//˼·����uglyNumber2һ����Ҳ����dp�����������prime�кܶ��֣����Ի����dp[i]==dp[i-1]�������
//���������Ӧ��ʹi--�������ſ��Ա�֤�ϸ��С����֮ǰ��Ϊû�뵽i--��������·���˷��˲���ʱ�䣻
//�ջ񣺼���DP���
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<set>

using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) return 1;
        int len = primes.size();
        int index[len];
        int temp[len];
        for (int i=0; i<len; i++){
            index[i] = 1;   //  the i'th prime's start index of dp;
            //temp[i] = 1;    //  result after compute
        }
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2; i<=n; i++) { //for dp[i]
            int minNum = INT_MAX;
            int needPlusIndex = -1;
            int j;
            for (j=0; j<len; j++) {
                temp[j] = dp[index[j]] * primes[j];
                if (temp[j] < minNum){
                    minNum = temp[j];
                    needPlusIndex = j;
                    //cout<<j<<"minNum:"<<minNum<<endl;
                }
            }

            dp[i] = minNum;
            if (dp[i] == dp[i-1])
                i--;
            index[needPlusIndex] += 1;  //  for dp;
            //cout<<dp[i]<<endl;

        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    vector<int> in{5,7,13,17,23,29,31,43,53,59,61,71,73,79,83,97,109,131,137,163,167,181,191,193,197,199,227,233,251,263};
    for (auto i : in)
        cout<<i<<" ";
    cout<<endl;
    int res = sol.nthSuperUglyNumber(500,in);
    cout<<res<<endl;
    //cout<<sol.isUgly(12)<<endl;


}
