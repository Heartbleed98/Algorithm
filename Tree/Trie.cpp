#include<iostream>
#include<string>
using namespace std;

class TrieNode{
public:
    TrieNode* next[26];
    bool isEnd;
    TrieNode(){
        memset(next, NULL, sizeof(next));
        isEnd = false;
    }
    ~TrieNode(){
        for(int i=0;i<26;i++)
            if(next[i])
                delete next[i];
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    ~Trie(){
        delete root;
    }

    void insert(string word){
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(p->next[word[i]-'a'] == NULL)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->isEnd = true;
    }

    bool search(string word){
        TrieNode* p = root;
        for(int i = 0; i < word.size() && p; i++)
            p = p->next[word[i]-'a'];
        return p && p->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.size() && p; i++)
            p = p->next[prefix[i]-'a'];
        return p;
    }
};
