// You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest
// common prefix among all these strings. 
//If there is no common prefix, you have to return an empty string.

// A prefix of a string can be defined as a substring obtained after removing some or all 
//characters from the end of the string.

// For Example:
// Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
// The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.




#include <bitset>/stdc++.h>
using namespace std;


struct Node {
  Node* Link[26];
  bool flag=false;
  int cnt=0;

  Node()
  {
      for(int i=0;i<26;i++)
      {
          Link[i]=NULL;
      }
  }

  void put(char ch, Node* node)
  {
    Link[ch-'a']=node;
  }

  Node* get(char ch)
  {
      return Link[ch-'a'];
  }

  void setEnd()
  {
     flag=true;
  }

  bool isEnd()
  {
      return flag;
  }

  bool containsKey(char ch)
  {
      return (Link[ch-'a']!=NULL)
  }

  void incCnt()
  {
      cnt++;
  }

  int getCnt()
  {
      return cnt;
  }

};

class Trie{

    private: 
    Node* root;

    public:

    Trie()
    {
        root = new Node();
    }

    //insert words , very simple

    void insert(string & word)
    {
        Node* node=root;

        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i], new Node);
                node->incCnt();
            }

            node = node->get(word[i]);
        }
        node->setEnd();
    }
   
   string longestPrefix(){
       Node* node= root;
       
       string ans="";
       while(node){
           int cnt=0;
            
            char ch;
           for(int i=0;i<26;i++)
           {
               if(node->containsKey(char(i+'a')))
               {
                   cnt++;
                   ch = i+'a';
               }
           }

           if(cnt!=1 || node->isEnd()) break;

           ans+=ch;
           node=node->get(ch);
       }
   }

};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie tree;

    for(auto x:arr)
    {
        tree.insert(x);
    }

   return longestPrefix;

}


