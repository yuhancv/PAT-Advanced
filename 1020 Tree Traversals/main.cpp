#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> in, post;

struct Node{
    int val;
    Node *left, *right;
};

Node* dfs(int root, int start, int end){
    if (start > end)
        return nullptr;

    int mid = start;
    while (mid <= end && in[mid] != post[root])
        mid++;

    Node* cur = new Node();
    cur->val = in[mid];
    cur->left = dfs(root - (end - mid) - 1, start, mid - 1);
    cur->right = dfs(root - 1, mid + 1, end);
    return cur;
}

Node* root = nullptr;
vector<int> level;
void bfs(Node* root){
    if (root == nullptr)
        return;

    queue<Node*> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            level.push_back(cur->val);

            if (cur->left)
                myQueue.push(cur->left);
            if (cur->right)
                myQueue.push(cur->right);
        }
    }
}

int main(){
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    root = dfs(n - 1, 0, n - 1);
    bfs(root);

    for (int i = 0; i < level.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", level[i]);
    }

    return 0;
}



/*

int n;
vector<int> in, post;

map<int, int> treemap;

void dfs(int root, int start, int end, int index){
    if (start > end)
        return;
    int mid = start;
    while (mid <= end && in[mid] != post[root])
        mid++;

    treemap[index] = in[mid];
    dfs(root - (end - mid) - 1, start, mid - 1, 2 * index);
    dfs(root - 1, mid + 1, end, 2 * index + 1);
}

int main() {
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    dfs(n - 1, 0, n - 1, 1);

    for (auto it = treemap.begin(); it != treemap.end(); it++) {
        if (it != treemap.begin())
            printf(" ");
        printf("%d", it->second);
    }

    return 0;
}

 
 */