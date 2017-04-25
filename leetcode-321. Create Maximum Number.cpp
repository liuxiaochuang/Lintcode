#include <cstdio>
 #include <cstring>
 #include<algorithm>
 #include<math.h>
 #include<set>
 #include<vector>
 #include<stdlib.h>
 #include<iostream>
 #include<map>
 #include<vector>
 #define MAXN 2010
 #define INF 0x7fffffff
// thought : from the end to the start to start dynamic programming; dp[i][j] represents
typedef long long ll;
using namespace std;
int a[MAXN];

class Solution {
public:
    map<int, vector<int>> find(vector<int> nums, int k) {
        map<int, vector<int>> ret;

        for (int i=nums.size(); i>=0; i--) {
                //cout<<nums.size()<<"i"<<i<<endl;
                if (i == 0) {
                    nums.clear();
                   // cout<<"i = 0 size: "<<nums.size()<<endl;
                }
            if (i <= k) {

                ret[i] = nums;
            }
            for (int j = 0; j<i-1; j++) {
                if (i == 1) {
                    nums.clear();
                    //cout<<"have clear:"<<nums.size()<<endl;
                    break;
                } else if (nums[j] < nums[j+1]) {
                    nums.erase(nums.begin()+j);
                    break;
                } else if (j == i-2) {
                    nums.erase(nums.begin()+j+1);
                    break;
                }
            }
        }

        return ret;
    }
    vector<int> merge(map<int, vector<int> > &map1,  map<int, vector<int> > &map2, int i, int j) {
        vector<int> ret;
        if (map1.find(i) == map1.end() || map2.find(j) == map2.end()) {
            return ret;
        }
        vector<int> temp1 = map1[i];
        vector<int> temp2 = map2[j];
        while (!temp1.empty() || !temp2.empty()) {
            if (!temp1.empty() && !temp2.empty()) {
                if (temp1[0] > temp2[0]) {
                    ret.push_back(temp1[0]);
                    temp1.erase(temp1.begin()+0);
                } else if (temp1[0] < temp2[0]){
                    ret.push_back(temp2[0]);
                    temp2.erase(temp2.begin()+0);
                } else {
                    int next1=temp1[0],next2=temp2[0];
                    int ii=1, jj=1, flag = 1;
                    while (next1 == next2) {
                        if (temp1.size()==ii && temp2.size()==jj)
                            break;
                        if (temp1.size()==ii){
                            next1 = 0;
                        } else {
                            next1 = temp1[ii];
                            ii++;
                        }
                        if (temp2.size() == jj) {
                            next2 = 0;
                        } else {
                            next2 = temp2[jj];
                            jj++;
                        }
                    }
                    if (next1 > next2) {
                        ret.push_back(temp1[0]);
                        temp1.erase(temp1.begin());
                    } else {
                        ret.push_back(temp2[0]);
                        temp2.erase(temp2.begin());
                    }


                }
            } else if (!temp1.empty()) {
                while (!temp1.empty()) {
                    ret.push_back(temp1[0]);
                    temp1.erase(temp1.begin()+0);
                }
            } else {
                while (!temp2.empty()) {
                    ret.push_back(temp2[0]);
                    temp2.erase(temp2.begin()+0);
                }
            }
        }
        return ret;
    }
    bool isBigger(vector<int> & cur, vector<int> &temp) {
        if (temp.size() > cur.size()) {
            return true;
        }
        for (int i=0; i<cur.size(); i++) {
            if (cur[i] > temp[i]) {
                return false;
            } else if (cur[i] < temp[i]) {
                return true;
            }
        }
        return false;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        map<int, vector<int> > map1;
        map<int, vector<int> > map2;
        map1 = find(nums1, k);
        map2 = find(nums2, k);

        vector<int> cur;
        for (int i=0; i<=k; i++) {
            vector<int> temp = merge(map1,map2,i, k-i);
            if (temp.size() == 0)
                continue;
            if (isBigger(cur, temp)) {
                cur = temp;
            }
        }
        ret = cur;
        return ret;
    }
};
int main()
 {
     Solution sol;
     vector<int> res;
     vector<int> t1{2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5};
     vector<int> t2{2,6,2,0,1,0,5,4,5,5,3,3,3,4};
     res = sol.maxNumber(t1,t2,35);
     for (auto i : res) {
        cout<<i<<" ";
     }
 }
