#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<vector<int>> graph;

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
        set<int> s;
        int l;
        scanf("%d", &l);

        for (int i = 0; i < l; ++i) {
            int val;
            scanf("%d", &val);
            s.insert(val);
        }

        bool flag = true;

        for (int i = 0; i < n; ++i) {
            int u = i;

            for (int j = 0; j < graph[u].size(); ++j) {
                int v = graph[u][j];

                if (!((s.find(u) != s.end()) || (s.find(v) != s.end()))){
                    flag = false;
                    break;
                }
            }

            if (!flag)
                break;
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}




/*
int n, m;

struct e{
    int u, v;
};

vector<e> edge;

int main(){
    scanf("%d%d", &n, &m);
    edge.resize(m);

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &edge[i].u, &edge[i].v);
    }

    int k;
    scanf("%d", &k);

    while (k--){
        int l;
        scanf("%d", &l);
        set<int> s;

        for (int i = 0; i < l; ++i) {
            int val;
            scanf("%d", &val);
            s.insert(val);
        }

        bool flag = true;

        for (int i = 0; i < m; ++i) {
            int u = edge[i].u, v = edge[i].v;
            if (!((s.find(u) != s.end()) || (s.find(v) != s.end()))){
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

/*
int n, m;
struct e{
    int u, v;
};

vector<e> edge;

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge.push_back({u, v});
    }

    int k;
    scanf("%d", &k);

    while (k--){
        set<int> s;
        int l;
        scanf("%d", &l);
        for (int i = 0; i < l; ++i) {
            int val;
            scanf("%d", &val);
            s.insert(val);
        }

        bool flag = true;

        for (int i = 0; i < edge.size(); ++i) {
            int u = edge[i].u, v = edge[i].v;

            if (!(s.find(u) != s.end() || s.find(v) != s.end())){
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