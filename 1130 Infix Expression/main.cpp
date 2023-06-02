#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n;
struct Node{
    string val;
    int left, right;
};

vector<Node> tree;
int visited[27] = {0};

string dfs(int cur){
    if (cur == -1)
        return "";
    else if (tree[cur].left == -1 && tree[cur].right == -1)
        return tree[cur].val;

    return "(" + dfs(tree[cur].left) + tree[cur].val + dfs(tree[cur].right) + ")";
}

int main() {
    scanf("%d", &n);
    tree.resize(n + 1);

    for (int i = 1; i <= n ; ++i) {
        cin >> tree[i].val;
        scanf("%d%d", &tree[i].left, &tree[i].right);
        if (tree[i].left != -1)
            visited[tree[i].left] = 1;
        if (tree[i].right != -1)
            visited[tree[i].right] = 1;
    }

    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0){
            root = i;
            break;
        }
    }

    string ans = dfs(root);

    if (ans[0] == '('){
        ans = ans.substr(1, ans.size() - 2);
    }

    cout << ans;

    return 0;
}
