#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

struct Node{
    string val;
    int left, right;
};

vector<Node> tree;
int visited[22] = {0};

string dfs(int cur){
    if (cur == -1)
        return "";
    if (tree[cur].left == -1 && tree[cur].right == -1)
        return "(" + tree[cur].val + ")";
    if (tree[cur].left == -1 && tree[cur].right != -1)
        return "(" + tree[cur].val + dfs(tree[cur].right) + ")";

    return "(" + dfs(tree[cur].left) + dfs(tree[cur].right) + tree[cur].val + ")";
}

int main() {
    scanf("%d", &n);
    tree.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> tree[i].val;
        scanf("%d%d", &tree[i].left, &tree[i].right);

        if (tree[i].left != -1){
            visited[tree[i].left] = 1;
        }

        if (tree[i].right != -1){
            visited[tree[i].right] = 1;
        }
    }

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0){
            root = i;
            break;
        }
    }

    string ans = dfs(root);
    printf("%s", ans.c_str());

    return 0;
}
