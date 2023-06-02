#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
const int MAXN = 510;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
map<int, int> tree;


int main(){
    scanf("%d%d", &n, &m);

    return 0;
}

/*
const int MAXN = 510;
int n, m;
vector<vector<int>> graph;
bool visited[MAXN] = {false};

map<int, int> tree;

int dfs(int u){
    visited[u] = true;
    tree[u] = graph[u].size();
    int odd = (graph[u].size() % 2 == 0) ? 0 : 1;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            odd += dfs(v);
    }

    return odd;
}

int dfsCnt(){
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            dfs(u);
            cnt++;
        }
    }

    return cnt;
}

int main(){
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = dfsCnt();

    if (cnt > 1){
        for (int i = 1; i <= n; ++i) {
            if (i != 1)
                printf(" ");
            printf("%d", tree[i]);
        }

        printf("\nNon-Eulerian");
    } else{
        fill(visited, visited + MAXN, false);
        int odd = dfs(1);

        for (int i = 1; i <= n; ++i) {
            if (i != 1)
                printf(" ");
            printf("%d", tree[i]);
        }

        if (odd == 0)
            printf("\nEulerian");
        else if (odd == 2)
            printf("\nSemi-Eulerian");
        else
            printf("\nNon-Eulerian");
    }

    return 0;
}

 */


/*
const int MAXN = 510;
int n, m;
vector<vector<int>> graph;
bool visited[MAXN] = {false};
map<int, int> tree;

int dfs(int u){
    visited[u] = true;
    tree[u] = graph[u].size();
    int odd = (graph[u].size() % 2 == 0) ? 0 : 1;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            odd += dfs(v);
    }

    return odd;
}

int dfsCnt(){
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (!visited[u]){
            dfs(u);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = dfsCnt();

    if (cnt > 1){
        for (auto it = tree.begin(); it != tree.end(); it++) {
            if (it != tree.begin())
                printf(" ");
            printf("%d", it->second);
        }

        printf("\nNon-Eulerian");
    } else{
        fill(visited, visited + MAXN, false);
        int odd = dfs(1);

        for (auto it = tree.begin(); it != tree.end(); it++) {
            if (it != tree.begin())
                printf(" ");
            printf("%d", it->second);
        }

        if (odd == 0)
            printf("\nEulerian");
        else if (odd == 2)
            printf("\nSemi-Eulerian");
        else
            printf("\nNon-Eulerian");
    }

    return 0;
}

 */