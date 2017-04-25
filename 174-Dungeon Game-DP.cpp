//174. Dungeon Game
//�����DP���������ϣ����������ε�����dp[i][j]��ʾ���ߵ�dungeon[i][j]��ʱ����Ҫ������ֵ������
//����
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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int clos = dungeon[0].size();
        vector<vector<int>> dp(rows+1,vector<int>(clos+1,INT_MAX));
        dp[rows][clos-1] = 1;
        dp[rows-1][clos] = 1;
        for (int i=rows-1; i>=0; i--) {
            for (int j=clos-1; j>=0; j--) {
                int temp = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = temp<=0? 1 : temp;
            }
        }
        return dp[0][0];
    }

};
int main() {
    string str = "qwe";
    cout<<(*str.end() == str[3]);

}

