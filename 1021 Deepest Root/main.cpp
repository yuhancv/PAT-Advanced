#include <iostream>
#include "bits/stdc++.h"
using namespace std;


/*
int n;
const int MAXN = 10010;
vector<int> graph[MAXN];
bool visited[MAXN] = {false};

void visit(int u){
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            visit(v);
    }
}

int visitCnt(){
    int cnt = 0;
    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            cnt++;
            visit(u);
        }
    }

    return cnt;
}

vector<int> ans;
int maxDepth = -INT_MAX;

int dfs(int u, int depth){
    visited[u] = true;
    int now = depth;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            now = max(now, dfs(v, depth + 1));
    }

    return now;
}

int bfs(int start){
    visited[start] = true;
    queue<int> myQueue;
    myQueue.push(start);
    int level = 1;
    while (!myQueue.empty()){
        int width = myQueue.size();
        int num = 0;
        for (int i = 0; i < width; ++i) {
            auto u = myQueue.front();
            myQueue.pop();

            for (int j = 0; j < graph[u].size(); ++j) {
                int v = graph[u][j];
                if (visited[v] == false){
                    num++;
                    visited[v] = true;
                    myQueue.push(v);
                }
            }
        }

        if (num > 0)
            level++;
    }

    return level;
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
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = bfsCnt();

    if (cnt > 1){
        printf("Error: %d components", cnt);
        return 0;
    }

    for (int u = 1; u <= n; ++u) {
        fill(visited, visited + MAXN, false);
        int now = bfs(u);
        if (now > maxDepth){
            maxDepth = now;
            ans.clear();
            ans.push_back(u);
        } else if (now == maxDepth)
            ans.push_back(u);
    }

    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

 */


/*
const int MAXN = 10010;
int n;
vector<int> graph[MAXN];
bool visited[MAXN] = {false};
vector<int> temp;
set<int> s;
int maxDepth = 0;

void dfs(int u, int depth){
    if (depth > maxDepth){
        temp.clear();
        temp.push_back(u);
        maxDepth = depth;
    } else if (depth == maxDepth){
        temp.push_back(u);
    }

    visited[u] = true;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (visited[v] == false)
            dfs(v, depth + 1);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;

    for (int u = 1; u <= n; ++u) {
        if (visited[u] == false){
            dfs(u, 1);
            cnt++;
        }
    }

    if (cnt > 1){
        printf("Error: %d components", cnt);
        return 0;
    }

    for (int i = 0; i < temp.size(); ++i) {
        s.insert(temp[i]);
    }

    fill(visited, visited + MAXN, false);

    dfs(temp.front(), 1);

    for (int i = 0; i < temp.size(); ++i) {
        s.insert(temp[i]);
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        printf("%d\n", *it);
    }

    return 0;
}

 */
