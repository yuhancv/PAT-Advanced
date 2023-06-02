#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n, m, k;

struct e{
    int u, v;
};

vector<e> edge;
vector<int> father;

void init(int n){
    father.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

int findFather(int x){
    int a = x;
    while (x != father[x]){
        x = father[x];
    }

    while (a != father[a]){
        int temp = a;
        a = father[a];
        father[temp] = x;
    }

    return x;
}

void Union(int a, int b){
    int fa = findFather(a), fb = findFather(b);

    if (fa != fb){
        father[fb] = fa;
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge.push_back({u, v});
    }

    while (k--){
        init(n);
        int cnt = n - 1;
        int occu;
        scanf("%d", &occu);

        for (int i = 0; i < edge.size(); ++i) {
            int a = edge[i].u, b = edge[i].v;
            if (a == occu || b == occu)
                continue;

            int fa = findFather(a), fb = findFather(b);
            if (fa != fb){
                Union(a, b);
                cnt--;
            }
        }

        printf("%d\n", cnt- 1);
    }

    return 0;
}














/*
const int MAXN = 1010;
struct e{
    int u, v;
};

int n, m, k;
vector<int> father;
vector<e> edge;

void init(int n){
    father.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

int findFather(int x){
    int a = x;

    while (x != father[x]){
        x = father[x];
    }

    while (a != father[a]){
        int temp = a;
        a = father[a];
        father[temp] = x;
    }

    return x;
}

void Union(int a, int b){
    int fa = findFather(a), fb = findFather(b);
    if (fa != fb)
        father[fb] = fa;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge.push_back({u, v});
    }

    while (k--){
        init(n);
        int cnt = n - 1;
        int x;
        scanf("%d", &x);

        for (int i = 0; i < edge.size(); ++i) {
            int u = edge[i].u, v = edge[i].v;
            if (u == x || v == x)
                continue;

            int fa = findFather(u), fb = findFather(v);
            if (fa != fb){
                Union(u, v);
                cnt--;
            }
        }

        printf("%d\n", cnt - 1);

    }

    return 0;
}

 */

/*
int n, m, k;
const int MAXN = 1010;
vector<int> graph[MAXN];
bool visited[MAXN] = {false};

void dfs(int u){
    visited[u] = true;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            dfs(v);
    }
}

int dfsCnt(){
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            cnt++;
            dfs(u);
        }
    }

    return cnt;
}

void bfs(int u){
    visited[u] = true;
    queue<int> myQueue;
    myQueue.push(u);

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();

            for (int j = 0; j < graph[cur].size(); ++j) {
                int v = graph[cur][j];

                if (visited[v] == false){
                    visited[v] = true;
                    myQueue.push(v);
                }
            }
        }
    }
}

int bfsCnt(){
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            bfs(u);
            cnt++;
        }
    }

    return cnt;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    while (k--){
        fill(visited, visited + MAXN, false);
        int occu;
        scanf("%d", &occu);
        visited[occu] = true;

        int cnt = bfsCnt();
        printf("%d\n", cnt - 1);
    }

    return 0;
}

 */

/*
const int MAXN = 1010;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int n, m, k;

void dfs(int u){
    visited[u] = true;

    for (int v = 1; v <= n; ++v) {
        if (graph[u][v] != 0 && visited[v] == false)
            dfs(v);
    }
}

int dfsCnt(){
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            cnt++;
            dfs(u);
        }
    }

    return cnt;
}

void bfs(int u){
    visited[u] = true;
    queue<int> myQueue;
    myQueue.push(u);

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto u = myQueue.front();
            myQueue.pop();

            for (int v = 1; v <= n; ++v) {
                if (graph[u][v] != 0 && visited[v] == false){
                    visited[v] = true;
                    myQueue.push(v);
                }
            }
        }
    }
}

int bfsCnt(){
    int cnt = 0;

    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            bfs(u);
            cnt++;
        }
    }

    return cnt;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    while (k--){
        fill(visited, visited + MAXN, false);
        int occu;
        scanf("%d", &occu);
        visited[occu] = true;
        int cnt = bfsCnt();
        printf("%d\n", cnt - 1);
    }

    return 0;
}

 */
