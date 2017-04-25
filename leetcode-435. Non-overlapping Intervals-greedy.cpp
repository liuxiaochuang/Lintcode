//#define lxc
#include<stack>
#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<string.h>
#include<queue>
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<math.h>

using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 // if you sort the intervals as intervals's end as an ascending order, the indexs that overlap with i must overlap with each other;
 // so we can erase these intervals overlap with i;
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int len = intervals.size();
        if (len == 0 || len == 1)
            return 0;
        sort(intervals.begin(), intervals.end(),[](Interval a, Interval b) {
            if (a.end < b.end)  return true;
            if (a.end == b.end) return a.start <b.start;
            return false;
        });
        int index = 0;
        int sum = 0;
        for (int i=1; i<len; i++) {
            if (intervals[i].start < intervals[index].end) {
                sum++;
            } else {
                index = i;
            }
        }
        return sum;
    }
};
int main(){
    #ifdef lxc
    freopen("in.txt","r", stdin);
    #endif // lxc

    #ifdef lxc
    fclose(stdin);
    #endif // lxc
    return 0;
}



