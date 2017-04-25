//考察点：DFS
//思路：通过visited数组来保存是否访问过；接下来就是DFS函数了，首先判断结束条件：搜索完所有
//的str。然后是根据1，2长度不断递归，看看哪个符合要求，这里用到一种重要的手法，就是进入
//递归前要置visited为true，出来递归后要置visited为false，这样可以让字符串搜索所有的可能性
//当然，遇到0开头的应该退出；最后的判断是如果搜索到最后一位，就不用再搜索i=2的情况了，还有就是
//如果已经找到答案，那么以前的递归栈就不需要再循环了；

//收获：又一次遇到了DFS，加深了映象，
//经验：if里面经常将==写成=，误了多少次啊！

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
