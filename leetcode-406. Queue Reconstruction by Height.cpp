#include <iostream>
#include <cstring>
#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;
const int MAX = 1003;
int map1[MAX][MAX];
bool visited[MAX];
int n,m;
class Solution {
public:

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size();
        sort(people.begin(), people.end(), [](pair<int,int> a,pair<int,int> b) {
            if (a.first>b.first) return true;
            if (a.first == b.first && a.second < b.second) return true;
            return false;
        });
        vector<pair<int, int>> ret;
        for (auto i : people) {
            ret.insert(ret.begin()+i.second, i);
        }


        return ret;
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
