#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int root = 1;
int n, m;
vector<vector<int>> tree;

map<int, int> treemap;

void bfs(){
    queue<int> myQueue;
    myQueue.push(root);
    int level = 0;

    while (!myQueue.empty()){
        level++;
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            int cur = myQueue.front();
            myQueue.pop();
            treemap[level]++;

            for (int j = 0; j < tree[cur].size(); ++j) {
                int v = tree[cur][j];
                myQueue.push(v);
            }
        }
    }
}

void dfs(int cur, int depth){
    if (tree[cur].empty()){
        treemap[depth]++;
        return;
    }

    treemap[depth]++;
    for (int i = 0; i < tree[cur].size(); ++i) {
        int v = tree[cur][i];
        dfs(v, depth + 1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    tree.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int id, k;
        scanf("%d%d", &id, &k);
        tree[id].resize(k);

        for (int j = 0; j < k; ++j) {
            scanf("%d", &tree[id][j]);
        }
    }

    dfs(root, 1);
    int maxNum = 0, ans = 0;

    for (auto it = treemap.begin(); it != treemap.end(); it++) {
        if (it->second > maxNum){
            maxNum = it->second;
            ans = it->first;
        }
    }

    printf("%d %d", maxNum, ans);

    return 0;
}
