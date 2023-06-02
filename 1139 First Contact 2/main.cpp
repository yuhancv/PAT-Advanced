#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct Node{
    int c, d;
};

bool cmp(Node x, Node y){
    if (x.c != y.c)
        return x.c < y.c;
    else
        return x.d < y.d;
}

int n, m;
const int MAXN = 10000;

vector<int> graph[MAXN];
unordered_map<int, bool> arr;

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        int u = abs(stoi(a)), v = abs(stoi(b));
        if (a.size() == b.size()){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        arr[u * MAXN + v] = arr[v * MAXN + u] = true;
    }

    int k;
    scanf("%d", &k);

    while (k--){
        int a, b;
        scanf("%d%d", &a, &b);
        vector<Node> ans;

        for (int i = 0; i < graph[abs(a)].size(); ++i) {
            int c = graph[abs(a)][i];

            for (int j = 0; j < graph[abs(b)].size(); ++j) {
                int d = graph[abs(b)][j];

                if (c == abs(b) || d == abs(a))
                    continue;

                if (arr[c * MAXN + d] == true)
                    ans.push_back({c, d});
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());

        for (int i = 0; i < ans.size(); ++i) {
            printf("%04d %04d\n", ans[i].c, ans[i].d);
        }
    }

    return 0;
}


/*
const int MAXN = 10000;
int n, m;

struct Node{
    int c, d;
};

bool cmp(Node x, Node y){
    if (x.c != y.c)
        return x.c < y.c;
    else
        return x.d < y.d;
}

vector<int> graph[MAXN];
unordered_map<int, bool> arr;

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        int u = abs(stoi(a)), v = abs(stoi(b));

        if (a.size() == b.size()){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        arr[u * MAXN + v] = arr[v * MAXN + u] = true;
    }


    int k;
    scanf("%d", &k);

    while (k--){
        vector<Node> ans;
        int a, b;
        scanf("%d%d", &a, &b);

        for (int i = 0; i < graph[abs(a)].size(); ++i) {
            int c = graph[abs(a)][i];

            for (int j = 0; j < graph[abs(b)].size(); ++j) {
                int d = graph[abs(b)][j];

                if (c == abs(b) || d == abs(a))
                    continue;

                if (arr[c * MAXN + d] == true)
                    ans.push_back({c, d});
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("%04d %04d\n", ans[i].c, ans[i].d);
        }

    }

    return 0;
}

 */








/*
const int MAXN = 10000;
int n, m;

struct Node{
    int a, b;
};

bool cmp(Node x, Node y){
    if (x.a != y.a)
        return x.a < y.a;
    else
        return x.b < y.b;
}

unordered_map<int, bool> arr;
vector<int> graph[10000];

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        int u = abs(stoi(a)), v = abs(stoi(b));

        if (a.size() == b.size()){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        arr[u * MAXN + v] = arr[v * MAXN + u] = true;
    }

    int k;
    scanf("%d", &k);

    while (k--){
        vector<Node> ans;
        int a, b;
        scanf("%d%d", &a, &b);

        for (int i = 0; i < graph[abs(a)].size(); ++i) {
            int c = graph[abs(a)][i];
            for (int j = 0; j < graph[abs(b)].size(); ++j) {
                int d = graph[abs(b)][j];

                if (c == abs(b) || d == abs(a))
                    continue;

                if (arr[c * MAXN + d] == true)
                    ans.push_back({c, d});
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("%04d %04d\n", ans[i].a, ans[i].b);
        }
    }

    return 0;
}

 */


/*
int n, m;

unordered_map<int, bool> arr;

struct Node{
    int a, b;
};

bool cmp(Node x, Node y){
    if (x.a != y.a)
        return x.a < y.a;
    else
        return x.b < y.b;
}

vector<int> graph[10010];

int main(){
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;

        if (a.size() == b.size()){
            graph[abs(stoi(a))].push_back(abs(stoi(b)));
            graph[abs(stoi(b))].push_back(abs(stoi(a)));
        }

        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }

    int k;
    scanf("%d", &k);

    while (k--){
        int c, d;
        scanf("%d%d", &c, &d);
        vector<Node> ans;

        for (int i = 0; i < graph[abs(c)].size(); ++i) {
            int u = graph[abs(c)][i];
            for (int j = 0; j < graph[abs(d)].size(); ++j) {
                int v = graph[abs(d)][j];

                if (graph[abs(c)][i] == abs(d) || abs(c) == graph[abs(d)][j])
                    continue;
                if (arr[u * 10000 + v] == true)
                    ans.push_back({u, v});
            }
        }

        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i) {
            printf("%04d %04d\n", ans[i].a, ans[i].b);
        }
    }

    return 0;
}

 */


/*
unordered_map<int, bool> arr;
struct Node{
    int a, b;
};
const int MAXN = 10000;
int n, m;
vector<int> graph[MAXN];

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        if (a.size() == b.size()){
            graph[abs(stoi(a))].push_back(abs(stoi(b)));
            graph
        }

    }
    return 0;
}

 */