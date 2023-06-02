#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int root = 0;
int n;
double p, r;

vector<vector<int>> tree;
vector<int> ans;
double minPrice = INT_MAX;

double dfs(int cur, int depth){
    if (tree[cur].empty()){
        double price = p * pow(1 + r / 100, depth - 1);
        if (price < minPrice){
            minPrice = price;
            ans.clear();
            ans.push_back(cur);
        } else if (price == minPrice)
            ans.push_back(cur);
        return price;
    }

    double now = INT_MAX;
    for (int i = 0; i < tree[cur].size(); ++i) {
        int v = tree[cur][i];
        now = min(now, dfs(v, depth + 1));
    }

    return now;
}

void bfs(){
    int level = 0;
    queue<int> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()){
        level++;
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            int cur = myQueue.front();
            myQueue.pop();

            if (tree[cur].empty()) {
                double price = p * pow(1 + r / 100, level - 1);
                if (price < minPrice) {
                    minPrice = price;
                    ans.clear();
                    ans.push_back(cur);
                } else if (price == minPrice) {
                    ans.push_back(cur);
                }
                continue;
            }

            for (int j = 0; j < tree[cur].size(); ++j) {
                int v = tree[cur][j];
                myQueue.push(v);
            }
        }
    }
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        tree[i].resize(k);

        for (int j = 0; j < k; ++j) {
            scanf("%d", &tree[i][j]);
        }
    }

    bfs();
    printf("%.4f %d", minPrice, ans.size());
    return 0;
}
