
#include <cstdio>
 #include <cstring>
 #include<algorithm>
 #include<math.h>
 #include<set>
 #include<queue>
 #include<vector>
 #include<stdlib.h>
 #include<iostream>
 #include<sstream>
 #include<utility>

 #include<stack>
 #define INF 0x7fffffff
 #include<fstream>
 #include<time.h>
 //#define lxc
using namespace std;
class Solution {
public:
    void dfs(string airport) {
        while (map1[airport].size()) {
            string temp = (map1[airport]).top();
            map1[airport].pop();
            dfs(temp);
        }
        ret.push_back(airport);
    }
    map<string, priority_queue<string,vector<string>,greater<string>>> map1;
    vector<string> ret;
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto i : tickets) {
            map1[i.first].push(i.second);
        }
        dfs("JFK");
        return vector<string>(ret.rbegin(), ret.rend());
    }
};

