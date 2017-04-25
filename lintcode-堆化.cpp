
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
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        int len = A.size();
        for (int i = len/2; i>=0; i--) {
            heapify(A, i);
        }
    }
    void heapify(vector<int> &A, int index) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int minIndex = index;
        if (left < A.size() && A[left] < A[minIndex])
            minIndex = left;
        if (right < A.size() && A[right] < A[minIndex])
            minIndex = right;
        if (minIndex != index) {
            swap(A[index], A[minIndex]);
            heapify(A, minIndex);
        }
    }
};
int main() {
    Solution sol;

    vector<vector<string>> str;
    str = sol.partition("aab");
    cout<<endl;
    return 0;
}

