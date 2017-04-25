#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
class Interval{
public:
	int start,end;
	Interval(int start, int end){
		this->start= start;
		this->end= end;
	}
};
void print(vector<Interval>& intervals);
bool comp(Interval& i1, Interval &i2) {
        return i1.start < i2.start;
    }
class Solution{
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        std::sort(intervals.begin(), intervals.end(),comp);
        cout<<"sorted:"<<endl;
        print(intervals);
        int i=1;
        while(true) {
            if (i>=intervals.size())
                break;
            if(intervals[i-1].end >= intervals[i].end){
                //intervals[i-1].end = intervals[i].end;
                intervals.erase(intervals.begin()+i);
            }else if(intervals[i-1].end>=intervals[i].start){
            	intervals[i-1].end = intervals[i].end;
                intervals.erase(intervals.begin()+i);
            }else{
            	i++;
            }
        }
        return intervals;
    }
    
};
void print(vector<Interval>& intervals){
	for (auto i : intervals){
		cout<<"interval start:"<<i.start<<" end:"<<i.end<<endl;
	}
}

int main(){
	vector<Interval> vec ;
	srand((unsigned)time(NULL));
	for (int i =0; i<5; i++){
		int a = rand()%50;
		Interval temp = Interval(a,a+rand()%30);
		vec.push_back(temp);
	}
	print(vec);
	Solution sol = Solution();
	sol.merge(vec);
	cout<<"sorted:"<<endl;
	print(vec);
}


