#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
vector<int> father;
int hobby[1010] = {0};
map<int, int> tree;
vector<int> ans;

bool cmp(int a, int b){
    return a >= b;
}

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
    if (fa != fb){
        father[fb] = fa;
    }
}

int main(){
    scanf("%d", &n);
    init(n);

    for (int i = 1; i <= n; ++i) {
        int k;
        scanf("%d:", &k);

        while (k--){
            int h;
            scanf("%d", &h);

            if (hobby[h] == 0)
                hobby[h] = i;

            Union(hobby[h], i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        tree[findFather(i)]++;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        ans.push_back(it->second);
    }

    sort(ans.begin(), ans.end(), cmp);

    printf("%d\n", tree.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}


/*
int n;
vector<int> father;
int hobby[1010] = {0};

bool cmp(int a, int b){
    return a >= b;
}

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
    if (fa != fb){
        father[fb] = fa;
    }
}

int main() {
    scanf("%d", &n);
    init(n);

    for (int i = 1; i <= n; ++i) {
        int k;
        scanf("%d:", &k);

        for (int j = 0; j < k; ++j) {
            int h;
            scanf("%d", &h);

            if (hobby[h] == 0)
                hobby[h] = i;

            Union(hobby[h], i);
        }
    }

    vector<int> ans;
    map<int, int> tree;

    for (int i = 1; i <= n; ++i) {
        tree[findFather(i)]++;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        ans.push_back(it->second);
    }

    sort(ans.begin(), ans.end(), cmp);

    printf("%d\n", tree.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}

 */
