#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

struct Node{
    string val;
    int left, right;
};

vector<Node> tree;
int visited[25] = {0};

void dfs(int cur){
    if (cur == -1)
        return;
    if (tree[cur].left == -1 && tree[cur].right == -1){
        printf("(%s)", tree[cur].val.c_str());
        return;
    }

    if (tree[cur].left == -1 && tree[cur].right != -1){
        printf("(");;
        printf("%s", tree[cur].val.c_str());
        dfs(tree[cur].right);
        printf(")");
        return;
    }

    printf("(");
    dfs(tree[cur].left);
    dfs(tree[cur].right);
    printf("%s", tree[cur].val.c_str());
    printf(")");
}

int main(){
    scanf("%d", &n);
    tree.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
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

    dfs(root);
    return 0;
}

/*
int n;

struct Node{
    string val;
    int left, right;
};

vector<Node> tree;
vector<int> visited;

void dfs(int cur){
    if (cur == -1)
        return;
    if (tree[cur].left == -1 && tree[cur].right == -1){
        printf("(%s)", tree[cur].val.c_str());
        return;
    }

    if (tree[cur].left == -1 && tree[cur].right != -1){
        printf("(");
        printf("%s", tree[cur].val.c_str());
        dfs(tree[cur].right);
        printf(")");
        return;
    }

    printf("(");
    dfs(tree[cur].left);
    dfs(tree[cur].right);
    printf("%s", tree[cur].val.c_str());
    printf(")");
}

int main() {
    scanf("%d", &n);
    tree.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
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

    dfs(root);
    return 0;
}

 */