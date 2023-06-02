#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 10000;
int s, d;
int n;
vector<vector<int>> graph(MAXN);
unordered_map<int, int> line;
vector<int> ans, temp;
bool visited[MAXN] = {false};
int minCnt = INT_MAX, minTran = INT_MAX;

int getTran(vector<int> &temp){
    int cnt = 0;
    int pre = line[temp[0] + MAXN + temp[1]];

    for (int i = 1; i < temp.size() - 1 ; ++i) {
        int now = line[temp[i] * MAXN + temp[i + 1]];
        if (now != pre)
            cnt++;
        pre = now;
    }

    return cnt;
}

void dfs(int cur){
    if (cur == d){
        temp.push_back(cur);
        visited[cur] = true;
        int nowCnt = temp.size() - 1, nowTran = getTran(temp);
        if (nowCnt < minCnt || (nowCnt == minCnt && nowTran < minTran)){
            minCnt = nowCnt;
            minTran = nowTran;
            ans = temp;
        }

        temp.pop_back();
        visited[cur] = false;
        return;
    }

    temp.push_back(cur);
    visited[cur] = true;

    for (int i = 0; i < graph[cur].size(); ++i) {
        int v = graph[cur][i];
        if (visited[v] == false)
            dfs(v);
    }

    temp.pop_back();
    visited[cur] = false;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);

        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[j]);
        }

        for (int j = 0; j < m - 1; ++j) {
            int u = a[j], v = a[j + 1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            line[u * MAXN + v] = line[v * MAXN + u] = i;
        }
    }

    int k;
    scanf("%d", &k);

    while (k--){
        scanf("%d%d", &s, &d);
        fill(visited, visited + MAXN, false);
        ans.clear(), temp.clear();
        minCnt = INT_MAX, minTran = INT_MAX;
        dfs(s);

        printf("%d\n", minCnt);

        int cur = s, pre = 0;
        for (int i = 1; i < ans.size(); ++i) {
            int now = line[ans[i - 1] * MAXN + ans[i]];
            if (now != pre){
                if (pre != 0)
                    printf("Take Line#%d from %04d to %04d.\n", pre, cur, ans[i - 1]);

                pre = now;
                cur = ans[i - 1];
            }
        }

        printf("Take Line#%d from %04d to %04d.\n", pre, cur, d);

    }

    return 0;
}
