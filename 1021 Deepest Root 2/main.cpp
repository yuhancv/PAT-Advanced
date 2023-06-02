#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
const int MAXN = 10010;
vector<int> graph[MAXN];
bool visited[MAXN] = {false};
set<int> s;
vector<int> ans;

int maxDepth = -INT_MAX;

void dfs(int u, int depth){
    visited[u] = true;

    if (depth > maxDepth){
        ans.clear();
        ans.push_back(u);
        maxDepth = depth;
    } else if (depth == maxDepth)
        ans.push_back(u);

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            dfs(v, depth + 1);
    }
}

int main(){
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;

    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            dfs(u, 1);
            cnt++;
        }
    }

    if (cnt > 1){
        printf("Error: %d components\n", cnt);
        return 0;
    }

    for (int i = 0; i < ans.size(); ++i) {
        s.insert(ans[i]);
    }

    int start = ans[0];
    ans.clear();
    maxDepth = -INT_MAX;
    fill(visited, visited + MAXN, false);
    dfs(start, 1);

    for (int i = 0; i < ans.size(); ++i) {
        s.insert(ans[i]);
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        printf("%d\n", *it);
    }

    return 0;
}





/*
const int MAXN = 10010;
vector<int> graph[MAXN];
bool visited[MAXN] = {false};
int n;

void travel(int u){
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            travel(v);
    }
}

int travelCnt(){
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            travel(u);
            cnt++;
        }
    }

    return cnt;
}

int dfs(int u, int depth){
    visited[u] = true;
    int maxDepth = depth;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false){
            maxDepth = max(maxDepth, dfs(v, depth + 1));
        }
    }

    return maxDepth;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = travelCnt();

    if (cnt > 1){
        printf("Error: %d components", cnt);
        return 0;
    }

    int maxDepth = -INT_MAX;
    vector<int> ans;

    for (int u = 1; u <= n; ++u) {
        fill(visited, visited + MAXN, false);
        int depth = dfs(u, 1);

        if (depth > maxDepth){
            ans.clear();
            ans.push_back(u);
            maxDepth = depth;
        } else if (depth == maxDepth)
            ans.push_back(u);
    }

    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

 */