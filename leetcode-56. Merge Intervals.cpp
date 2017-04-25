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
 #define INF 0x7fffffff
 #define lxc
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        if (len == 0 || len == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            if (a.start < b.start)  return true;
            if (a.start == b.start) return a.end<b.end;
            return false;
        });
        vector<Interval> ret;
        Interval temp;
        temp.start = intervals[0].start;
        temp.end = intervals[0].end;
        for (int i=0; i<intervals.size(); i++) {
            if (intervals[i].start <= temp.end) {
                temp.end = max(temp.end, intervals[i].end);
                if (i == intervals.size()-1) {
                    ret.push_back(temp);
                }
            } else {
                ret.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
                if (i == intervals.size()-1) {
                    ret.push_back(temp);
                }
            }

        }
        return ret;
    }
};
