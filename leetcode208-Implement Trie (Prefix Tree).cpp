//字典树的demo，简单易实现
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
class Trie {
public:
    /** Initialize your data structure here. */
    struct Node{
        char c;
        Node(char ch) : c(ch){
            for (int i=0; i<27; i++)
                chd[i] = NULL;
        };
        Node *chd[27];
    };

    Node *root;
    Trie() {
        root = new Node('0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();
        Node * cur = root;
        for (int i=0; i<len; i++) {
            if (cur->chd[word[i] - 'a'] == NULL) {
                Node *temp = new Node(word[i]);
                cur->chd[word[i] - 'a'] = temp;
                cur = temp;
            } else {
                cur = cur->chd[word[i] - 'a'];
            }

        }
        cur->chd[26] = new Node('1');
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * cur = root;
        int len = word.size();
        for (int i=0; i<len; i++) {

            if (cur->chd[word[i] - 'a'] == NULL)
                return false;
            else {
                cur = cur->chd[word[i] - 'a'];
            }
        }
        if (cur->chd[26] != NULL && cur->chd[26]->c == '1')
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * cur = root;
        int len = prefix.size();
        for (int i=0; i<len; i++) {
            if (cur->chd[prefix[i] - 'a'] == NULL)
                return false;
            else {
                cur = cur->chd[prefix[i] - 'a'];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main() {
    Trie sol;
    //sol.Trie();

    sol.insert("a");
    cout<<"search"<<sol.search("a")<<endl;
    cout<<"start with:"<<sol.startsWith("a")<<endl;

}

