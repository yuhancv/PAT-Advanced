#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n;
struct Node{
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
    }
};

vector<int> in, post;

Node* create(int root, int start, int end){
    if (start > end)
        return nullptr;
    int mid = start;
    while (mid <= end && in[mid] != post[root])
        mid++;

    Node* cur = new Node(in[mid]);
    cur->left = create(root - (end - mid) - 1, start, mid - 1);
    cur->right = create(root - 1, mid + 1, end);
    return cur;
}

Node* dfs(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;
    if (cur->val == val)
        return cur;
    Node* left = dfs(cur->left, val), *right = dfs(cur->right, val);
    return left ? left : right;
}

Node* dfsPar(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;
    if ((cur->left && cur->left->val == val) || (cur->right && cur->right->val == val))
        return cur;
    Node *left = dfsPar(cur->left, val), *right = dfsPar(cur->right, val);
    return left ? left : right;
}

int dfsDepth(Node* cur, int val, int depth){
    if (cur == nullptr)
        return 0;
    if (cur->val == val)
        return depth;
    int left = dfsDepth(cur->left, val, depth + 1), right = dfsDepth(cur->right, val, depth + 1);
    return left ? left : right;
}

bool judge(Node* cur){
    if (cur == nullptr)
        return true;
    if (!cur->left && !cur->right)
        return true;

    if (!cur->left || !cur->right)
        return false;
    return judge(cur->left) && judge(cur->right);
}

int main() {
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    Node* root = create(n - 1, 0, n - 1);

    int k;
    scanf("%d", &k);
    getchar();

    while (k--){
        string s;
        getline(cin, s);

        if (s.find("root") != string::npos){
            int val;
            sscanf(s.c_str(), "%d is the root", &val);
            if (dfs(root, val) == root)
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (s.find("siblings") != string::npos){
            int u, v;
            sscanf(s.c_str(), "%d and %d are siblings", &u, &v);
            if (dfsPar(root, u) == dfsPar(root, v))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (s.find("parent") != string::npos){
            int u, v;
            sscanf(s.c_str(), "%d is the parent of %d", &u, &v);
            if (dfsPar(root, v) == dfs(root, u))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (s.find("left") != string::npos){
            int u, v;
            sscanf(s.c_str(), "%d is the left child of %d", &u, &v);
            if (dfs(root, v)->left == dfs(root, u))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (s.find("right") != string::npos){
            int u, v;
            sscanf(s.c_str(), "%d is the right child of %d", &u, &v);
            if (dfs(root, v)->right == dfs(root, u))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (s.find("same") != string::npos){
            int u, v;
            sscanf(s.c_str(), "%d and %d are on the same level", &u, &v);
            if (dfsDepth(root, u, 1) == dfsDepth(root, v, 1))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (s.find("full") != string::npos){
            if (judge(root))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }
    }

    return 0;
}
