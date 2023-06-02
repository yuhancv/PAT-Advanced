#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct Record{
    int id, f, m, num, area;
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

const int MAXN = 10000;
int n;
int k;
vector<Record> a;
unordered_set<int> s;
vector<int> father;
map<int, Node> tree;
vector<Ans> ans;

void init(){
    father.resize(MAXN);
    for (int i = 0; i < father.size(); ++i) {
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

int main() {
    scanf("%d", &n);
    a.resize(n);
    init();

    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i].id, &a[i].f, &a[i].m, &k);
        s.insert(a[i].id);

        if (a[i].f != -1){
            s.insert(a[i].f);
            Union(a[i].id, a[i].f);
        }

        if (a[i].m != -1){
            s.insert(a[i].m);
            Union(a[i].m, a[i].id);
        }

        a[i].child.resize(k);
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
        ans.push_back({it->first, it->second.people, it->second.num, it->second.area});
    }

    sort(ans.begin(), ans.end(), cmp);

    printf("%d\n", tree.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    }

    return 0;
}
