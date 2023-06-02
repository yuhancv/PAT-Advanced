#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> pre, in, post;

bool flag = true;

void dfs(int preL, int preR, int postL, int postR){
    if (preL > preR)
        return;
    if (preL == preR){
        in.push_back(pre[preL]);
        return;
    }

    int i = preL + 1;
    while (i <= preR && pre[i] != post[postR - 1])
        i++;

    if (i > preL + 1){
        dfs(preL + 1, i - 1, postL, postL + (i - preL - 2));
    } else{
        flag = false;
    }
    in.push_back(pre[preL]);
    dfs(i, preR, postL + (i - preL - 1), postR - 1);
}

int main() {
    scanf("%d", &n);
    pre.resize(n);
    post.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }

    dfs(0, n - 1, 0, n - 1);

    if (flag)
        printf("Yes\n");
    else
        printf("No\n");

    for (int i = 0; i < in.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", in[i]);
    }

    printf("\n");
    return 0;
}
