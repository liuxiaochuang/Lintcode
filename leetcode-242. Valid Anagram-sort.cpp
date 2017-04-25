#include <cstdio>
 #include <cstring>
 #include<algorithm>
 #include<math.h>
 #include<set>
 #include<queue>
 #include<vector>
 #include<stdlib.h>
 #include<iostream>
 #include<sstream>
 #include<utility>
 #define MAXN 100005
 #include<stack>
 #define INF 0x7fffffff
 #include<fstream>
 #include<time.h>
 //#define lxc
 using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map1, map2;
        if (s.size() != t.size())
            return false;
        for (auto i : s) {
            if (map1.find(i) != map1.end()) {
                map1[i]+=1;
            } else {
                map1[i] = 1;
            }
        }
        for (auto i : t) {
            if (map2.find(i) != map2.end()) {
                map2[i] += 1;
            } else {
                map2[i] = 1;
            }
        }
        bool ret = true;
        for (auto i : map1) {
            char first = i.first;
            int second = i.second;
            if (map2.find(first) == map2.end() || map2[first] != second){
                ret = false;
                break;
            }
        }
        return ret;
    }
};

/*
The idea is simple. It creates a size 26 int arrays as buckets
 for each letter in alphabet. It increments the bucket value with
    String s and decrement with string t. So if they are anagrams,
    all buckets should remain with initial value which is zero.
    So just checking that and return

public class Solution {
    public boolean isAnagram(String s, String t) {
        int[] alphabet = new int[26];
        for (int i = 0; i < s.length(); i++) alphabet[s.charAt(i) - 'a']++;
        for (int i = 0; i < t.length(); i++) alphabet[t.charAt(i) - 'a']--;
        for (int i : alphabet) if (i != 0) return false;
        return true;
    }
}*/

int main()
{
    string s = "adsfasdfa";
    for (auto i : s)
        cout<<i<<" ;";

}
