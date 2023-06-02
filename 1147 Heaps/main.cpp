#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int m, n;
vector<int> heap;
vector<int> post;
void dfs(int cur){
    if (cur < 1 || cur > n)
        return;
    if (cur * 2 > n){
        post.push_back(heap[cur]);
        return;
    }

    dfs(2 * cur);
    dfs(2 * cur + 1);
    post.push_back(heap[cur]);
}

int main() {
    scanf("%d%d", &m, &n);

    while (m--){
        post.clear();
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

        if (maxn == 1)
            printf("Max Heap\n");
        else if (minn == 1)
            printf("Min Heap\n");
        else
            printf("Not Heap\n");

        for (int i = 0; i < post.size(); ++i) {
            if (i != 0)
                printf(" ");
            printf("%d", post[i]);
        }

        printf("\n");
    }
    return 0;
}
