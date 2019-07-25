#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x = 0):val(x), left(nullptr), right(nullptr){};
};

Node *generateBiSearchTree(int length){
    if(length == 0) return nullptr;
    srand(5);
    Node *root = nullptr;
    int range = 15;
    for(int i = 0; i < length; ++i){
        int val = rand()%20;
        Node *newNode = new Node(val);
        if(root == nullptr){
            root = newNode;
            continue;
        }

        Node *current = root;
        while(true){
            if(current->val == val){
                delete newNode;
                break;
            }
            if(val > current->val){
                if(current->right == nullptr){
                    current->right = newNode;
                    break;
                }
                else{
                    current = current->right;
                }
            }
            else{
                if(current->left == nullptr){
                    current->left = newNode;
                    break;
                }
                else{
                    current = current->left;
                }
            }
        }
    }
    return root;
}

Node *core(Node *treeNode){
    if(treeNode == nullptr) return nullptr;

    Node *left = core(treeNode->left);
    Node *right = core(treeNode->right);
    
    Node *frontNode = treeNode, *backNode = treeNode; 
    if(left){
        frontNode = left;
        Node *leftBack = left->left;
        leftBack->right = treeNode;
        treeNode->left = leftBack;
    }
    if(right){
        backNode = right->left;
        treeNode->right = right;
        right->left = treeNode;
    }
    
    frontNode->left = backNode;
    backNode->right = frontNode;

    return frontNode;
}

Node *biTree2List(Node *root){
    Node *list = core(root);
    Node *listEnd = list->left;
    listEnd->right = nullptr;
    list->left = nullptr;

    return list;
}

void display(Node *list){
    Node *p = list;
    Node *reverseP;
    while(p){
        cout<<p->val<<", ";
        if(!p->right){
            reverseP = p;
        }
        p = p->right;
    }
    cout<<endl;
    while(reverseP){
        cout<<reverseP->val<<", ";
        reverseP = reverseP->left;
    }
    cout<<endl;
}

int main(){
    Node *treeRoot = generateBiSearchTree(10);
    Node *list = biTree2List(treeRoot);
    display(list);
}