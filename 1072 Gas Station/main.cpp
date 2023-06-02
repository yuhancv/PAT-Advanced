#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m, k, range;
const int MAXN = 1100;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int dis[MAXN];

int minDis = -INT_MAX, nowDis = 0;
double minAver = INT_MAX, nowAver = 0;

bool dijkstra(int start){
    fill(visited, visited + MAXN, false);
    fill(dis, dis + MAXN, INT_MAX);
    dis[start] = 0;
    int times = n + m;

    while (times--){
        int u = -1, min = INT_MAX;

        for (int i = 1; i <= n + m; ++i) {
            if (!visited[i] && dis[i] < min){
                min = dis[i];
                u = i;
            }
        }

        if (u == -1)
            return false;
        
        visited[u] = true;
        for (int v = 1; v <= n + m ; ++v) {
            if (visited[v] == false && graph[u][v] != 0){
                if (dis[v] > dis[u] + graph[u][v]){
                    dis[v] = dis[u] + graph[u][v];
                } 
            }
        }
    }

    nowDis = dis[1];
    nowAver = 0;
    int maxDis = dis[1];
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > maxDis)
            maxDis = dis[i];
        if (dis[i] < nowDis)
            nowDis = dis[i];
        nowAver += (double )dis[i];
    }

    if (maxDis > range)
        return false;

    nowAver /= n;
    return true;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &range);

    for (int i = 0; i < k; ++i) {
        string s1, s2;
        int len;
        int u, v;
        cin >> s1 >> s2;
        scanf("%d", &len);

        if (s1[0] == 'G'){
            s1.erase(s1.begin());
            u = n + stoi(s1);
        } else{
            u = stoi(s1);
        }

        if (s2[0] == 'G'){
            s2.erase(s2.begin());
            v = n + stoi(s2);
        } else{
            v = stoi(s2);
        }

        graph[u][v] = len;
        graph[v][u] = len;
    }

    int ans = -1;

    for (int i = n + 1; i <= n + m; ++i) {
        bool flag = dijkstra(i);

        if (!flag)
            continue;

        if (nowDis > minDis){
            minDis = nowDis;
            minAver = nowAver;
            ans = i - n;
        } else if (nowDis == minDis && nowAver < minAver){
            minAver = nowAver;
            ans = i - n;
        } else if (nowDis == minDis && nowAver == minAver)
            continue;

    }

    if (ans == -1){
        printf("No Solution");
    } else{
        string s = "G" + to_string(ans);
        printf("%s\n", s.c_str());
        printf("%.1f %.1f", (double )minDis, minAver + 0.01);
    }

    return 0;
}

