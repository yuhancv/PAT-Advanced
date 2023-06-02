#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<vector<int>> graph;

bool judge(vector<int> &a){
    bool flag = true;

    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];

            if (a[u] == a[v]){
                flag = false;
                break;
            }
        }

        if (!flag)
            break;
    }

    return flag;
}

int main(){
    scanf("%d%d", &n, &m);
    graph.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int k;
    scanf("%d", &k);

    while (k--){
        vector<int> a(n);
        set<int> s;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }

        if (!judge(a))
            printf("No\n");
        else
            printf("%d-coloring\n", s.size());
    }

    return 0;
}


/*
int n, m;
vector<set<int>> graph;

bool judge(vector<int> &a){
    bool flag = true;
    for (int u = 0; u < n; ++u) {
        for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
            int v = *it;
            if (a[u] == a[v]){
                flag = false;
                break;
            }
        }

        if (flag == false)
            break;
    }

    return flag;
}

int main() {
    scanf("%d%d", &n, &m);
    graph.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }

    int k;
    scanf("%d", &k);

    while (k--){
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }

        if (!judge(a))
            printf("No\n");
        else
            printf("%d-coloring\n", s.size());
    }

    return 0;
}

 */