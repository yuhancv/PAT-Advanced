#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
map<int, int>
int main(){

    return 0;
}




/*
int n, m;
map<int, int> tree;

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        tree[val]++;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        it->second--;
        if (m > it->first && tree[m - it->first] != 0){
            printf("%d %d", it->first, m - it->first);
            return 0;
        }
        it->second++;
    }

    printf("No Solution");

    return 0;
}

 */