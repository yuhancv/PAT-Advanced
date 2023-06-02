#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> post, in;

struct Node{
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
    }
};

Node* dfs(int root, int start, int end){
    if (start > end)
        return nullptr;
    int mid = start;
    while (mid <= end && in[mid] != post[root])
        mid++;

    Node* cur = new Node(in[mid]);
    cur->left = dfs(root - (end - mid) - 1, start, mid - 1);
    cur->right = dfs(root - 1, mid + 1, end);
    return cur;
}

vector<int> ans;

void bfs(Node* root){
    if (root == nullptr)
        return;

    queue<Node*> myQueue;
    myQueue.push(root);
    int level = 0;

    while (!myQueue.empty()){
        level++;
        int width = myQueue.size();
        vector<int> temp;

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            temp.push_back(cur->val) ;

            if (cur->left)
                myQueue.push(cur->left);
            if (cur->right)
                myQueue.push(cur->right);
        }

        if (level % 2 == 1)
            reverse(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); ++i) {
            ans.push_back(temp[i]);
        }
    }
}

int main() {
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }

    Node* root = dfs(n - 1, 0, n - 1);
    bfs(root);

    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}
