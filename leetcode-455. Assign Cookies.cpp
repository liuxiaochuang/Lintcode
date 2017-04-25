class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sum = 0;
        sort(g.begin(), g.end());
        sort(s.begin(),s.end());
        int glen = g.size();
        int slen = s.size();
        int i=0,j=0;
        while (i != glen && j != slen) {
            if (s[j] >=g[i]) {
                sum++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return sum;
    }
};
