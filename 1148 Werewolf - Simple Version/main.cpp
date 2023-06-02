#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n;


int main() {
    scanf("%d", &n);
    vector<int> v(n + 1);

    for (int i = 1; i <= n ; ++i) {
        scanf("%d", &v[i]);
    }
    return 0;
}
