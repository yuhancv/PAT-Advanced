#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int a[100010] = {0};

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    return 0;
}

/*
int main() {
    int n, t, cnt = 0, a[100010];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> t;
        a[t] = i;
    }

    for(int i = 1; i < n; i++) {
        if(i != a[i]) {
            while(a[0] != 0) {
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i != a[i]) {
                swap(a[0],a[i]);
                cnt++;
            }
        }

    }
    cout << cnt;
    return 0;
}

 */


/*
int n;
vector<int> table(100010);
int cnt = 0;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        table[val] = i;
    }

    for (int i = 1; i < n; ++i) {
        if (i != table[i]){

        }
    }


    return 0;
}

 */

