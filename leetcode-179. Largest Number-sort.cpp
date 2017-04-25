#include <cstdio>
 #include <cstring>
 #include<algorithm>
 #include<math.h>
 #include<set>
 #include<vector>
 #include<stdlib.h>
 #include<iostream>
 #include<sstream>
 #define MAXN 100005
 #include<stack>
 #define INF 0x7fffffff
 #include<fstream>
 //#define lxc
 using namespace std;
class Solution {
public:
    static bool isBigger(int a, int b) {
        if (a == b)
            return true;
        if (a == 0)
            return false;
        if (b == 0)
            return true;
        int aa = a, bb = b;
        stack<int> sa, sb, tempa,tempb;
        while (a) {
            sa.push(a%10);
            a /= 10;
        }

        while (b) {
            sa.push(b%10);
            b /= 10;
        }
        while (bb) {
            sb.push(bb%10);
            bb /= 10;
        }
        while (aa) {
            sb.push(aa%10);
            aa /= 10;
        }
        while (!sa.empty() || !sb.empty()) {

            int tempa = sa.top();
            sa.pop();
            int tempb = sb.top();
            sb.pop();
            if (tempa > tempb)
                return false;
            else if (tempa < tempb)
                return true;
        }
        return false;
    }
    string largestNumber(vector<int>& nums) {
        stable_sort(nums.begin(),nums.end(), isBigger);
        string ret;
        for (auto i : nums) {
            stringstream ss ;
            ss << i;
            ret += ss.str();
        }

        int i=0;
        while (ret[i] == '0' && i!= ret.size()-1) {
            i++;
        }
        ret = ret.substr(i);
        return ret;
    }
};
/*
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
};
*/
int main()
{

    Solution sol;
    vector<int> v{0,0,0};
    string res = sol.largestNumber(v);
    cout<<res;
}
