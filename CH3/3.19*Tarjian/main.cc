///用Targan算法和并查集解决二叉树节点间最近公共祖先问题
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <initializer_list>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

struct DisjoinSet{
    map<Node*, Node*> fatherMap;
    map<Node*,int> rankMap;

    Node *findFather(Node *n){
        Node *current = fatherMap[n];
        while(current != fatherMap[current]){
            current = fatherMap[current];
        }
        fatherMap[n] = current;
        return current;
    }

    void join(Node *n1, Node *n2){
        if(n1 == nullptr || n2 == nullptr){
            return;
        }

        Node *n1Father = fatherMap[n1];
        Node *n2Father = fatherMap[n2];

        if(n1Father != n2Father){
            int n1FatherRank = rankMap[n1Father];
            int n2FatherRank = rankMap[n2Father];
            if(n1FatherRank < n2FatherRank){
                fatherMap[n1Father] = n2Father;
            }
            else if(n1FatherRank > n2FatherRank){
                fatherMap[n2Father] = n1Father;
            }
            else{
                fatherMap[n1Father] = n2Father;
                rankMap[n2Father] += 1;
            }
        }
    }

    void preOrderMake(Node *node){
        if(!node) return;
        fatherMap[node] = node;
        rankMap[node] = 0;
        preOrderMake(node->lchild);
        preOrderMake(node->rchild);
    }
};

struct Query{
    Node *node1;
    Node *node2;
    Query(Node *n1, Node *n2):node1(n1), node2(n2){};
};

void setAnswers(Node *root, vector<Node*> &answers, DisjoinSet &set, 
                map<Node*, Node*> &ancestorMap, map<Node*, list<Node*>> &queryMap,
                map<Node*, list<int>> &indexMap){
    if(!root) return;
    
    set.fatherMap[root] = root;

    setAnswers(root->lchild, answers, set, ancestorMap, queryMap, indexMap);
    set.join(root->lchild, root);
    ancestorMap[set.findFather(root)] = root;

    setAnswers(root->rchild, answers, set, ancestorMap, queryMap, indexMap);
    set.join(root->rchild, root);
    ancestorMap[set.findFather(root)] = root;

    list<Node*> queryNodes = queryMap[root];
    list<int> answerIndex = indexMap[root];
    int size = queryNodes.size();
    for(int i = 0; i < size; ++i){
        int index = answerIndex.front();
        queryMap[root].pop_front();
        Node* node = queryNodes.front();
        indexMap[root].pop_front();
        Node* nodeFather = set.findFather(node);
        if(ancestorMap.find(node) != ancestorMap.end()){
            answers[index] = ancestorMap[nodeFather];
        }
    }
}

vector<Node*> Tarjan(Node *head, vector<Query> query){
    DisjoinSet set;
    vector<Node*> ret(query.size());
    map<Node*, list<Node*>> queryMap;
    map<Node*, list<int>> indexMap;
    map<Node*, Node*> ancestorMap;

    ///fill queryMap and indexMap
    for(int i = 0; i < query.size(); ++i){
        Node *node1 = query[i].node1;
        Node *node2 = query[i].node2;
        if(queryMap.find(node1) == queryMap.end()){
            list<Node*> newNodeList;
            newNodeList.push_back(node2);
            queryMap[node1] = newNodeList;
        }
        else{
            auto nodeList = queryMap[node1];
            nodeList.push_back(node2);
        }

        if(queryMap.find(node2) == queryMap.end()){
            list<Node*> newNodeList;
            newNodeList.push_back(node1);
            queryMap[node2] = newNodeList;
        }
        else{
            auto nodeList = queryMap[node2];
            nodeList.push_back(node1);
        }
        

        if(indexMap.find(node1) == indexMap.end()){
            list<int> newIndexList;
            newIndexList.push_back(i);
            indexMap[node1] = newIndexList;
        }
        else{
            auto indexList = indexMap[node1];
            indexList.push_back(i);
        }
        if(indexMap.find(node2) == indexMap.end()){
            list<int> newIndexList;
            newIndexList.push_back(i);
            indexMap[node2] = newIndexList;
        }
        else{
            auto indexList = indexMap[node2];
            indexList.push_back(i);
        }
    }

    setAnswers(head, ret, set, ancestorMap, queryMap, indexMap);

    return ret;
}

Node *testCase(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node3->lchild = node6;
    node3->rchild = node7;
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node3->lchild = node6;
    node3->rchild = node7;

    vector<Query> queries({{node2, node3}});
    vector<Node*> ret = Tarjan(node1, queries);
    for(int i = 0; i < ret.size(); ++i){
        cout<<ret[i]->val<<", ";
    }
}