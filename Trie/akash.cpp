// You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest
// common prefix among all these strings. 
//If there is no common prefix, you have to return an empty string.

// A prefix of a string can be defined as a substring obtained after removing some or all 
//characters from the end of the string.

// For Example:
// Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
// The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.


#include <bits/stdc++.h>

using namespace std;


struct Node {
    Node* Link[26];
    bool flag;

    Node() {
        for (int i = 0; i < 26; ++i)
            Link[i] = nullptr;
        flag = false; // Should only be true for the end of a word
    }

    void put(char ch, Node* node) {
        Link[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return Link[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    bool containsKey(char ch) {
        return Link[ch - 'a'] != nullptr;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->get(ch);
        }
        node->setEnd();
    }

    string longestPrefix() {
        Node* node = root;
        string ans;
        while (node) {
            int cnt = 0;
            char ch;
            for (int i = 0; i < 26; i++) {
                if (node->containsKey(char(i + 'a'))) {
                    cnt++;
                    ch = i + 'a';
                }
            }
            if (cnt != 1 || node->isEnd())
                break;
            ans += ch;
            node = node->get(ch);
        }
        return ans;
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    Trie tree;

    for (auto x : arr) {
        tree.insert(x);
    }

    return tree.longestPrefix();
}