#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 510;
int n, m, s, d;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int dis[MAXN];
vector<int> weight;
int num[MAXN] = {0};

vector<int> pre[MAXN];

void dijkstra(int start){
    fill(visited, visited + MAXN, false);
    fill(dis, dis + MAXN, INT_MAX);
    fill(num, num + MAXN, 0);
    dis[start] = 0;
    num[start] = 1;
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
            if (!visited[v] && graph[u][v] != 0){
                if (dis[v] > dis[u] + graph[u][v]){
                    dis[v] = dis[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                    num[v] = num[u];
                } else if (dis[v] == dis[u] + graph[u][v]){
                    pre[v].push_back(u);
                    num[v] += num[u];
                }
            }
        }
    }
}

vector<int> ans, temp;
int maxNum = -INT_MAX;

void dfs(int u){
    if (u == s){
        temp.push_back(u);
        int nowNum = 0;

        for (int i = 0; i < temp.size(); ++i) {
            nowNum += weight[temp[i]];
        }

        if (nowNum > maxNum){
            ans = temp;
            maxNum = nowNum;
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
    weight.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &weight[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] = len;
        graph[v][u] = len;
    }

    dijkstra(s);
    dfs(d);

    printf("%d %d", num[d], maxNum);

    return 0;
}
