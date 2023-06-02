#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 10000;
int n;
int s, d;
vector<int> graph[MAXN];
unordered_map<int, int> line;
bool visited[MAXN] = {false};
vector<int> ans, temp;
int minCnt = INT_MAX, minMove = INT_MAX;

int getMove(vector<int> &a){
    int cnt = 0;
    int pre = line[a[0] * MAXN + a[1]];

    for (int i = 1; i < a.size() - 1; ++i) {
        int now = line[a[i] * MAXN + a[i + 1]];
        if (now != pre)
            cnt++;
        pre = now;
    }
    return cnt;
}

void dfs(int u){
    if (u == d){
        visited[u] = true;
        temp.push_back(u);
        int nowCnt = temp.size() - 1, nowMove = getMove(temp);
        if (nowCnt < minCnt || (nowCnt == minCnt && (nowMove < minMove))){
            minCnt = nowCnt;
            minMove = nowMove;
            ans = temp;
        }

        visited[u] = false;
        temp.pop_back();
        return;
    }

    visited[u] = true;
    temp.push_back(u);

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (!visited[v]){
            dfs(v);
        }
    }

    visited[u] = false;
    temp.pop_back();
    return;
}

int main(){
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
        ans.clear(); temp.clear();
        minCnt = INT_MAX, minMove = INT_MAX;
        dfs(s);
        printf("%d\n", minCnt);

        int start = 0, end = 1;
        int pre = line[ans[0] * MAXN + ans[1]];

        for (int i = 1; i < ans.size() - 1; ++i) {
            int now = line[ans[i] * MAXN + ans[i + 1]];

            if (now != pre){
                printf("Take Line#%d from %04d to %04d.\n", pre, ans[start], ans[end]);
                start = i, end = i + 1;
                pre = now;
            } else{
                end = i + 1;
            }
        }

        printf("Take Line#%d from %04d to %04d.\n", pre, ans[start], ans[end]);
    }

    return 0;
}


/*
const int MAXN = 10000;
int n;
int s, d;
vector<vector<int>> graph(MAXN);
unordered_map<int, int> line;
bool visited[MAXN] = {false};
vector<int> ans, temp;
int minCnt = INT_MAX, minMove = INT_MAX;

int getMove(vector<int> &a){
    int cnt = 0;
    int pre = line[a[0] * MAXN + a[1]];

    for (int i = 1; i < a.size() - 1; ++i) {
        int now = line[a[i] * MAXN + a[i + 1]];
        if (now != pre)
            cnt++;
        pre = now;
    }
    return cnt;
}

void dfs(int u){
    if (u == d){
        visited[u] = true;
        temp.push_back(u);
        int nowCnt = temp.size() - 1, nowMove = getMove(temp);
        if (nowCnt < minCnt || (nowCnt == minCnt && nowMove < minMove)){
            minCnt = nowCnt;
            minMove = nowMove;
            ans = temp;
        }

        visited[u] = false;
        temp.pop_back();
        return;
    }

    visited[u] = true;
    temp.push_back(u);

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (!visited[v])
            dfs(v);
    }

    visited[u] = false;
    temp.pop_back();
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n ; ++i) {
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
        ans.clear(); temp.clear();
        minCnt = INT_MAX, minMove = INT_MAX;
        dfs(s);
        printf("%d\n", minCnt);

        int start = 0, end = 1;
        int pre = line[ans[start] * MAXN + ans[end]];

        for (int i = 1; i < ans.size() - 1; ++i) {
            int now = line[ans[i] * MAXN + ans[i +  1]];
            if (now != pre){
                printf("Take Line#%d from %04d to %04d.\n", pre, ans[start], ans[end]);
                start = i, end = i + 1;
                pre = now;
            } else{
                end = i + 1;
            }
        }

        printf("Take Line#%d from %04d to %04d.\n", pre, ans[start], d);
    }

    return 0;
}

 */
