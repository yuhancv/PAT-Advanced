#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 210;
int n, m;
int s, d;
string startcity;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int weight[MAXN] = {0};
int dis[MAXN];
int num[MAXN];
map<string, int> toInt;
map<int, string> toStr;

vector<int> pre[MAXN];

void dijkstra(int start){
    fill(visited, visited + MAXN, false);
    fill(dis, dis + MAXN, INT_MAX);
    fill(num, num + MAXN, 0);
    int times = n;
    dis[start] = 0;
    num[start] = 1;

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
int maxHappy = -INT_MAX;
double maxAver = -INT_MAX;

void dfs(int u){
    if (u == s){
        temp.push_back(s);
        int nowHappy = 0;
        double nowAver = 0;

        for (int i = 0; i < temp.size(); ++i) {
            nowHappy += weight[temp[i]];
        }

        nowAver = (double ) nowHappy / (temp.size() - 1);

        if (nowHappy > maxHappy){
            maxHappy = nowHappy;
            maxAver = nowAver;
            ans = temp;
        } else if (nowHappy == maxHappy && nowAver > maxAver){
            maxAver = nowAver;
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
    scanf("%d%d", &n, &m);
    cin >> startcity;

    for (int i = 1; i <= n - 1; ++i) {
        string s;
        int happy;
        cin >> s;
        scanf("%d", &happy);
        toInt[s] = i;
        toStr[i] = s;
        weight[i] = happy;
    }

    weight[0] = 0;
    toInt[startcity] = 0;
    toStr[0] = startcity;

    for (int i = 0; i < m; ++i) {
        string s1, s2;
        int len;
        cin >> s1 >> s2;
        scanf("%d", &len);

        int u = toInt[s1];
        int v = toInt[s2];
        graph[u][v] = len;
        graph[v][u] = len;
    }

    d = toInt["ROM"], s = toInt[startcity];
    dijkstra(s);
    dfs(d);

    printf("%d %d %d %d\n", num[d], dis[d], maxHappy, (int )maxAver);

    for (int i = ans.size() - 1; i >= 0 ; --i) {
        if (i != ans.size() - 1)
            printf("->");
        printf("%s", toStr[ans[i]].c_str());
    }

    return 0;
}
