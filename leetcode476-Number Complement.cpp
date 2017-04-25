
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<string>
#include<hash_map>
#include<memory>
#include<math.h>
//#include<string.h>

#include<algorithm>
using namespace std;

class Solution {
public:
    string int2binary(int num) {
        string str;
        while (num) {
            str = (char)('0' + (1^(num&1))) + str;
            num >>= 1;
        }
        return str;
    }
    int findComplement(int num) {
        string str= int2binary(num);
        int res = 0;
        int len = str.size();
        for (int i=len-1; i>=0; i--) {
            if (str[i] == '1')
                res += pow(2,len-i-1);
        }
        return res;
    }
};

int main() {
    int a = 6;
    cout<<int2binary(a)<<endl;
    cout<<atoi()
}

