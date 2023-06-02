#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int m, n;

struct Node{
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
    }
};

vector<int> pre, in;

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

Node* findNode(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;
    while (cur){
        if (val == cur->val)
            break;
        else if (val < cur->val)
            cur = cur->left;
        else if (val > cur->val)
            cur = cur->right;
    }

    return cur;
}

Node* lca(Node* cur, Node *a, Node *b){
    if (cur == nullptr || cur == a || cur == b)
        return cur;
    Node *left = lca(cur->left, a, b), *right = lca(cur->right, a, b);
    if (left && right)
        return cur;
    else
        return (left) ? left : right;
}

int main(){
    scanf("%d%d", &m, &n);
    pre.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }

    in = pre;
    sort(in.begin(), in.end());
    Node* root = create(0, 0, n - 1);

    while (m--){
        int u, v;
        scanf("%d%d", &u, &v);
        Node *a = findNode(root, u), *b = findNode(root, v);

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
    Node *left, *right;
    Node(int val){
        this->val= val;
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

Node* findNode(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;

    while (cur){
        if (cur->val == val)
            break;
        else if (val < cur->val)
            cur = cur->left;
        else if (val > cur->val)
            cur = cur->right;
    }

    return cur;
}

Node* lca(Node* cur, Node* a, Node* b){
    if (cur == nullptr || cur == a || cur == b)
        return cur;
    Node* left = lca(cur->left, a, b);
    Node* right = lca(cur->right, a, b);
    if (left && right)
        return cur;
    else
        return (left) ? left : right;
}

int main() {
    scanf("%d%d", &m, &n);
    pre.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }

    in = pre;
    sort(in.begin(), in.end());

    Node* root = create(0, 0, n - 1);

    while (m--){
        int u, v;
        scanf("%d%d", &u, &v);
        Node *a = findNode(root, u), *b = findNode(root, v);

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
