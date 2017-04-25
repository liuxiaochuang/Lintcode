//����㣺O��1��ʱ���DP��
//˼·������������ͬ�������⣬��ǰn�����Ĳ����ں͵����ֵ�����Կ��Դ�n=2��ʼ�ң�����֮ǰ
//�Ľ������̬�滮


class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        long long len = A.size();
        if (len == 1) return A[0];
        if (len == 0) return 0;
        long long temp1,temp2,temp3;
        temp1 = A[0];
        temp3 = temp2 = A[1];
        //vector<long long> dp(len,0);;
        //dp[0] = A[0];
        //dp[1] = A[1];
        for (long long i = 2; i<len; i++) {
            if (temp1 + A[i] > temp2)
                temp3 = temp1 + A[i];
            else
                temp3 = temp2;
            temp1 = temp2;
            temp2 = temp3;
        }
        return temp3;
    }
};
