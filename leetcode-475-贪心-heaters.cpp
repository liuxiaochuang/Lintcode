//����㣺̰�ģ�
//˼·�����ȶ�heaters����Ȼ���ÿ��house��ʼ���ҵ���һ��>=house��heaterָ��larger�����
//larger!=v.end������temp��Ҫ����*larger-houses[i]�����larger != heaters.begin()��temp��Ҫ����
//��ѡһ������������ľ��룻

//���飬ѧ����algorithm���lower_bound��upper_bound���÷�����>= �� >��
#include<vector>
#include<iostream>
#include<limits.h>
#include<map>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<string>
#include<string.h>

#include<algorithm>

using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        //sort(houses.begin(), houses.end());
        sort(heaters.begin(),heaters.end());
        //cout<<heaters[0]<<endl;
        int result = 0;
        int temp = 0;

        for (int i=0; i<houses.size(); i++) {   //  for every house;
            auto larger = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            temp = INT_MAX;
            if (larger != heaters.end())
                temp = *larger -houses[i];
            if (larger != heaters.begin()) {
                auto smaller = larger - 1;
                temp = min(temp, houses[i]-*smaller);
            }
            result = max(result,temp);
           // cout<<*heaters.begin()<<endl;
        }
        //at here ,result will be the best smallest distance;
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> houses ;
    vector<int> heaters;
    houses.push_back(1);
    houses.push_back(2);
    houses.push_back(3);
    //houses.push_back(4);
    heaters.push_back(2);
    //heaters.push_back(4);
    cout<<sol.findRadius(houses,heaters);
}

