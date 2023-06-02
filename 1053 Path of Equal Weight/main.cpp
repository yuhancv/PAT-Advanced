#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int root = 0;
int n, m, s;
int weight[105] ={0};
vector<vector<int>> tree;
vector<vector<int>> ans;
vector<int> temp;

bool cmp(vector<int> a, vector<int> b){
    return a > b;
}

void dfs(int cur){
    if (tree[cur].empty()){
        temp.push_back(weight[cur]);
        int sum = 0;
        for (int i = 0; i < temp.size(); ++i) {
            sum += temp[i];
        }

        if (sum == s)
            ans.push_back(temp);

        temp.pop_back();
        return;
    }

    temp.push_back(weight[cur]);
    for (int i = 0; i < tree[cur].size(); ++i) {
        int v = tree[cur][i];
        dfs(v);
    }
    temp.pop_back();
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &weight[i]);
    }

    for (int i = 0; i < m; ++i) {
        int id, k;
        scanf("%d%d", &id, &k);
        tree[id].resize(k);

        for (int j = 0; j < k; ++j) {
            scanf("%d", &tree[id][j]);
        }
    }

    dfs(root);
    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            if (j != 0)
                printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
