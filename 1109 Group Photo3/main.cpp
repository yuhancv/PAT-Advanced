#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, k;

struct Node{
    string name;
    int height;
};

bool cmp(Node a, Node b){
    if (a.height != b.height)
        return a.height > b.height;
    else
        return a.name <= b.name;
}

vector<Node> v;

int main(){
    scanf("%d%d", &n, &k);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].name;
        scanf("%d", &v[i].height);
    }

    sort(v.begin(), v.end(), cmp);

    int m; int cur = 0;

    for (int i = k; i >= 1 ; --i) {
        if (i == k){
            m = n - (n / k) * (k - 1);
        } else{
            m = n / k;
        }

        vector<string> ans(m);
        ans[m / 2] = v[cur].name;

        int j = m / 2 - 1;
        for (int l = cur + 1; l < cur + m; l += 2) {
            ans[j--] = v[l].name;
        }

        j = m / 2 + 1;
        for (int l = cur + 2; l < cur + m; l += 2) {
            ans[j++] = v[l].name;
        }

        for (int l = 0; l < ans.size(); ++l) {
            if (l != 0)
                printf(" ");
            printf("%s", ans[l].c_str());
        }

        printf("\n");
        cur += m;
    }

    return 0;
}


/*
int n, k;
struct Node{
    string name;
    int height;
};
vector<Node> v;

bool cmp(Node a, Node b){
    if (a.height != b.height)
        return a.height > b.height;
    else
        return a.name <= b.name;
}

int main(){
    scanf("%d%d", &n, &k);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].name;
        scanf("%d", &v[i].height);
    }

    sort(v.begin(), v.end(), cmp);

    int m;
    int cur = 0;

    for (int t = k; t >= 1 ; --t) {
        if (t == k){
          m = n - (n / k) * (k - 1);
        } else{
            m = n / k;
        }

        vector<string> ans(m);
        ans[m / 2] = v[cur].name;

        int j = m / 2 - 1;
        for (int i = cur + 1; i < cur + m; i += 2) {
            ans[j--] = v[i].name;
        }

        j = m / 2 + 1;
        for (int i = cur + 2; i < cur + m; i += 2) {
            ans[j++] = v[i].name;
        }

        for (int i = 0; i < ans.size(); ++i) {
            if (i != 0)
                printf(" ");
            printf("%s", ans[i].c_str());
        }
        printf("\n");
        cur += m;
    }

    return 0;
}

 */

/*
int n, k;

struct Node{
    string name;
    int height;
};
vector<Node> v;

bool cmp(Node a, Node b){
    if (a.height != b.height)
        return a.height > b.height;
    else
        return a.name <= b.name;
}

int main(){
    scanf("%d%d", &n, &k);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].name;
        scanf("%d", &v[i].height);
    }

    sort(v.begin(), v.end(), cmp);

    int row = k, m, cur = 0;

    while (row){
        if (row == k){
            m = n - (n / k) * (k - 1);
        } else{
            m = n / k;
        }

        vector<string> ans(m);
        ans[m / 2] = v[cur].name;

        int j = m / 2 - 1;

        for (int i = cur + 1; i < cur + m; i += 2) {
            ans[j--] = v[i].name;
        }

        j = m / 2 + 1;
        for (int i = cur + 2; i < cur + m; i += 2) {
            ans[j++] = v[i].name;
        }

        for (int i = 0; i < ans.size(); ++i) {
            if (i != 0)
                printf(" ");
            printf("%s", ans[i].c_str());
        }

        printf("\n");
        row--;
        cur += m;
    }

    return 0;
}

 */


/*
int n, k;

struct Node{
    string name;
    int height;
};

bool cmp(Node a, Node b){
    if (a.height != b.height)
        return a.height > b.height;
    else
        return a.name <= b.name;
}

vector<Node> v;

int main(){
    scanf("%d%d", &n, &k);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].name;
        scanf("%d", &v[i].height);
    }

    sort(v.begin(), v.end(), cmp);

    int m, cur = 0;
    int row = k;

    while (row){
        if (row == k){
            m = n - (n / k) * (k - 1);
        } else{
            m = n / k;
        }

        vector<string> ans(m);
        ans[m / 2] = v[cur].name;

        // left
        int j = m / 2 - 1;
        for (int i = cur + 1; i < cur + m; i += 2) {
            ans[j--] = v[i].name;
        }

        j = m / 2 + 1;
        for (int i = cur + 2; i < cur + m; i += 2) {
            ans[j++] = v[i].name;
        }

        for (int i = 0; i < ans.size(); ++i) {
            if (i != 0)
                printf(" ");
            printf("%s", ans[i].c_str());
        }
        printf("\n");
        cur = cur + m;
        row--;
    }
    return 0;
}

 */


/*
int n, k;

struct Node{
    string name;
    int height;
};

bool cmp(Node a, Node b){
    if (a.height != b.height)
        return a.height > b.height;
    else
        return a.name < b.name;
}

vector<Node> v;

int main() {
    scanf("%d%d", &n, &k);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].name;
        scanf("%d", &v[i].height);
    }

    sort(v.begin(), v.end(), cmp);

    int t = 0, row = k;
    int m;

    while (row){
        if (row == k){
            m = n - (n / k) * (k - 1);
        } else{
            m = n / k;
        }

        vector<string> a(m);
        a[m / 2] = v[t].name;


        int j = m / 2 - 1;
        for (int i = t + 1; i < t + m; i += 2) {
            a[j--] = v[i].name;
        }

        j = m / 2 + 1;
        for (int i = t + 2; i < t + m; i += 2) {
            a[j++] = v[i].name;
        }

        for (int i = 0; i < a.size(); ++i) {
            if (i != 0)
                printf(" ");
            printf("%s", a[i].c_str());
        }
        printf("\n");
        t += m;
        row--;
    }


    return 0;
}

 */

/*
    int row = k;
    int m;
    int cur = 0;
    int t = 0;

    for (int i = row; i >= 1 ; --i) {
        if (i == k){
            m = n - (n / k) * (k - 1);
        } else{
            m = n / k;
        }

        vector<string> a(m);
        a[m / 2] = v[cur].name;

        int j = m / 2 - 1;
        for (int l = t + 1; l < t + m; i += 2) {
            a[j--] = v[i].name;
        }

        j = m / 2 + 1;
        for (int l = t + 2; l < t + m; i += 2) {
            a[j++] = v[i].name;
        }

        printf("%s", a.front().c_str());
        for (int l = 1; l < a.size(); ++l) {
            printf(" %s", a[i].c_str());
        }
        printf("\n");
        t += m;
    }

     */
