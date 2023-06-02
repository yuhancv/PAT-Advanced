#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> v;

struct Node{
    int val;
    Node *left, *right;
    Node(int val, Node* left, Node* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

Node* root = nullptr;

Node* insert(Node* cur, int val){
    if (cur == nullptr){
        cur = new Node(val, nullptr, nullptr);
        return cur;
    }

    if (val < cur->val)
        cur->left = insert(cur->left, val);
    else if (val >= cur->val)
        cur->right = insert(cur->right, val);
    return cur;
}

vector<int> pre;

void preorder(Node* cur){
    if (cur == nullptr)
        return;
    pre.push_back(cur->val);
    preorder(cur->left);
    preorder(cur->right);
}

vector<int> preM;

void preorderM(Node* cur){
    if (cur == nullptr)
        return;
    preM.push_back(cur->val);
    preorderM(cur->right);
    preorderM(cur->left);
}

vector<int> post;

void postorder(Node* cur){
    if (cur == nullptr)
        return;
    postorder(cur->left);
    postorder(cur->right);
    post.push_back(cur->val);
}

vector<int> postM;

void postorderM(Node* cur){
    if (cur == nullptr)
        return;
    postorderM(cur->right);
    postorderM(cur->left);
    postM.push_back(cur->val);
}

int main() {
    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        root = insert(root, v[i]);
    }

    preorder(root);
    preorderM(root);

    if (v == pre){
        postorder(root);
        printf("YES\n");
        for (int i = 0; i < post.size(); ++i) {
            if (i != 0)
                printf(" ");
            printf("%d", post[i]);
        }
    } else if (v == preM){
        printf("YES\n");
        postorderM(root);
        for (int i = 0; i < postM.size(); ++i) {
            if (i != 0)
                printf(" ");
            printf("%d", postM[i]);
        }
    } else{
        printf("NO\n");
    }

    return 0;
}
