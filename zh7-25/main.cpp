#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n, m;
int club[1010] = {0};
vector<int> father;
map<int, int> tree;

void init(int n){
    father.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
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
        father[fb] = fa;
}

int main() {
    scanf("%d%d", &n, &m);
    init(n);

    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; ++j) {
            int id;
            scanf("%d", &id);

            if (club[i] == 0)
                club[i] = id;

            Union(club[i], id);
        }
    }

    for (int i = 1; i <= n; ++i) {
        tree[findFather(i)]++;
    }

    int num = 0;

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second > num)
            num = it->second;
    }

    printf("%d", num);
    return 0;
}
