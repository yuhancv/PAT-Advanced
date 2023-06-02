#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int k;

struct Node{
    int val;
    Node *left, *right;
    Node(int val, Node *left, Node *right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

bool cmp(int a, int b){
    return abs(a) <= abs(b);
}

vector<int> pre, in;

Node* insert(Node* cur, int val){
    if (cur == nullptr){
        cur = new Node(val, nullptr, nullptr);
        return cur;
    }

    if (abs(val) < abs(cur->val))
        cur->left = insert(cur->left, val);
    else
        cur->right = insert(cur->right, val);
    return cur;
}

bool dfsRed(Node* cur){
    if (cur == nullptr)
        return true;
    if (cur->val < 0){
        if ((cur->left && cur->left->val < 0) || (cur->right && cur->right->val < 0))
            return false;
    }

    return dfsRed(cur->left) && dfsRed(cur->right);
}

int getNum(Node* cur){
    if (cur == nullptr)
        return 0;
    int sum = (cur->val > 0) ? 1 : 0;
    return sum + max(getNum(cur->left), getNum(cur->right));
}

bool dfsEqual(Node* cur){
    if (cur == nullptr)
        return true;
    if (getNum(cur->left) != getNum(cur->right))
        return false;
    return dfsEqual(cur->left) && dfsEqual(cur->right);
}

Node* create(int root, int start, int end){
    if (start > end)
        return nullptr;
    int mid = start;
    while (mid <= end && in[mid] != pre[root])
        mid++;

    Node* cur = new Node(in[mid], nullptr, nullptr);
    cur->left = create(root + 1, start, mid - 1);
    cur->right = create(root + (mid - start) + 1, mid + 1, end);
    return cur;
}

int main(){
    scanf("%d", &k);

    while (k--){
        pre.clear();
        in.clear();
        int n;
        scanf("%d", &n);
        Node* root = nullptr;
        pre.resize(n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &pre[i]);
        }

        in = pre;
        sort(in.begin(), in.end(), cmp);
        root = create(0, 0, n - 1);

        if (root->val > 0 && dfsRed(root) && dfsEqual(root))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}



/*
int k;

struct Node{
    int val;
    Node *left, *right;
    Node(int val, Node* left, Node* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

Node* insert(Node* cur, int val){
    if (cur == nullptr){
        cur = new Node(val, nullptr, nullptr);
        return cur;
    }

    if (abs(val) < abs(cur->val))
        cur->left = insert(cur->left, val);
    else
        cur->right = insert(cur->right, val);
    return cur;
}

bool dfsRed(Node* cur){
    if (cur == nullptr)
        return true;
    if (cur->val < 0){
        if ((cur->left != nullptr && cur->left->val < 0) || (cur->right != nullptr && cur->right->val < 0))
            return false;
    }

    return dfsRed(cur->left) && dfsRed(cur->right);
}

int getNum(Node* cur){
    if (cur == nullptr)
        return 0;

    int sum = (cur->val > 0) ? 1 : 0;
    int left = getNum(cur->left), right = getNum(cur->right);
    return sum + max(left, right);
}

bool dfsEqual(Node* cur){
    if (cur == nullptr)
        return true;
    if (getNum(cur->left) != getNum(cur->right))
        return false;
    return dfsEqual(cur->left) && dfsEqual(cur->right);
}

int main() {
    scanf("%d", &k);

    while (k--){
        int n;
        scanf("%d", &n);

        Node* root = nullptr;

        for (int i = 0; i < n; ++i) {
            int val;
            scanf("%d", &val);
            root = insert(root, val);
        }

        if (root->val > 0 && dfsRed(root) && dfsEqual(root))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
*/
