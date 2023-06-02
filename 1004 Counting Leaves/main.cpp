#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int root = 1;
int n, m;
vector<vector<int>> tree;
int table[110] = {0};


int bfs(){
    int level = 0;
    queue<int> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()){
        level++;
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();

            if (tree[cur].empty()){
                table[level]++;
                continue;
            }

            for (int j = 0; j < tree[cur].size(); ++j) {
                int v = tree[cur][j];
                myQueue.push(v);
            }
        }
    }

    return level;
}

int dfs(int cur, int depth){
    if (tree[cur].empty()){
        table[depth]++;
        return depth;
    }

    int maxDepth = 0;
    for (int i = 0; i < tree[cur].size(); ++i) {
        int v = tree[cur][i];
        maxDepth = max(maxDepth, dfs(v, depth + 1));
    }

    return maxDepth;
}


int main() {
    scanf("%d%d", &n, &m);
    tree.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int cur, k;
        scanf("%d%d", &cur, &k);
        tree[cur].resize(k);

        for (int j = 0; j < k; ++j) {
            scanf("%d", &tree[cur][j]);
        }
    }

    int level = dfs(root, 1);

    for (int i = 1; i <= level; ++i) {
        if (i != 1)
            printf(" ");
        printf("%d", table[i]);
    }

    return 0;
}
