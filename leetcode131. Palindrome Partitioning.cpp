
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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> mid;
        if (s.size() == 0)
            return ret;
        process(ret, s, mid, 0);
        return ret;
    }

     void process(vector<vector<string>> &ret, string &s, vector<string> mid, int start) {
        if (start == s.size() ) {
            ret.push_back(mid);
            for (auto i : mid) {
                cout<<i<<" ";
            }
            cout<<endl;

            return ;
        }
        for (int i=start + 1; i<=s.size(); i++) {
            string temp = s.substr(start, i - start);
            if (isPart(temp) ) {
                mid.push_back(temp);
                process(ret,s,mid,i);
                mid.pop_back();
            }
        }
        return;
    }

    bool isPart(string &str) {
        int len = str.size();
        for (int i=0; i<len/2; i++) {
            if (str[i] != str[len-i-1]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<vector<string>> str;
    str = sol.partition("aab");
    cout<<endl;
    return 0;
}

