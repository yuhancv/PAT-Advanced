#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int N, m, n;
vector<int> v;

bool cmp(int a, int b){
    return a >= b;
}

int main(){
    scanf("%d", &N);
    v.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), cmp);


    return 0;
}



/*
int N;
int m, n;
vector<int> v;

bool cmp(int a, int b){
    return a >= b;
}

int main(){
    scanf("%d", &N);
    v.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = (int ) sqrt(N); i >= 1 ; --i) {
        if (N % i == 0){
            n = i;
            m = N / i;
            break;
        }
    }

    vector<vector<int>> graph(m, vector<int> (n));
    int level = m + (m % 2);
    int cur = 0;

    for (int i = 0; i < level; ++i) {
        for (int j = i; j <= n - 1 - i && cur < N ; ++j) {
            graph[i][j] = v[cur++];
        }

        for (int j = 1 + i; j <= m - 2 - i && cur < N ; ++j) {
            graph[j][n - 1 - i] = v[cur++];
        }

        for (int j = n - 1 - i; j >= i && cur < N ; --j) {
            graph[m - 1 - i][j] = v[cur++];
        }

        for (int j = m - 2 - i; j >= 1 + i && cur < N ; --j) {
            graph[j][i] = v[cur++];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0)
                printf(" ");
            printf("%d", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}

 */

/*
int N;
vector<int> v;
int n, m;

bool cmp(int a, int b){
    return a >= b;
}

int main(){
    scanf("%d", &N);
    v.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = (int ) sqrt(N); i >= 1; --i) {
        if (N % i == 0){
            m = N / i;
            n = i;
            break;
        }
    }

    int level = m / 2 + (m % 2);
    int cur = 0;
    vector<vector<int>> graph(m, vector<int> (n));
    
    for (int i = 0; i < level; ++i) {
        for (int j = i; j <= n - 1 - i && cur < N; ++j) {
            graph[i][j] = v[cur++];
        }

        for (int j = 1 + i; j <= m - 2 - i && cur < N; ++j) {
            graph[j][n - 1 - i] = v[cur++];
        }

        for (int j = n - 1 - i; j >= i && cur < N; --j) {
            graph[m - 1 - i][j] = v[cur++];
        }

        for (int j = m - 2 - i; j >= 1 + i && cur < N; --j) {
            graph[j][i] = v[cur++];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0)
                printf(" ");
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}

 */


/*
int N;
int n, m;

bool cmp(int a, int b){
    return a >= b;
}

int main(){
    scanf("%d", &N);
    vector<int> v(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), cmp);

    for (n = (int ) sqrt(N); n >= 1; --n) {
        if (N % n == 0){
            m = N / n;
            break;
        }
    }

    vector<vector<int>> graph(m, vector<int> (n));
    int level = m / 2 + m % 2;
    int cur = 0;

    for (int i = 0; i < level; ++i) {
        for (int j = i; j <= n - 1 - i && cur < N; ++j) {
            graph[i][j] = v[cur++];
        }

        for (int j = i + 1; j <= m - 2 - i && cur < N; ++j) {
            graph[j][n - 1 - i] = v[cur++];
        }

        for (int j = n - 1 - i; j >= i && cur < N; --j) {
            graph[m - 1 - i][j] = v[cur++];
        }

        for (int j = m - 2 - i; j >= i + 1 && cur < N; --j) {
            graph[j][i] = v[cur++];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0)
                printf(" ");
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}

 */

/*
int N;
int n, m;
vector<int> v;

bool cmp(int a, int b){
    return a >= b;
}

int main() {
    scanf("%d", &N);
    v.resize(N);

    for (n = (int)sqrt(N); n >= 1 ; --n) {
        if (N % n == 0){
            m = N / n;
            break;
        }
    }


    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    sort(v.begin(), v.end(), cmp);
    vector<vector<int>> graph(m, vector<int>(n));
    int level = m / 2 + m % 2;
    int now = 0;

    for (int i = 0; i < level; ++i) {
        for (int j = i; j <= n - 1 - i && now <= N - 1; ++j) {
            graph[i][j] = v[now++];
        }

        for (int j = i + 1; j <= m - 2 - i && now <= N - 1 ; ++j) {
            graph[j][n - 1 - i] = v[now++];
        }

        for (int j = n - 1 - i; j >= i && now <= N - 1 ; --j) {
            graph[m - 1 - i][j] = v[now++];
        }

        for (int j = m - 2 - i; j >= 1 + i && now <= N - 1 ; --j) {
            graph[j][i] = v[now++];
        }
    }
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", graph[i][j]);
            if (j != n - 1)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}

 */