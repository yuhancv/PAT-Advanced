#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<unordered_set<int>> graph;

int judge(vector<int> &a){
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            if (i == j)
                continue;
            if (graph[a[i]].find(a[j]) == graph[a[i]].end())
                return 3;
        }
    }

    vector<int> b;
    for (int i = 1; i <= n ; ++i) {
        if (find(a.begin(), a.end(), i) == a.end())
            b.push_back(i);
    }

    if (b.empty())
        return 1;

    for (int i = 0; i < b.size(); ++i) {
        int u = b[i];
        bool flag = true;
        for (int j = 0; j < a.size(); ++j) {
            int v = a[j];
            if (graph[u].find(v) == graph[u].end()){
                flag = false;
                break;
            }
        }

        if (flag)
            return 2;
    }

    return 1;
}

int main(){
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }

    int l;
    scanf("%d", &l);

    while (l--){
        int k;
        scanf("%d", &k);
        vector<int> a(k);

        for (int i = 0; i < k; ++i) {
            scanf("%d", &a[i]);
        }

        int flag = judge(a);

        if (flag == 1)
            printf("Yes\n");
        else if (flag == 2)
            printf("Not Maximal\n");
        else
            printf("Not a Clique\n");
    }
    return 0;
}




/*
int n, m;
vector<vector<int>> graph;

int judge(vector<int> &a){
    bool flag1 = true;

    for (int i = 0; i < a.size(); ++i) {
        int u = a[i];
        for (int j = 0; j < a.size(); ++j) {
            if (j == i)
                continue;
            int v = a[j];

            if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end()){
                flag1 = false;
                break;
            }
        }

        if (!flag1)
            break;
    }

    if (!flag1)
        return 2;

    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        if (find(a.begin(), a.end(), i) == a.end())
            b.push_back(i);
    }

    if (b.empty()){
        return 0;
    }

    vector<int> c;
    for (int i = 0; i < b.size(); ++i) {
        int u = b[i];
        bool flag = true;
        for (int j = 0; j < a.size(); ++j) {
            int v = a[j];

            if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end()){
                flag = false;
                break;
            }
        }

        if (flag)
            c.push_back(u);
    }

    if (c.empty())
        return 0;
    else
        return 1;
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

    int k;
    scanf("%d", &k);

    while (k--){
        int l;
        scanf("%d", &l);
        vector<int> a(l);

        for (int i = 0; i < l; ++i) {
            scanf("%d", &a[i]);
        }

        int flag = judge(a);

        if (flag == 0)
            printf("Yes\n");
        else if (flag == 1)
            printf("Not Maximal\n");
        else
            printf("Not a Clique\n");
    }
    return 0;
}

 */
