#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int m, n;
vector<int> pre, in;

struct Node{
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
    }
};

Node* create(int root, int start, int end){
    if (start > end)
        return nullptr;
    int mid = start;
    while (mid <= end && in[mid] != pre[root])
        mid++;
    Node* cur = new Node(in[mid]);
    cur->left = create(root + 1, start, mid - 1);
    cur->right = create(root + (mid - start) + 1, mid + 1, end);
    return cur;
}

Node* dfs(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;
    if (val == cur->val)
        return cur;

    Node* left = dfs(cur->left, val);
    Node* right = dfs(cur->right, val);
    return left ? left : right;
}

Node* lca(Node* cur, Node* a, Node* b){
    if (cur == nullptr || cur == a || cur == b)
        return cur;
    Node* left = lca(cur->left, a, b), *right = lca(cur->right, a, b);
    if (left && right)
        return cur;
    else
        return left ? left : right;
}

int main(){
    scanf("%d%d", &m, &n);
    pre.resize(n);
    in.resize(n);

    for (int i = 0; i < in.size(); ++i) {
        scanf("%d", &in[i]);
    }

    for (int i = 0; i < pre.size(); ++i) {
        scanf("%d", &pre[i]);
    }

    Node* root = create(0, 0, n - 1);

    while (m--){
        int u, v;
        scanf("%d%d", &u, &v);
        Node *a = dfs(root, u), *b = dfs(root, v);

        if (!a && !b)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!a && b)
            printf("ERROR: %d is not found.\n", u);
        else if (a && !b)
            printf("ERROR: %d is not found.\n", v);
        else{
            Node* s = lca(root, a, b);
            if (s == a)
                printf("%d is an ancestor of %d.\n", u, v);
            else if (s == b)
                printf("%d is an ancestor of %d.\n", v, u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, s->val);
        }
    }

    return 0;
}



/*
int m, n;
vector<int> pre, in;

struct Node{
    int val;
    Node* left, *right;
    Node(int val){
        this->val = val;
    }
};

Node* create(int root, int start, int end){
    if (start > end)
        return nullptr;
    int mid = start;
    while (mid <= end && in[mid] != pre[root])
        mid++;
    Node* cur = new Node(in[mid]);
    cur->left = create(root + 1, start, mid - 1);
    cur->right = create(root + (mid - start) + 1, mid + 1, end);
    return cur;
}

Node* dfs(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;
    if (val == cur->val)
        return cur;

    Node* left = dfs(cur->left, val);
    Node* right = dfs(cur->right, val);
    return (left) ? left : right;
}

Node* lca(Node* cur, Node* a, Node* b){
    if (cur == nullptr || cur == a || cur == b)
        return cur;

    Node *left = lca(cur->left, a, b), *right = lca(cur->right, a, b);
    if (left && right)
        return cur;
    else
        return (left) ? left : right;
}


int main() {
    scanf("%d%d", &m, &n);
    pre.resize(n);
    in.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }

    Node* root = create(0, 0, n - 1);

    while (m--){
        int u, v;
        scanf("%d%d", &u, &v);
        Node *a = dfs(root, u), *b = dfs(root, v);

        if (!a && !b)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (!a && b)
            printf("ERROR: %d is not found.\n", u);
        else if (a && !b)
            printf("ERROR: %d is not found.\n", v);
        else{
            Node* s = lca(root, a, b);
            if (s == a)
                printf("%d is an ancestor of %d.\n", u, v);
            else if (s == b)
                printf("%d is an ancestor of %d.\n", v, u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, s->val);
        }
    }

    return 0;
}

 */
