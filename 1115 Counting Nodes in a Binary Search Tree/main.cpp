#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

struct Node{
    int val;
    Node *left, *right;
    Node(int val, Node* left, Node* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

map<int, int> treemap;

Node* insert(Node* cur, int val){
    if (cur == nullptr){
        cur = new Node(val, nullptr, nullptr);
        return cur;
    }

    if (val <= cur->val)
        cur->left = insert(cur->left, val);
    else
        cur->right = insert(cur->right, val);
    return cur;
}

int dfs(Node* cur, int depth){
    if (cur == nullptr)
        return 0;
    else if (cur->left == nullptr && cur->right == nullptr){
        treemap[depth]++;
        return depth;
    }

    treemap[depth]++;
    int left = dfs(cur->left, depth + 1), right = dfs(cur->right, depth + 1);
    return max(left, right);
}

int bfs(Node* root){
    if (root == nullptr)
        return 0;

    int level = 0;
    queue<Node*> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()){
        level++;
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            treemap[level]++;

            if (cur->left)
                myQueue.push(cur->left);
            if (cur->right)
                myQueue.push(cur->right);
        }
    }

    return level;
}

int main() {
    scanf("%d", &n);

    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int lowest = bfs(root);

    printf("%d + %d = %d", treemap[lowest], treemap[lowest - 1], (treemap[lowest] + treemap[lowest - 1]));
    return 0;
}
