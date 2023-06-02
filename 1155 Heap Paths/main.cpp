#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> heap;

vector<vector<int>> ans;
vector<int> temp;

void dfs(int cur){
    if (cur > n || cur < 1)
        return;
    if (2 * cur > n){
        temp.push_back(heap[cur]);
        ans.push_back(temp);
        temp.pop_back();
        return;
    }

    temp.push_back(heap[cur]);
    dfs(2 * cur + 1);
    dfs(2 * cur);
    temp.pop_back();
}

int main() {
    scanf("%d", &n);
    heap.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &heap[i]);
    }

    dfs(1);

    int maxn = 1, minn = 1;

    for (int i = 2; i <= n; ++i) {
        if (heap[i / 2] < heap[i])
            maxn = 0;
        if (heap[i / 2] > heap[i])
            minn = 0;
    }

    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            if (j != 0)
                printf(" ");
            printf("%d", ans[i][j]);
        }

        printf("\n");
    }

    if (maxn == 1)
        printf("Max Heap\n");
    else if (minn == 1)
        printf("Min Heap\n");
    else
        printf("Not Heap\n");

    return 0;
}
