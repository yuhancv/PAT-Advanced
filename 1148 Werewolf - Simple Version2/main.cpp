#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<int> a(n + 1, 1), lie;
            a[i] = a[j] = -1;

            for (int k = 1; k <= n; ++k) {
                if (v[k] * a[abs(v[k])] < 0)
                    lie.push_back(k);
            }

            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("No Solution");
    return 0;
}

/*
int n;

int main(){
    scanf("%d", &n);
    vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;

            for (int k = 1; k <= n ; ++k) {
                if (v[k] * a[abs(v[k])] < 0)
                    lie.push_back(k);
            }

            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("No Solution");
    return 0;
}

 */

/*
int n;

int main(){
    scanf("%d", &n);
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> lie, a(n, 1);
            a[i] = a[j] = -1;

            for (int k = 0; k < n; ++k) {
                if (v[k] * a[abs(v[k]) - 1] < 0)
                    lie.push_back(k);
            }

            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
                printf("%d %d", i + 1, j + 1);
                return 0;
            }
        }
    }

    printf("No Solution");
    return 0;
}

 */

/*
int n;
vector<int> v;
int main() {
    scanf("%d", &n);
    v.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }

    for (int i = 1; i <= n ; ++i) {
        for (int j = i + 1; j <= n ; ++j) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;

            for (int k = 1; k <= n; ++k) {
                if (v[k] * a[abs(v[k])] < 0)
                    lie.push_back(k);
            }

            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0){
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("No Solution");
    return 0;
}

 */