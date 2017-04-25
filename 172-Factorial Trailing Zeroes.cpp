//172. Factorial Trailing Zeroes
// ����㣺��ѧ�������Ǹ�n���ж�n!ĩβ�ж���0��
//����˼·��֮ǰ��������⣬��������˼·�ˣ�ֻ�ǵ�ֻ����5�ı������������ÿ���2�ģ���Ϊ2̫����
//����һ�����ʹ�n������5���ж�ÿ�����ж��ٸ�5��multiplys����������ʱ�ˡ�
//���������뵽�������125ʱ��125����25�����ӣ������ܲ�����map�洢�Ѿ�֪��������������
//Ȼ��ʱ��Ͳ��ó���5�ˣ�ֱ��ȡ���У�������ǳ�ʱ����Ϊ�����Ĵ洢��Լ���˶���ʱ�䣬��Ҫ�洢��
//��̫���ˡ�
//���ŷ������ŵĽ⣺ͨ��n/��5��i�����ж�1-n�У�����5��i�����ӵĸ����ж��ٸ�������ͨ����5
//��������n��5��i�������ͻ��ҳ����еĽ����

//���飺��ʱ��õ���ѧ˼·���Լ���Ľ�Լʱ�䣻
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<set>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int times = 0;
        for (long long i=5; i<=n; i*=5) {
            int tempTimes = n/i;
            if (tempTimes < 1)
                break;
            times += n/i;
        }
        return times;
    }
};
