
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
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int sum = 1;
        int len = points.size();
        if (len == 0)
            return 0;
        //int cur1 = points[0].first;
        int cur2 = points[0].second;
        for (int i=0; i<len; i++) {
            if (points[i].first <= cur2) {
                //cur1 = max(points[i].first, cur1);
                cur2 = min(points[i].second, cur2);
                continue;
            }
            sum++;
            //cur1 = points[i].first;
            cur2 = points[i].second;
        }
        return sum;
    }

};

int main() {
    pair<int, int> a;
    a.first = 19;
    a.second = 912;
    pair<int, int> a1;
    a1.first = 19;
    a1.second = 112;
    vector<pair<int, int>> v;
    v.push_back(a);
    v.push_back(a1);
    sort(v.begin(), v.end());
    for (auto i : v)
        cout<<i.first<<" "<<i.second<<endl;;
    return 0;
}


