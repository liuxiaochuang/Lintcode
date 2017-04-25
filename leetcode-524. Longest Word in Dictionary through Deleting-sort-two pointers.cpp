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
 #define MAXN 100005
 #include<stack>
 #define INF 0x7fffffff
 #include<fstream>
 #include<time.h>
 //#define lxc
 using namespace std;
class Solution {
public:
    static bool cmp(const string &a, const string &b) {
        if (a.size() > b.size()) {
            return true;
        } else if (a.size() < b.size()) {
            return false;
        } else {
            if (a <= b) {
                return true;
            } else {
                return false;
            }
        }
    }
    bool isOk(string &s, string &str) {
        int len1 = s.size();
        int len2 = str.size();
        if (len1 < len2)
            return false;
        int i=0, j=0;
        while (i<len1 && j<len2) {
            if (s[i] == str[j]) {
                if (j == len2-1)
                    return true;
                i++;
                j++;
                continue;
            } else {
                i++;
            }
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        stable_sort(d.begin(), d.end(), cmp);
        for (int i=0; i<d.size(); i++) {
            if (isOk(s, d[i])) {
                return d[i];
            }
        }
        return "";
    }
};
int main()
{
    string a = "asd";
    string b = "a";
    cout<<(a < b);
}
