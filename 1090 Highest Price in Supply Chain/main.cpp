#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int root;
int n;
double p, r;

vector<vector<int>> tree;
vector<int> ans;
double maxPrice = -INT_MAX;

double dfs(int cur, int depth){
    if (tree[cur].empty()){
        double price = p * pow(1 + r / 100, depth - 1);
        if (price > maxPrice){
            ans.clear();
            ans.push_back(cur);
            maxPrice = price;
        } else if (price == maxPrice)
            ans.push_back(cur);

        return p * pow(1 + r / 100, depth - 1);
    }

    double now = 0;
    for (int i = 0; i < tree[cur].size(); ++i) {
        int v = tree[cur][i];
        now = max(now, dfs(v, depth + 1));
    }

    return now;
}

void bfs(int root){
    queue<int> myQueue;
    myQueue.push(root);
    int level = 0;

    while (!myQueue.empty()){
        level++;
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            int cur = myQueue.front();
            myQueue.pop();

            if (tree[cur].empty()){
                double price = p * pow(1 + r / 100, level - 1);
                if (price > maxPrice){
                    maxPrice = price;
                    ans.clear();
                    ans.push_back(cur);
                } else if (price == maxPrice)
                    ans.push_back(cur);
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
        int val;
        scanf("%d", &val);

        if (val == -1)
            root = i;
        else{
            tree[val].push_back(i);
        }
    }

    bfs(root);

    printf("%.2f %d", maxPrice, ans.size());

    return 0;
}
