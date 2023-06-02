#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 510;
int graph[MAXN][MAXN] = {0}, cost[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int n, m, s, d;
int dis[MAXN], hour[MAXN];

vector<int> pre1[MAXN];

void dijkstra1(int start){
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
                    pre1[v].clear();
                    pre1[v].push_back(u);
                } else if (dis[v] == dis[u] + graph[u][v])
                    pre1[v].push_back(u);
            }
        }
    }
}

vector<int> ans1, temp1;
int minTime = INT_MAX;

void dfs1(int u){
    if (u == s){
        temp1.push_back(s);
        int nowTime = 0;

        for (int i = temp1.size() - 1; i > 0 ; --i) {
            nowTime += cost[temp1[i]][temp1[i - 1]];
        }

        if (nowTime < minTime){
            minTime = nowTime;
            ans1 = temp1;
        }

        temp1.pop_back();
        return;
    }

    temp1.push_back(u);
    for (int i = 0; i < pre1[u].size(); ++i) {
        dfs1(pre1[u][i]);
    }
    temp1.pop_back();
}

vector<int> pre2[MAXN];
void dijkstra2(int start){
    fill(visited, visited + MAXN, false);
    fill(hour, hour + MAXN, INT_MAX);
    hour[start] = 0;
    int times = n;

    while (times--){
        int u = -1, min = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (visited[i] == false && hour[i] < min){
                min = hour[i];
                u = i;
            }
        }

        if (u == -1)
            return;

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (visited[v] == false && cost[u][v] != 0){
                if (hour[v] > hour[u] + cost[u][v]){
                    hour[v] = hour[u] + cost[u][v];
                    pre2[v].clear();
                    pre2[v].push_back(u);
                } else if (hour[v] == hour[u] + cost[u][v]){
                    pre2[v].push_back(u);
                }
            }
        }
    }
}

int minInter = INT_MAX;
vector<int> ans2, temp2;

void dfs2(int u){
    if (u == s){
        temp2.push_back(s);
        int nowInter = temp2.size();
        if (nowInter < minInter){
            minInter = nowInter;
            ans2 = temp2;
        }

        temp2.pop_back();
        return;
    }

    temp2.push_back(u);
    for (int i = 0; i < pre2[u].size(); ++i) {
        dfs2(pre2[u][i]);
    }
    temp2.pop_back();
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, one, len, t;
        scanf("%d%d%d%d%d", &u, &v, &one, &len, &t);

        if (one == 1){
            graph[u][v] = len;
            cost[u][v] = t;
        } else{
            graph[u][v] = len;
            graph[v][u] = len;
            cost[u][v] = t;
            cost[v][u] = t;
        }
    }

    scanf("%d%d", &s, &d);

    dijkstra1(s);
    dijkstra2(s);
    dfs1(d);
    dfs2(d);

    if (ans1 == ans2){
        printf("Distance = %d; Time = %d: ", dis[d], hour[d]);
        for (int i = ans1.size() - 1; i >= 0 ; --i) {
            if (i != ans1.size() - 1)
                printf(" -> ");
            printf("%d", ans1[i]);
        }

    } else{
        printf("Distance = %d: ", dis[d]);
        for (int i = ans1.size() - 1; i >= 0 ; --i) {
            if (i != ans1.size() - 1)
                printf(" -> ");
            printf("%d", ans1[i]);
        }

        printf("\n");

        printf("Time = %d: ", hour[d]);
        for (int i = ans2.size() - 1; i >= 0 ; --i) {
            if (i != ans2.size() - 1)
                printf(" -> ");
            printf("%d", ans2[i]);
        }
    }

    return 0;
}
