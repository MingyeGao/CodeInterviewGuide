///前缀树的实现
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Node{
    char val;
    bool isEnd;
    int resultNum;
    unordered_map<char, Node*> children;
    Node(char x = 'a'):val(x), isEnd(false), resultNum(1){}
};

struct TrieTree{
    Node *root;
    TrieTree(){
        root = new Node();
    }

    void insert(string &word);
    void remove(string &word);
    bool search(string &word);
    int prefixNumber(string &word);
};

void TrieTree::insert(string &word){
    Node *current = root;
    int i = 0;
    while(i < word.size()){
        if(current->children.find(word[i]) == current->children.end()){
            Node *newNode = new Node(word[i]);
            current->children[word[i]] = newNode;
            current = newNode;
        }
        else{
            current = current->children[word[i]];
            current->resultNum++;
        }
        ++i;
    }
    current->isEnd = true;
}

bool TrieTree::search(string &word){
    Node *current = root;
    int i = 0;
    while(current && i < word.size()){
        if(current->children.find(word[i]) != current->children.end()){
            current = current->children[word[i]];
            ++i;
        }
        else{
            return false;
        }
    }

    if(current && current->isEnd){
        return true;
    }
    else{
        return false;
    }
}

void TrieTree::remove(string &word){
    bool exist = search(word);
    if(!exist) return;

    Node *current = root;
    int i = 0;
    while(i < word.size()){
        current = current->children[word[i]];
        current->resultNum--;
        ++i;
    }

    if(current->resultNum == 0){
        current->isEnd = false;
    }
}

int TrieTree::prefixNumber(string &word){
    int i = 0;
    Node *current = root;
    while(current && i < word.size()){
        current = current->children[word[i]];
        ++i;
    }

    if(current){
        return current->resultNum;
    }
    else{
        return 0;
    }
}

int main(){
    TrieTree *tree = new TrieTree();
    string s = "hello";
    string s2 = "h",s3 = "j";
    tree->insert(s);
    assert(tree->search(s));
    assert(tree->prefixNumber(s2) == 1);
    assert(tree->prefixNumber(s3) == 0);

}