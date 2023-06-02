#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> v;
map<int, int> tree;

void dfs(int start, int end, int index){
    if (start > end)
        return;
    int min = v[start];
    int mid = start;

    for (int i = start; i <= end ; ++i) {
        if (v[i] < min){
            min = v[i];
            mid = i;
        }
    }

    tree[index] = v[mid];
    dfs(start, mid - 1, 2 * index + 1);
    dfs(mid + 1, end, 2 * index + 2);
}

int main(){
    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    dfs(0, v.size() - 1, 0);

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it != tree.begin())
            printf(" ");
        printf("%d", it->second);
    }

    return 0;
}




/*
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

Node* dfs(int start, int end){
    if (start > end)
        return nullptr;

    int min = v[start];
    int cur = start;
    for (int i = start; i <= end; ++i) {
        if (v[i] < min){
            min = v[i];
            cur = i;
        }
    }

    Node* u = new Node(v[cur], dfs(start, cur - 1), dfs(cur + 1, end));
    return u;
}

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
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    Node* root = dfs(0, v.size() - 1);
    bfs(root);

    for (int i = 0; i < level.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", level[i]);
    }

    return 0;
}
 */

/*
int n;
vector<int> v;
map<int, int> tree;

void dfs(int start, int end, int index){
    if (start > end)
        return;

    int min = v[start];
    int cur = start;
    for (int i = start; i <= end ; ++i) {
        if (v[i] < min){
            min = v[i];
            cur = i;
        }
    }

    tree[index] = v[cur];
    dfs(start, cur - 1, 2 * index + 1);
    dfs(cur + 1, end, 2 * index + 2);
}

int main() {
    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    dfs(0, v.size() - 1, 0);

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it != tree.begin())
            printf(" ");
        printf("%d", it->second);
    }

    return 0;
}

 */
