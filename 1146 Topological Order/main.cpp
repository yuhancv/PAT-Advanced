#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<set<int>> graph, temp;
vector<int> ans;

int getIn(int u){
    int cnt = 0;
    for (int v = 1; v <= n; ++v) {
        if (u == v)
            continue;
        if (temp[v].find(u) != temp[v].end())
            cnt++;
    }
    return cnt;
}

void judge(vector<int> &a, int index){
    bool flag = true;
    for (int i = 0; i < a.size(); ++i) {
        if (getIn(a[i]) != 0){
            flag = false;
            break;
        }

        temp[a[i]].clear();
    }

    if (!flag)
        ans.push_back(index);
}

int main(){
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].insert(v);
    }

    int k;
    scanf("%d", &k);


    for (int i = 0; i < k; ++i) {
        temp = graph;
        vector<int> a(n);

        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
        }

        judge(a, i);
    }

    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}

/*
int n, m;
vector<set<int>> graph, temp;
vector<int> ans;

int getIn(int u){
    int cnt = 0;
    for (int v = 1; v <= n; ++v) {
        if (u == v)
            continue;
        if (temp[v].find(u) != temp[v].end())
            cnt++;
    }

    return cnt;
}

void judge(vector<int> &a, int index){
    bool flag = true;
    for (int i = 0; i < a.size(); ++i) {
        if (getIn(a[i]) != 0){
            flag = false;
            break;
        }

        temp[a[i]].clear();
    }

    if (!flag)
        ans.push_back(index);
}

int main(){
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].insert(v);
    }

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        vector<int> a(n);
        temp = graph;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
        }

        judge(a, i);
    }

    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}

 */

/*
int n, m;
vector<int> ans;
vector<unordered_set<int>> graph;
vector<unordered_set<int>> temp;

int getIn(int v){
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (i == v)
            continue;
        if (temp[i].find(v) != temp[i].end())
            cnt++;
    }

    return cnt;
}

void judge(vector<int> &a, int index){
    bool flag = true;
    for (int i = 0; i < a.size(); ++i) {
        if (getIn(a[i]) != 0){
            flag = false;
            break;
        }

        temp[a[i]].clear();
    }

    if (!flag)
        ans.push_back(index);
}

int main() {
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].insert(v);
    }

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        temp = graph;
        vector<int> a(n);

        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
        }

        judge(a, i);
    }

    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}

 */
