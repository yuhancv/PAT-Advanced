#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), greater<int> ());
    int cur = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > cur + 1)
            cur++;
    }

    printf("%d", cur);
    return 0;
}

/*
int n;

int main(){
    scanf("%d", &n);
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), greater<int> ());
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        if (v[i] > cur + 1)
            cur++;
        else
            break;
    }

    printf("%d", cur);

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

    sort(v.begin(), v.end(), greater<int> ());
    int cur = 0;

    while (cur < n && v[cur] > cur + 1)
        cur++;

    printf("%d", cur);
    return 0;
}

 */

/*
int n;
vector<int> v;

int main() {
    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), greater<int>());

    int e = 0;

    while (e < n && v[e] > e + 1)
        e++;

    printf("%d", e);
    return 0;
}

 */
