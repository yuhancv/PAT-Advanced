#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, k, p;
vector<int> v;
int maxFactor = -INT_MAX;
vector<int> ans, temp;

void init(){
    int index = 0;
    while (pow(index, p) <= n){
        v.push_back(pow(index, p));
        index++;
    }
}

void dfs(int cur, int num, int sum, int tempFactor){
    if (num > k || sum > n)
        return;
    if (num == k && sum == n && tempFactor > maxFactor){
        maxFactor = tempFactor;
        ans = temp;
        return;
    }

    for (int i = cur; i >= 1 ; --i) {
        temp.push_back(i);
        dfs(i, num + 1, sum + v[i], tempFactor + i);
        temp.pop_back();
    }
}

int main(){
    scanf("%d%d%d", &n, &k, &p);
    init();

    dfs(v.size() - 1, 0, 0, 0);

    if (maxFactor < 0)
        printf("Impossible");
    else{
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); ++i) {
            if (i != 0)
                printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }

    return 0;
}




/*
int n, k, p;
vector<int> v;

void init(){
    int di = 0;
    while (pow(di, p) <= n){
        v.push_back(pow(di, p));
        di++;
    }
}

int maxFactor = -INT_MAX;
vector<int> ans, temp;

void dfs(int cur, int num, int sum, int factor){
    if (num > k || sum > n){
        return;
    }

    if (num == k && sum == n && factor > maxFactor){
        maxFactor = factor;
        ans = temp;
        return;
    }

    for (int i = cur; i >= 1 ; i--) {
        temp.push_back(i);
        dfs(i, num + 1, sum + v[i], factor + i);
        temp.pop_back();
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    init();

    dfs(v.size() - 1, 0, 0, 0);

    if (maxFactor < 0)
        printf("Impossible");
    else{
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); ++i) {
            if (i != 0)
                printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }

    return 0;
}

 */



