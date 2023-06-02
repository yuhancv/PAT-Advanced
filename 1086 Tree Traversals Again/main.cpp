#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> pre, in, post;
stack<int> s;

void dfs(int root, int start, int end){
    if (start > end)
        return;
    int mid = start;
    while (mid <= end && in[mid] != pre[root])
        mid++;

    dfs(root + 1, start, mid - 1);
    dfs(root + (mid - start) + 1, mid + 1, end);
    post.push_back(in[mid]);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < 2 * n; ++i) {
        string commend;
        int val;
        cin >> commend;

        if (commend == "Push"){
            scanf("%d", &val);
            s.push(val);
            pre.push_back(val);
        } else{
            in.push_back(s.top());
            s.pop();
        }
    }

    dfs(0, 0, n - 1);

    for (int i = 0; i < post.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", post[i]);
    }
    return 0;
}
