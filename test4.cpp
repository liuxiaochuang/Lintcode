
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<set>

using namespace std;

int partirion(vector<int> &nums, int start , int last) {
    int x = nums[last];
    int i = start;
    int j = start ;
    while (j != last+1) {
        if (nums[i] > x) {
            swap(nums[i], nums[j]);
        } else {
            i++;
        }
        j++;
    }
    swap(nums[i],nums[last]);
    return i;
}

int main() {
    vector<int> nums{53,137,163,17,59,61,71,227,233,251,263,167,181,
    73,79,83,97,109,131,23,29,31,43,191,193,197,199,5,7,13};
    int mid = 5,low = 0,high = nums.size()-1;
    int temp = partition(nums,0,nums.size()-1);
    while(temp != mid) {
        if (temp > mid) {
            high = temp;
            temp = partition(nums, low, high);

        } else {
            low = temp;
            temp = partition(nums, low, high);
        }


    }
    cout<<nums[temp];
}
