#include <iostream>
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 10000;
int n, k;
struct Record{
    int id, fid, mid, num, area;
    vector<int> child;
};

struct Node{
    int people;
    double num, area;
};

struct Ans{
    int id, people;
    double num, area;
};

map<int, Node> tree;
vector<int> father;
vector<Record> a;
set<int> s;
void init(){
    father.resize(MAXN);
    for (int i = 0; i < father.size(); ++i) {
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
    if (fa != fb)
        father[max(fa, fb)] = min(fa, fb);
}

bool cmp(Ans a, Ans b){
    if (a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}

int main(){
    scanf("%d", &n);
    init();
    a.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i].id, &a[i].fid, &a[i].mid, &k);
        a[i].child.resize(k);
        s.insert(a[i].id);

        if (a[i].fid != -1){
            Union(a[i].id, a[i].fid);
            s.insert(a[i].fid);
        }

        if (a[i].mid != -1){
          Union(a[i].id, a[i].mid);
          s.insert(a[i].mid);
        }

        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[i].child[j]);
            Union(a[i].id, a[i].child[j]);
            s.insert(a[i].child[j]);
        }

        scanf("%d%d", &a[i].num, &a[i].area);
    }

    for (int i = 0; i < n; ++i) {
        tree[findFather(a[i].id)].num += a[i].num;
        tree[findFather(a[i].id)].area += a[i].area;
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        tree[findFather(*it)].people++;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        it->second.num /= it->second.people;
        it->second.area /= it->second.people;
        //printf("%04d %d %f %f\n", it->first, it->second.people, it->second.num, it->second.area);
    }

    vector<Ans> ans;
    for (auto it = tree.begin(); it != tree.end(); it++) {
        ans.push_back({it->first, it->second.people, it->second.num, it->second.area});
    }

    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", tree.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    }

    return 0;
}



/*
const int MAXN = 10010;
int n;
vector<int> father;
bool visited[MAXN] = {false};
struct Node{
    int id, f, m, num, area;
    vector<int> child;
}data[1010];

struct Ans{
    int id, people;
    double num, area;
    bool flag = false;
}ans[MAXN];

void init(){
    father.resize(MAXN);
    for (int i = 0; i < father.size(); ++i) {
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
    if (fa != fb)
        father[max(fa, fb)] = min(fa, fb);
}

int main() {
    scanf("%d", &n);
    init();

    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d%d%d%d", &data[i].id, &data[i].f, &data[i].m, &k);
        visited[data[i].id] = true;

        if (data[i].f != -1){
            visited[data[i].f ] = true;
            Union(data[i].id, data[i].f);
        }

        if (data[i].m != -1){
            visited[data[i].m] = true;
            Union(data[i].id, data[i].m);
        }

        data[i].child.resize(k);

        for (int j = 0; j < k; ++j) {
            scanf("%d", &data[i].child[j]);
            visited[data[i].child[j]] = true;
            Union(data[i].child[j], data[i].id);
        }

        scanf("%d%d", &data[i].num, &data[i].area);
    }

    for (int i = 0; i < n; ++i) {
        int f = findFather(data[i].id);
        ans[f].id = f;
        ans[f].num += data[i].num;
        ans[f].area += data[i].area;
        ans[f].flag = true;
    }
    return 0;
}

 */
