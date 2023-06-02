#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 10010;
int n, k;
struct Record{
    int id, f, m, num, area;
    vector<int> child;
};
vector<Record> a;
vector<int> father;

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

set<int> s;

int main() {
    scanf("%d", &n);
    a.resize(n);
    init();

    for (int i = 0; i < n; ++i) {
        int id, f, m, k;
        int num, area;
        scanf("%d%d%d%d", &id, &f, &m, &k);
        s.insert(id);

        if (f != -1){
            Union(f, id);
            s.insert(f);
        }

        if (m != -1){
            Union(m, id);
            s.insert(m);
        }

        a[i].child.resize(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[i].child[j]);
            Union(a[i].child[j], id);
            s.insert(a[i].child[j]);
        }
    }

    /*
    set<int> t;

    for (auto it = s.begin(); it != s.end(); it++) {
        t.insert(findFather(*it));
    }

    printf("%d", t.size());
     */

    return 0;
}
