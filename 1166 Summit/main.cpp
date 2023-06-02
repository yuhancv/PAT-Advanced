#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<unordered_set<int>> graph;

void judge(set<int> &a, int index){
    bool flag = true;
    for (auto it = a.begin(); it != a.end(); it++) {

        for (auto iq = a.begin(); iq != a.end(); iq++) {
            if (iq == it)
                continue;
            if (graph[*it].find(*iq) == graph[*it].end()){
                flag = false;
                break;
            }
        }

        if (!flag)
            break;
    }

    if (!flag){
        printf("Area %d needs help.\n", index);
        return;
    }

    set<int> b;

    for (int i = 1; i <= n; ++i) {
        if (a.find(i) == a.end())
            b.insert(i);
    }

    if (b.empty()){
        printf("Area %d is OK.\n", index);
        return;
    }

    int ans = -1;

    for (auto it = b.begin(); it != b.end(); it++) {
        int u = *it;
        bool flag = true;
        for (auto iq = a.begin(); iq != a.end(); iq++) {
            int v = *iq;

            if (graph[u].find(v) == graph[u].end()){
                flag = false;
                break;
            }
        }

        if (flag){
            ans = u;
            break;
        }
    }

    if (ans == -1)
        printf("Area %d is OK.\n", index);
    else
        printf("Area %d may invite more people, such as %d.\n", index, ans);
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

    int k;
    scanf("%d", &k);

    for (int i = 1; i <= k; ++i) {
        int l;
        scanf("%d", &l);
        set<int> a;

        for (int j = 0; j < l; ++j) {
            int val;
            scanf("%d", &val);
            a.insert(val);
        }

        judge(a, i);
    }
    return 0;
}








/*
int n, m;
vector<set<int>> graph;

void judge(vector<int> &a, int index){
    bool flag1 = true;

    for (int i = 0; i < a.size(); ++i) {
        int u = a[i];
        for (int j = 0; j < a.size(); ++j) {
            if (j == i)
                continue;
            int v  = a[j];

            if (graph[u].find(v) == graph[u].end()){
                flag1 = false;
                break;
            }
        }

        if (!flag1)
            break;
    }

    if (!flag1){
        printf("Area %d needs help.\n", index);
        return;
    }

    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        if (find(a.begin(), a.end(), i) == a.end())
            b.push_back(i);
    }

    if (b.empty()){
        printf("Area %d is OK.\n", index);
        return;
    }

    vector<int> c;
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
            c.push_back(u);
    }

    if (c.empty())
        printf("Area %d is OK.\n", index);
    else
        printf("Area %d may invite more people, such as %d.\n", index, c.front());
}

int main() {
    scanf("%d%d", &n, &m);
    graph.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }

    int k;
    scanf("%d", &k);


    for (int i = 1; i <= k; ++i) {
        int l;
        scanf("%d", &l);
        vector<int> a(l);

        for (int j = 0; j < l; ++j) {
            scanf("%d", &a[j]);
        }
        judge(a, i);
    }

    return 0;
}

 */