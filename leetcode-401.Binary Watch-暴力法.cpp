
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<iomanip>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<string>
#include<hash_map>
#include<memory>
#include<random>
#include<sstream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i=0; i<12; i++) {
            for (int j=0; j<60; j++) {
                if (countBit(i) + countBit(j) == num) {
                    stringstream s1 , s2;
                    s1 << i;
                    s2 << j;
                    res.push_back(s1.str() + ":" + (j<=9?"0":"") + s2.str());
                }
            }
        }
        return res;
    }
    int countBit(int num) {
        int count = 0;
        while (num) {
            if ((num & 1) == 1) {
                count++;
            }
            num >>= 1;
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<string> str = sol.readBinaryWatch(2);
    for (auto i : str) {
        cout<< i<< " ";
    }
    cout<<endl;
}

