#include <iostream>
#include "bits/stdc++.h"
using namespace std;
const int MAXN = 10010;
int n;
int picture[MAXN] = {0};
vector<int> father;
set<int> bird;
map<int, int> tree;

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
        father[fb] = fa;
}

int main(){
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; ++j) {
            int id;
            scanf("%d", &id);
            bird.insert(id);

            if (picture[i] == 0)
                picture[i] = id;

            Union(picture[i], id);
        }
    }

    for (auto it = bird.begin(); it != bird.end(); it++) {
        tree[findFather(*it)]++;
    }

    printf("%d %d\n", tree.size(), bird.size());

    int q;
    scanf("%d", &q);
    while (q--){
        int a, b;
        scanf("%d%d", &a, &b);

        int fa = findFather(a), fb = findFather(b);

        if (fa ==  fb)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}


/*
const int MAXN = 10010;
int picture[MAXN] = {0};
int n;
vector<int> father;
set<int> bird;
map<int, int> tree;

void init(){
    father.resize(MAXN);
    for (int i = 1; i < father.size(); ++i) {
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
    scanf("%d", &n);
    init();

    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; ++j) {
            int id;
            scanf("%d", &id);
            bird.insert(id);

            if (picture[i] == 0)
                picture[i] = id;

            Union(id, picture[i]);
        }
    }

    for (auto it = bird.begin(); it != bird.end(); it++) {
        tree[findFather(*it)]++;
    }

    printf("%d %d\n", tree.size(), bird.size());

    int q;
    scanf("%d", &q);

    while (q--){
        int a, b;
        scanf("%d%d", &a, &b);
        int fa = findFather(a), fb = findFather(b);
        if (fa == fb)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}


 */