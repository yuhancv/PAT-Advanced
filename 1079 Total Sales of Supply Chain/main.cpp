#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int root = 0;
int n;
double p, r;

struct Node{
    int num;
    vector<int> child;
};

vector<Node> tree;

double dfs(int cur, int depth){
    if (tree[cur].child.empty()){
        return tree[cur].num * p * pow(1 + r / 100, depth - 1);
    }

    double sum = 0;
    for (int i = 0; i < tree[cur].child.size(); ++i) {
        int v = tree[cur].child[i];
        sum += dfs(v, depth + 1);
    }

    return sum;
}

double bfs(){
    queue<int> myQueue;
    myQueue.push(root);
    int level = 0;
    double sum = 0;

    while (!myQueue.empty()){
        int width = myQueue.size();
        level++;

        for (int i = 0; i < width; ++i) {
            int cur = myQueue.front();
            myQueue.pop();

            if (tree[cur].child.empty()){
                sum += tree[cur].num * p * pow(1 + r / 100, level - 1);
                continue;
            }

            for (int j = 0; j < tree[cur].child.size(); ++j) {
                int v = tree[cur].child[j];
                myQueue.push(v);
            }

        }
    }

    return sum;
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);

    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);

        if (k != 0) {
            tree[i].child.resize(k);
            for (int j = 0; j < k; ++j) {
                scanf("%d", &tree[i].child[j]);
            }
        }else{
            scanf("%d", &tree[i].num);
        }
    }

    double ans = dfs(root, 1);

    printf("%.1f", ans);
    return 0;
}
