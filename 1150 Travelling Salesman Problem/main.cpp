#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 210;
int n, m;
int graph[MAXN][MAXN] = {0};
struct Node{
    int id;
    int len;
};

bool cmp(Node a, Node b){
    return a.len < b.len;
}

vector<Node> ans;

void judge(vector<int> &a, int index){
    set<int> s;
    bool flag1 = true;
    int sum = 0;

    for (int i = 0; i < a.size() - 1; ++i) {
        int u = a[i], v = a[i + 1];
        if (graph[u][v] == 0){
            flag1 = false;
            break;
        }

        sum += graph[u][v];
        s.insert(a[i]);
    }
    s.insert(a.back());

    if (!flag1){
        printf("Path %d: NA (Not a TS cycle)\n", index);
        return;
    }


    if (s.size() < n || a.front() != a.back()){
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
        return;
    }

    if (s.size() == n && a.size() == n + 1){
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        ans.push_back({index, sum});
        return;
    }

    if (s.size() == n && a.size() > n + 1){
        printf("Path %d: %d (TS cycle)\n", index, sum);
        ans.push_back({index, sum});
        return;
    }
}

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] = len;
        graph[v][u] = len;
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
    sort(ans.begin(), ans.end(), cmp);
    printf("Shortest Dist(%d) = %d", ans.front().id, ans.front().len);
    return 0;
}

/*
const int MAXN = 210;
int n, m;
int graph[MAXN][MAXN] = {0};

struct Node{
    int id;
    int len;
};

vector<Node> ans;

bool cmp(Node a, Node b){
    return a.len < b.len;
}

void judge(vector<int> &a, int index){
    bool flag1 = true;
    int sum = 0;
    set<int> s;
    for (int i = 0; i < a.size() - 1; ++i) {
        int u = a[i], v = a[i + 1];
        if (graph[u][v] == 0){
            flag1 = false;
            break;
        }

        sum += graph[u][v];
        s.insert(a[i]);
    }

    if (!flag1){
        printf("Path %d: NA (Not a TS cycle)\n", index);
        return;
    }

    if (a.front() != a.back() || s.size() < n){
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
        return;
    }

    if (s.size() == n && a.size() == n + 1){
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        ans.push_back({index, sum});
        return;
    }

    if (s.size() == n && a.size() > n - 1){
        printf("Path %d: %d (TS cycle)\n", index, sum);;
        ans.push_back({index, sum});
        return;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        scanf("%d%d%d", &u, &v, &len);
        graph[u][v] = len;
        graph[v][u] = len;
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

    sort(ans.begin(), ans.end(), cmp);

   printf("Shortest Dist(%d) = %d", ans.front().id, ans.front().len);

    return 0;
}

 */
