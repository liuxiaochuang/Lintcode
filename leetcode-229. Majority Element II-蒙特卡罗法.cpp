
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
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int> res;
        if (nums.size() == 0)
            return vector<int>();
        int len = nums.size();
        srand(time(NULL));
        for (int i=0; i<100; i++) {
            int randIndex = rand()%len;
            int temp = nums[randIndex];
            int count1 = 0;
            for (int j = 0; j<len; j++) {
                if (nums[j] == nums[randIndex])
                    count1++;
            }
            if (count1 > len/3)
                res.insert(nums[randIndex]);
        }

        return vector<int>(res.begin(),res.end());
    }
};
int main() {
    default_random_engine e();

    for (int i=0; i<10; i++) {
        cout<< e()<<endl;
    }
    cout<<endl;

}

