#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 510;
int graph[MAXN][MAXN] = {0}, cost[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int dis[MAXN];
int n, m, s, d;

vector<int> pre[MAXN];
void dijkstra(int start){
    fill(visited, visited + MAXN, false);
    fill(dis, dis + MAXN, INT_MAX);
    dis[start] = 0;
    int times = n;

    while (times--){
        int u = -1, min = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (visited[i] == false && dis[i] < min){
                min = dis[i];
                u = i;
            }
        }

        if (u == -1)
            return;

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
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

int minCost = INT_MAX;
vector<int> ans, temp;

void dfs(int u){
    if (u == s){
        temp.push_back(s);
        int nowCost = 0;

        for (int i = temp.size() - 1; i > 0 ; --i) {
            nowCost += cost[temp[i]][temp[i - 1]];
        }

        if (nowCost < minCost){
            ans = temp;
            minCost = nowCost;
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
    scanf("%d%d%d%d", &n, &m, &s, &d);

    for (int i = 0; i < m; ++i) {
        int u, v, len, t;
        scanf("%d%d%d%d", &u, &v, &len, &t);
        graph[u][v] = len;
        graph[v][u] = len;
        cost[u][v] = t;
        cost[v][u] = t;
    }

    dijkstra(s);
    dfs(d);

    for (int i = ans.size() - 1; i >= 0 ; --i) {
        if (i != ans.size() - 1)
            printf(" ");
        printf("%d", ans[i]);
    }

    printf(" %d %d", dis[d], minCost);

    return 0;
}
