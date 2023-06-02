#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1010;
vector<int> graph[MAXN];
bool visited[MAXN] = {false};
vector<int> table(MAXN);
int n, l;

int bfs(int start){
    if (start < 1 || start > n)
        return 0;
    int sum = 0;
    int level = 0;
    visited[start] = true;
    queue<int> myQueue;
    myQueue.push(start);

    while (!myQueue.empty()){
        level++;
        if (level > l)
            break;

        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto u = myQueue.front();
            myQueue.pop();

            for (int j = 0; j < graph[u].size(); ++j) {
                int v = graph[u][j];

                if (!visited[v]){
                    visited[v] = true;
                    myQueue.push(v);
                    sum++;
                }
            }
        }
    }

    return sum;
}

int dfs(int u, int depth){
    if (depth > l + 1)
        return 0;
    if (depth == l + 1 && visited[u] == false){
        visited[u] = true;
        return 1;
    }

    table[u] = depth;
    int sum = 0;
    if (visited[u] == false){
        visited[u] = true;
        sum++;
    }

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false || depth + 1 < table[v])
            sum += dfs(v, depth + 1);
    }

    return sum;
}

int main(){
    scanf("%d%d", &n, &l);

    for (int u = 1; u <= n; ++u) {
        int m;
        scanf("%d", &m);

        for (int i = 0; i < m; ++i) {
            int v;
            scanf("%d", &v);
            graph[v].push_back(u);
        }
    }

    int k;
    scanf("%d", &k);

    while (k--){
        fill(table.begin(), table.end(), 7);
        fill(visited, visited + MAXN, false);
        int start;
        scanf("%d", &start);
        printf("%d\n", dfs(start, 1) - 1);
    }

    return 0;
}


/*
const int MAXN = 1010;
vector<int> graph[MAXN];
bool visited[MAXN] = {false};
int n, l;
vector<int> table(MAXN);


int bfs(int start){
    if (start < 1 || start > n)
        return 0;

    int level = 0;
    int sum = 0;
    visited[start] = true;
    queue<int> myQueue;
    myQueue.push(start);

    while (!myQueue.empty()){
        level++;
        if (level > l)
            break;

        int width = myQueue.size();
        for (int i = 0; i < width; ++i) {
            auto u = myQueue.front();
            myQueue.pop();

            for (int j = 0; j < graph[u].size(); ++j) {
                int v = graph[u][j];

                if (visited[v] == false){
                    visited[v] = true;
                    sum++;
                    myQueue.push(v);
                }
            }
        }
    }

    return sum;
}

int dfs(int u, int depth){
    if (depth > 1 + l)
        return 0;
    if (depth == 1 + l && visited[u] == false){
        visited[u] = true;
        return 1;
    }

    int sum = 0;
    if (visited[u] == false){
        sum++;
        visited[u] = true;
    }

    table[u] = depth;

    for (int i = 0; i < graph[u].size(); ++i) {
        auto v = graph[u][i];

        if (visited[v] == false || depth + 1 < table[v])
            sum += dfs(v, depth + 1);
    }

    return sum;
}



int main() {
    scanf("%d%d", &n, &l);

    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);

        for (int j = 0; j < m; ++j) {
            int v;
            scanf("%d", &v);
            graph[v].push_back(i);
        }
    }

    int k;
    scanf("%d", &k);

    while (k--){
        fill(table.begin(), table.end(), 7);
        fill(visited, visited + MAXN, false);
        int start;
        scanf("%d", &start);
        int cnt = dfs(start, 1);
        printf("%d\n", cnt - 1);
    }

    return 0;
}

 */