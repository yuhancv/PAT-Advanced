#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
const int MAXN = 1100;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int dis[MAXN];

void dijkstra(int start){
    fill(visited, visited + MAXN, false);
    fill(dis, dis + MAXN, INT_MAX);
    dis[start] = 0;
    int times = n;

    while (times--){
        int u = -1, min = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == false && dis[i] < min){
                min = dis[i];
                u = i;
            }
        }

        if (u == -1)
            return;

        visited[u] = true;

        for (int v = 1; v <= n; ++v) {
            if (visited[v] == false && graph[u][v] != 0){
                if (dis[v] > dis[u] + graph[u][v]){
                    dis[v] = dis[u] + graph[u][v];
                }
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] = len;
        graph[v][u] = len;
    }

    int k;
    scanf("%d", &k);

    while (k--){
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        dijkstra(a[0]);
        bool flag = true;

        for (int i = 0; i < a.size()- 1; ++i) {
            if (!(dis[a[i]] <= dis[a[i + 1]])){
                flag = false;
                break;
            }
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

/*
const int MAXN = 1100;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int dis[MAXN];
int n, m;

void dijkstra(int start){
    fill(visited, visited + MAXN, false);
    fill(dis, dis + MAXN, INT_MAX);
    dis[start] = 0;
    int times = n;

    while (times--){
        int u = -1, min = INT_MAX;

        for (int i = 1; i <= n; ++i) {
            if (visited[i] == false && dis[i] < min){
                min = dis[i];
                u = i;
            }
        }

        if (u == -1)
            return;

        visited[u] = true;
        for (int v = 1; v <= n; ++v) {
            if (visited[v] == false && graph[u][v] != 0){
                if (dis[v] > dis[u] + graph[u][v]){
                    dis[v] = dis[u] + graph[u][v];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] = len;
        graph[v][u] = len;
    }

    int k;
    scanf("%d", &k);

    while (k--){
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        dijkstra(a[0]);
        bool flag = true;
        for (int i = 0; i < a.size() - 1; ++i) {
            if (!(dis[a[i]] <= dis[a[i + 1]])){
                flag = false;
                break;
            }
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

 */