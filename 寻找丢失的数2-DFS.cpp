//����㣺DFS
//˼·��ͨ��visited�����������Ƿ���ʹ�������������DFS�����ˣ������жϽ�������������������
//��str��Ȼ���Ǹ���1��2���Ȳ��ϵݹ飬�����ĸ�����Ҫ�������õ�һ����Ҫ���ַ������ǽ���
//�ݹ�ǰҪ��visitedΪtrue�������ݹ��Ҫ��visitedΪfalse�������������ַ����������еĿ�����
//��Ȼ������0��ͷ��Ӧ���˳��������ж���������������һλ���Ͳ���������i=2������ˣ����о���
//����Ѿ��ҵ��𰸣���ô��ǰ�ĵݹ�ջ�Ͳ���Ҫ��ѭ���ˣ�

//�ջ���һ��������DFS��������ӳ��
//���飺if���澭����==д��=�����˶��ٴΰ���

#include<stdlib.h>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param n an integer
     * @param str a string with number from 1-n in
     *            random order and miss one number
     * @return an integer
     */
     int ans=0;
    int findMissing2(int n, string& str) {
        if ( str.size()==0)
            return 0;
        bool visited[n+1];

        process(visited,n,0,0,str);
        return ans;
    }
    void process(bool *visited, int n, int sum, int index, string &str) {
                //cout<<str.size()<<endl;
        if (index == str.size()) {
            ans = (n+1)*n/2 - sum;
            for (int i=0; i<n+1; i++)
            //cout<<" "<<visited[i];
            return;
        }
        for (int i=1; i<=2; i++) {

            int num = atoi(str.substr(index,i).c_str());
           // cout<<num<<endl;
            if (num == 0)
                break;
            if (num <=n && !visited[num]) {
                visited[num] = true;
                //cout<<num<<endl;
                process(visited, n, sum + num, index +i, str);
                visited[num] = false;
            }
            if (index == str.size()-1 || ans != 0)
            break;

        }

    }
};

int main() {
    Solution sol;
    string str ="19201234568910117121314151618";
    int res = sol.findMissing2(20,str);
    cout<<res;
    return 0;
}
