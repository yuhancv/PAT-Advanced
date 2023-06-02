#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> pre, in, post;
bool flag = false;
void dfs(int root, int start, int end){
    if (start > end)
        return;

    if (flag)
        return;

    int mid = start;
    while (mid <= end && in[mid] != pre[root])
        mid++;

    dfs(root + 1, start, mid - 1);
    dfs(root + (mid - start) + 1, mid + 1, end);
    if (!flag){
        post.push_back(in[mid]);
        flag = true;
    }
}

int main() {
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    dfs(0, 0, n - 1);
    printf("%d", post.front());
    return 0;
}
