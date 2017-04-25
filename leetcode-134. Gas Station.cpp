#include <iostream>
#include <cstring>
#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;
// if from start to i, the temp is < 0, that is to say there is no suitable start
//from start to i ; so we can set i+1 as the start and continue; out the for circle
// if total + temp < 0, then there is no suitable place for the circle, else, it is
//start that is suitable;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start(0), total(0), temp(0);
        int len = gas.size();
        for (int i=0; i<len; i++) {
            temp += gas[i] - cost[i];
            if (temp < 0) {
                total += temp;
                temp = 0;
                start = i + 1;
            }
        }
        return (total + temp < 0 ? -1 : start);
    }
};

int main()
{
    Solution sol;
    vector<pair<int,int>> v;
    v.push_back(pair<int,int>{6,0});
    v.push_back(pair<int,int>{5,0});
    v.push_back(pair<int,int>{4,0});
    v.push_back(pair<int,int>{3,2});
    v.push_back(pair<int,int>{2,2});
    v.push_back(pair<int,int>{1,4});
    sol.reconstructQueue(v);
        return 0;
}
