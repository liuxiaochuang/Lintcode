//172. Factorial Trailing Zeroes
// 考察点：数学；题意是给n，判断n!末尾有多少0；
//解题思路：之前做个这个题，但是忘记思路了，只记得只考虑5的倍数的数，不用考虑2的，因为2太多了
//所以一上来就从n遍历到5，判断每个数有多少个5的multiplys。这样做超时了。
//后来我又想到，如果到125时，125包含25的因子，所以能不能用map存储已经知道的树的因子数
//然后到时候就不用除以5了，直接取就行，结果还是超时，因为这样的存储节约不了多少时间，需要存储的
//数太多了。
//最后才发现最优的解：通过n/（5×i）来判断1-n中，含有5×i的因子的个数有多少个；这样通过从5
//到不大于n的5×i遍历，就会找出所有的结果。

//经验：有时候好的数学思路可以极大的节约时间；
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
