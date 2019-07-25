///统计完全二叉树的节点数
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

Node *generateCBT(int n){
    vector<Node*> Nodes(n);
    for(int i = 0; i < n; ++i){
        Nodes[i] = new Node(i);
    }

    for(int i = 0; i < n; ++i){
        if((2 * i + 1) >= n){
            break;
        }
        Nodes[i]->lchild = Nodes[2*i + 1];

        if((2*i + 2) >= n) break;
        Nodes[i]->rchild = Nodes[2 * i + 2];
    }

    return Nodes[0];
}

int mostLeftLevel(Node *t, int l){
    if(!t) return 0;
    while(t->lchild){
        ++l;
        t = t->lchild;
    }
    return l;
}

int bs(Node *node, int l, int h){
    if(l == h) return 1;

    if(mostLeftLevel(node->rchild, l+1) == h){
        int val = ((1<<(h-l)) + bs(node->rchild, l+1, h));
        return val;
    }
    else{
        int val = ((1<<(h-1-l)) + bs(node->lchild, l+1, h));
        return val;
    }
}

int getCBTNum(Node *t){
    if(!t) return 0;
    int val = bs(t, 1, mostLeftLevel(t, 1));
    return val;
}

int main(){
    Node *t = generateCBT(7);
    int ret = getCBTNum(t);
    cout<<ret<<endl;
}