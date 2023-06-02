#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int s = 0, MAXN = 510;
int capacity, n, d, m;
int graph[MAXN][MAXN] = {0};
int dis[MAXN];
bool visited[MAXN] = {false};
int weight[MAXN] = {0};

vector<int> pre[MAXN];
void dijkstra(int start){
    fill(visited, visited + MAXN, false);
    fill(dis, dis + MAXN, INT_MAX);
    dis[start] = 0;
    int times = 1 + n;

    while (times--){
        int u = -1, min = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            if (visited[i] == false && dis[i] < min){
                min = dis[i];
                u = i;
            }
        }

        if (u == -1)
            return;

        visited[u] = true;

        for (int v = 0; v <= n ; ++v) {
            if (visited[v] == false && graph[u][v] != 0){
                if (dis[v] > dis[u] + graph[u][v]){
                    dis[v] = dis[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + graph[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<int> ans, temp;
int minSent = INT_MAX, minBack = INT_MAX;

void dfs(int u){
    if (u == s){
        temp.push_back(s);
        int nowSent = 0, nowBack = 0;

        for (int i = temp.size() - 1; i >= 0 ; --i) {
            int cur = temp[i];
            if (weight[cur] >= 0)
                nowBack += weight[cur];
            else{
                if (nowBack >= abs(weight[cur]))
                    nowBack -= abs(weight[cur]);
                else{
                    nowSent += abs(weight[cur]) - nowBack;
                    nowBack = 0;
                }
            }
        }

        if (nowSent < minSent){
            minSent = nowSent;
            minBack = nowBack;
            ans = temp;
        } else if (nowSent == minSent && nowBack < minBack){
            minBack = nowBack;
            ans = temp;
        }

        temp.pop_back();
        return;
    }

    temp.push_back(u);
    for (int i = 0; i < pre[u].size(); ++i) {
        dfs(pre[u][i]);
    }
    temp.pop_back();
}

int main() {
    scanf("%d%d%d%d", &capacity, &n, &d, &m);

    for (int i = 1; i <= n ; ++i) {
        int val;
        scanf("%d", &val);
        weight[i] = val - (capacity / 2);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] = len;
        graph[v][u] = len;
    }

    dijkstra(s);
    dfs(d);

    printf("%d ", minSent);

    for (int i = ans.size() - 1; i >= 0 ; --i) {
        if (i != ans.size() - 1)
            printf("->");
        printf("%d", ans[i]);
    }

    printf(" %d", minBack);
    return 0;
}
