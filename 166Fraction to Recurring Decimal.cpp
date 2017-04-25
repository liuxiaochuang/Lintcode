//����㣺��ѧ���߽����
//���̣�һ��ʼӦ���뵽�����ļ�����̣�����㷨Ӧ��ģ������ļ�����̣�������С�����Ƿ��ص�
//string�ﺬ��С�������о���Ҫ��C++��int��string��ת������������������о��Ǹ������Ҫ���ǵ�
//���縺����0��������Ҫ��������߽�����������int��ת����long long���ټ���

//���飺������ᵽ��ģ������Ĺ��̣���ص���Сѧ�� ����int���͵ı߽����⣻
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string str;
        if (denominator == 0)
            return "";
        if  (numerator == 0)
            return "0";
        if (numerator<0 ^ denominator<0)
            str += "-";
        long long num1 = numerator;
        long long num2 = denominator;
        num1 = abs(num1);
        num2 = abs(num2);
        cout<<num1<<endl;
        cout<<"num2"<<num2<<endl;
        //int shang = num1 / num2;
        str += int2string(num1/num2);
        long long mod = num1 % num2;
        if (mod == 0)
            return str;
        str += ".";
        map<int,int> map1;
        while (mod) {
            if (map1.find(mod) != map1.end()) {
               //     cout<<mod<<" "<<map1[mod]<<endl;
                str.insert(map1[mod],1,'(');
                str += ')';
                break;
            }
            map1[mod] = str.size();
            mod *= 10;
            long long temp = mod/num2;
            cout<<"temp="<<temp<<"mod="<<mod<<" "<<num2<<endl;
            str += int2string(temp);
            mod = mod%num2;
        }
        return str;

    }
    string int2string(long long num){
        string str = "";
        if (num == 0)
            return "0";
        while(num) {
            long long temp = num % 10;
            num /= 10;
            str += ('0' + temp);
        }
        reverse(str.begin(), str.end());
        return str;
}
};
int main() {

    Solution sol;
    string str = sol.fractionToDecimal(-2147483648,1);
    cout<<str<<endl;
    cout<<sol.int2string(2147483648)<<endl;
    cout<<2147483648;
}

