//设计前缀树并实现搜索功能，只要掌握了原理，就可以轻松自如解决问题。
//leetcode-211. Add and Search Word - Data structure design
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
class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct Node {
        Node(){
            for (int i=0; i<28; i++) {
                chd[i] = NULL;
            }
        }
        Node * chd[28];
    };
    Node *root;
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur = root;
        int len = word.size();
        for (int i=0; i<len; i++) {
            if (cur->chd[word[i] - 'a'] == NULL) {
                Node * temp = new Node();
                cur->chd[word[i] - 'a'] = temp;
                cur = temp;
            } else {
                cur = cur->chd[word[i] - 'a'];
            }
        }
        cur->chd[26] = new Node();
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Node * cur = root;
        return helpSearch(cur, word, 0);
    }
    bool helpSearch(Node * cur, string &word, int index) {
        if (cur == NULL)
            return false;
        if (word.size()==index && cur->chd[26]!=NULL)
            return true;
        if (word.size()==index && cur->chd[26]==NULL)
            return false;
        if (word[index] == '.') {
            bool temp = false;
            for (int i=0; i<26; i++) {
                temp = temp | helpSearch(cur->chd[i],  word, index + 1);
            }
            if (temp)
                return true;
            else
                return false;
        } else {
            if (cur->chd[word[index] - 'a'] == NULL)
                return false;
            else {
                return helpSearch(cur->chd[word[index] - 'a'],word,index+1);
            }
        }

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main() {
    string str = "qwe";
    cout<<(*str.end() == str[3]);

}

