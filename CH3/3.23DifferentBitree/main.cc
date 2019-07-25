///统计和生成所有不同的二叉树
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

int numTrees(int n){
    vector<int> nums(n+1, 0);
    nums[0] = 1;
    nums[1] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            nums[i] += nums[j]*nums[i - 1 -j];
        }
    }
    return nums[n];
}

vector<Node*> getHeads(int n){
    vector<int> nums(n, 0);
    nums[0] = 1;
    nums[1] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            nums[i] += nums[j]*nums[i - 1 -j];
        }
    }
    vector<vector<Node*> > heads(n+1);
    heads[0].push_back(nullptr);
    Node *newNode = new Node(1);
    heads[1].push_back(newNode);
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            for(int p = 0; p < heads[j].size(); ++p){
                for(int q = 0; q < heads[i - 1 - j].size(); ++q){
                    Node *newNode = new Node(i);
                    newNode->lchild = heads[j][p];
                    newNode->rchild = heads[i - 1 - j][q];
                    heads[i].push_back(newNode);
                }
            }
        }
    }
    return heads[n];
}

void display(Node *n){
    if(!n) return;
    cout<<n->val<<", ";
    display(n->lchild);
    display(n->rchild);
}

int main(){
    int ret = numTrees(1);
    cout<<ret<<endl;
    vector<Node*> result = getHeads(3);
    for(int i = 0; i < result.size(); ++i){
        display(result[i]);
        cout<<endl;
    }
}