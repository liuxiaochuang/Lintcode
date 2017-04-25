//考察点：数学，边界情况
//过程：一开始应该想到除法的计算过程，这个算法应该模拟除法的计算过程，不产生小数但是返回的
//string里含有小数；还有就是要会C++里int到string的转换，会这个函数；还有就是各种情况要考虑到
//比如负数，0，；最重要的情况：边界情况：必须把int先转换成long long，再计算

//经验：让我体会到了模拟除法的过程，像回到了小学； 还有int类型的边界问题；
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

