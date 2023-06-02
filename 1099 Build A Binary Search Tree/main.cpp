#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int root = 0;
int n;
vector<int> v;
struct Node{
    int val;
    int left, right;
};

vector<Node> tree;

int now = 0;

void dfs(int cur){
    if (cur == -1)
        return;
    dfs(tree[cur].left);
    tree[cur].val = v[now++];
    dfs(tree[cur].right);
}

vector<int> ans;

void bfs(){
    queue<int> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            int cur = myQueue.front();
            myQueue.pop();
            ans.push_back(tree[cur].val);

            if (tree[cur].left != -1)
                myQueue.push(tree[cur].left);
            if (tree[cur].right != -1)
                myQueue.push(tree[cur].right);
        }
    }
}


int main() {
    scanf("%d", &n);
    v.resize(n);
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &tree[i].left, &tree[i].right);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());
    dfs(0);
    bfs();

    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}
