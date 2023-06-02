#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 210;
int n, m;
int graph[MAXN][MAXN] = {0};


int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    int k;
    scanf("%d", &k);

    while (k--){
        int l;
        scanf("%d", &l);
        vector<int> a(l);
        set<int> s;

        for (int i = 0; i < l; ++i) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }

        if (a.front() != a.back() || s.size() != n || a.size() - 1 > n){
            printf("NO\n");
            continue;
        }
        
        bool flag = true;

        for (int i = 0; i < a.size() - 1; ++i) {
            int u = a[i], v = a[i + 1];
            if (graph[u][v] == 0){
                flag = false;
                break;
            }
        }

        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}



/*
int n, m;
vector<vector<int>> graph;

int main() {
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k;
    scanf("%d", &k);

    while (k--){
        int l;
        scanf("%d", &l);
        vector<int> v(l);
        set<int> s;

        for (int i = 0; i < l; ++i) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }

        if (s.size() != n || v.front() != v.back() || v.size() - 1 > n){
            printf("NO\n");
            continue;
        }

        bool flag = true;
        for (int i = 0; i < v.size() - 1; ++i) {
            if (find(graph[v[i]].begin(), graph[v[i]].end(), v[i + 1]) == graph[v[i]].end()){
                flag = false;
                break;
            }
        }

        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

 */
