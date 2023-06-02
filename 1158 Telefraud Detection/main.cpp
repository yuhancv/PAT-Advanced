#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1010;
int k, n, m;
vector<int> father;
vector<int> bad;
map<int, set<int>> tree;
int graph[MAXN][MAXN] = {0};

void init(int n){
    father.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

int findFather(int x){
    int a = x;
    while (x != father[x])
        x = father[x];
    while (a != father[x]){
        int temp = a;
        a = father[a];
        father[temp] = x;
    }
    return x;
}

void Union(int a, int b){
    int fa = findFather(a), fb = findFather(b);
    if (fa != fb){
        father[max(fa, fb)] = min(fa, fb);
    }
}

bool connect(int u, int v){
    if (graph[u][v] > 0 && graph[v][u] > 0)
        return true;
    else
        return false;
}

bool judge(int u){
    int cnt = 0, back = 0;
    for (int v = 1; v <= n ; ++v) {
        if (v == u || graph[u][v] == 0)
            continue;
        if (graph[u][v] > 0 && graph[u][v] <= 5){
            cnt++;
            if (graph[v][u] > 0)
                back++;
        }
    }

    if (cnt > k && 5 * back <= cnt)
        return true;
    else
        return false;
}

int main(){
    scanf("%d%d%d", &k, &n, &m);
    init(n);

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] += len;
    }

    for (int i = 1; i <= n; ++i) {
        if (judge(i))
            bad.push_back(i);
    }

    if (bad.empty()){
        printf("None\n");
        return 0;
    }

    for (int i = 0; i < bad.size(); ++i) {
        int u = bad[i];

        for (int j = 0; j < bad.size(); ++j) {
            if (j == i)
                continue;
            int v = bad[j];
            if (connect(u, v))
                Union(u, v);
        }
    }

    for (int i = 0; i < bad.size(); ++i) {
        int u = bad[i];
        tree[findFather(u)].insert(u);
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        int f = it->first;

        for (auto iq = tree[f].begin(); iq != tree[f].end(); iq++) {
            if (iq != tree[f].begin())
                printf(" ");
            printf("%d", *iq);
        }
        printf("\n");
    }

    return 0;
}









/*
const int MAXN = 1100;
vector<int> father;
int k, n, m;
int graph[MAXN][MAXN] = {0};
map<int, set<int>> tree;
vector<int> bad;

void init(int n){
    father.resize(n + 1);
    for (int i = 1; i <= n ; ++i) {
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

bool connect(int u, int v){
    if (graph[u][v] > 0 && graph[v][u] > 0)
        return true;
    else
        return false;
}

bool isBad(int u){
    int cnt = 0, back = 0;
    for (int v = 1; v <= n ; ++v) {
        if (v == u || graph[u][v] == 0)
            continue;
        if (graph[u][v] > 0 && graph[u][v] <= 5){
            cnt++;
            if (graph[v][u] > 0)
                back++;
        }
    }

    if (cnt > k && 5 * back <= cnt)
        return true;
    else
        return false;
}

void Union(int a, int b){
    int fa = findFather(a), fb = findFather(b);
    if (fa != fb)
        father[max(fa, fb)] = min(fa, fb);
}

int main(){
    scanf("%d%d%d", &k, &n, &m);
    init(n);

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] += len;
    }

    for (int i = 1; i <= n; ++i) {
        if (isBad(i))
            bad.push_back(i);
    }

    if (bad.empty()){
        printf("None");
        return 0;
    }

    for (int i = 0; i < bad.size(); ++i) {
        int u = bad[i];
        for (int j = 0; j < bad.size(); ++j) {
            if (j == i)
                continue;
            int v = bad[j];
            if (connect(u, v))
                Union(u, v);
        }
    }

    for (int i = 0; i <= bad.size(); ++i) {
        int u = bad[i];
        tree[findFather(u)].insert(u);
    }
    printf("%d", tree[0].size());

    return 0;
}
 */

/*
const int MAXN = 1100;
int k, n, m;
int graph[MAXN][MAXN] = {0};
vector<int> father;
map<int, set<int>> tree;
vector<int> bad;

void init(int n){
    father.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

int findFather(int x){
    int a = x;
    while (x != father[x])
        x = father[x];

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
        father[max(fa, fb)] = min(fa, fb);
    }
}

bool connect(int u, int v){
    if (graph[u][v] > 0 && graph[v][u] > 0)
        return true;
    else
        return false;
}

bool isBad(int u){
    int cnt = 0, back = 0;
    for (int v = 1; v <= n; ++v) {
        if (v == u || graph[u][v] == 0)
            continue;
        if (graph[u][v] > 0 && graph[u][v] <= 5){
            cnt++;
            if (graph[v][u] > 0)
                back++;
        }
    }

    if (cnt > k && 5 * back <= cnt)
        return true;
    else
        return false;
}

int main() {
    scanf("%d%d%d", &k, &n, &m);
    init(n);

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] += len;
    }

    for (int i = 1; i <= n; ++i) {
        if (isBad(i))
            bad.push_back(i);
    }

    if (bad.empty()){
        printf("None");
        return 0;
    }

    for (int i = 0; i < bad.size(); ++i) {
        int u = bad[i];
        for (int j = 0; j < bad.size(); ++j) {
            if (j == i)
                continue;
            int v = bad[j];
            if (connect(u, v))
                Union(u, v);
        }
    }

    for (int i = 0; i < bad.size(); ++i) {
        int u = bad[i];
        tree[findFather(u)].insert(u);
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        int f = it->first;
        for (auto iq = tree[f].begin(); iq != tree[f].end(); iq++) {
            if (iq != tree[f].begin())
                printf(" ");
            printf("%d", *iq);
        }
        printf("\n");
    }

    return 0;
}


 */