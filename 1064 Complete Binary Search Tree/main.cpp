#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> v;
vector<int> cbt;

int now = 0;

void dfs(int cur){
    if (cur > n - 1 || cur < 0)
        return;
    dfs(2 * cur + 1);
    cbt[cur] = v[now++];
    dfs(2 * cur + 2);
}

vector<int> ans;

void bfs(int root){
    if (root == -1)
        return;
    queue<int> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            int cur = myQueue.front();
            myQueue.pop();
            ans.push_back(cbt[cur]);

            if (2 * cur + 1 <= n - 1)
                myQueue.push(2 * cur + 1);
            if (2 * cur + 2 <= n - 1)
                myQueue.push(2 * cur + 2);
        }
    }
}


int main() {
    scanf("%d", &n);
    v.resize(n);
    cbt.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end());


    dfs(0);

    /*
    for (int i = 0; i < n; ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", cbt[i]);
    }

     */

    bfs(0);

    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
