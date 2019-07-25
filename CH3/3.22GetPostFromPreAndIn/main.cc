///通过先序和中序生成后序数组
#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    Node *lchild;
    Node *rchild;
    Node(int x = 0):val(x), lchild(nullptr), rchild(nullptr){}
};

void getPostFrom(vector<int> &pre, vector<int> &in, int preStart, int preEnd,
                 int inStart, int inEnd, vector<int> &post, int postIndex){
    
    if(preStart > preEnd) return;
    post[postIndex] = pre[preStart];
    int index = inStart;
    for(; index < inEnd; ++index){
        if(in[index] == pre[preStart]){
            break;
        }
    }

    int llen = index - inStart;
    int rlen = inEnd - index;
    getPostFrom(pre, in, preStart+1, preStart+llen, inStart, index-1, post, postIndex-1-rlen);
    getPostFrom(pre, in, preStart+llen+1, preEnd, index+1, inEnd, post, postIndex-1);

}

int main(){
    vector<int> pre({1, 2, 4, 5, 3, 6, 7});
    vector<int> in({4, 2, 5, 1, 6, 3, 7});
    vector<int> post(pre.size());
    getPostFrom(pre, in, 0, 6, 0, 6, post, 6);
    for(int i = 0; i < post.size(); ++i){
        cout<<post[i]<<", ";
    }
}