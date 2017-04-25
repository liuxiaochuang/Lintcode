
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<queue>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<string>
#include<hash_map>
#include<memory>
#include<math.h>
//#include<string.h>

#include<algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        int low = 0;
        int high = len - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[low] < nums[high])
                return nums[low];
            //if (nums[low] == nums[high] && low == high)
            //    return nums[low];
            if (nums[low] < nums[mid]) {
                low = mid + 1;
            }else if (nums[low] > nums[mid]) {
                high = mid;
            } else {
                low++;
            }


        }
        return nums[low];
    }
};
int main() {

}

