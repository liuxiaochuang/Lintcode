
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
        set<string> res;
        help(res,num,0,0);
        vector<string> ret(res.begin(),res.end());
        return ret;
    }
    void help(set<string> &res, int num, int hour, int minute) {
        if (num == 0) {
            if (hour >=12 || minute >59)
                return;
            cout<<hour<< " "<<minute<<endl;
            stringstream s1,s2;
            s1 << hour;
            s2 << minute;
            if (minute < 10) {
                res.insert(s1.str() + ":" + "0" + s2.str());
            } else {
                res.insert(s1.str() + ":" + s2.str());
            }
            return;
        }

        for (int i=0; i<4; i++) {
            int temp = (1<<i);
            //cout<<"temp :"<<temp<<endl;
            if ((hour & temp) != temp) {
                hour = hour | temp;
                help(res, num-1, hour, minute);
                temp = (~temp);
                hour  = hour & temp;
            }

        }
        for (int i=0; i<6; i++) {
            int temp = (1<<i);
            if ((minute & temp)  != temp) {
                minute = minute | temp;
                help(res, num-1, hour, minute);
                temp = (~temp);
                minute  = minute & temp;
            }
        }

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

