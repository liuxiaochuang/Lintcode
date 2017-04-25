//这道题关键是理解题意：不同的数量
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

    int hammingDistance(int x, int y) {
        int time = 0;
        int len = 0;
        while (x || y) {
            int temp1 = x&1;
            int temp2 = y&1;
            if (temp1 != temp2) {
                len++;
            }
            time++;
            x >>=1;
            y >>=1;
        }
        return len;
    }
};int main() {
    Solution sol;
    cout<<sol.hammingDistance(1,4);
}

