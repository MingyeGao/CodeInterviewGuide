///在二叉树中找到累加和为指定值的最长路径长度

#include <iostream>
#include <map>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){};
};

Node *testCase1(){
    Node *node1 = new Node(-3);
    Node *node2 = new Node(3);
    Node *node3 = new Node(-9);
    Node *node4 = new Node(1);
    Node *node5 = new Node(0);
    Node *node6 = new Node(2);
    Node *node7 = new Node(1);
    Node *node8 = new Node(1);
    Node *node9 = new Node(6);

    node1->lchild = node2;
    node1->rchild = node3;
    node2->lchild = node4;
    node2->rchild = node5;
    node5->lchild = node7;
    node5->rchild = node9;
    node3->lchild = node6;
    node3->rchild = node9;
    return node1;
}

int getMaxLen(Node *head, int sum, int preSum, map<int, int> mapSumLevel, int level, int maxLen){
    if(!head) return maxLen;
    int curSum = head->val + preSum;
    int diff = curSum - sum;
    if(mapSumLevel.find(curSum) == mapSumLevel.end()){
        mapSumLevel[curSum] = level;
    }
    
    if(mapSumLevel.find(diff) != mapSumLevel.end()){
        int thisMaxLen = level - mapSumLevel[diff];
        if(thisMaxLen > maxLen) maxLen = thisMaxLen;
    }

    maxLen = getMaxLen(head->lchild, sum, curSum, mapSumLevel, level + 1, maxLen);
    maxLen = getMaxLen(head->rchild, sum, curSum, mapSumLevel, level + 1, maxLen);

    if(level == mapSumLevel[diff]){
        mapSumLevel.erase(diff);
    }

    return maxLen;
}

int findDeepestPath(Node *root, int sum){
    map<int, int> mapSumLevel;
    mapSumLevel[0] = 0;
    int maxLen = getMaxLen(root, sum, 0, mapSumLevel, 1, 0);
    return maxLen;
}

int main(){
    Node *root = testCase1();
    int ret = findDeepestPath(root, -9);
    cout<<ret<<"\n";
}