
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
private:
    unordered_map<string, vector<string>> map1;
    vector<string> combine(string s, vector<string> pre) {
        for (int i=0; i<pre.size(); i++) {
            pre[i] += " " + s;
        }
        return pre;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set1;
        for (auto i : wordDict) {
            set1.insert(i);
        }
        //move(wordDict.begin(), wordDict.end(), back_inserter(set1));
        vector<string> ret = help(s, set1);
        return ret;
    }
    vector<string> help(string s, unordered_set<string> set1) {
        vector<string> ret;
        if (map1.count(s))
            return map1[s];
        if (set1.count(s))
            ret.push_back(s);
        for (int i=s.size() - 1; i>=1; i--) {
            string temp = s.substr(i);
            if (set1.count(temp)) {

                vector<string> pre = combine(temp, help(s.substr(0,i), set1));
                ret.insert(ret.end(), pre.begin(), pre.end());
            }
        }
        map1[s] = ret;
        return ret;
    }

};

int main() {
    int n, sum;
    scanf("%d", &n);
    if (n<=1 || n>5){
        printf("Error!\n");
        return 0;
    }
    sum = fun(n,n);
    printf("%d\n", sum);
    return 0;
}


