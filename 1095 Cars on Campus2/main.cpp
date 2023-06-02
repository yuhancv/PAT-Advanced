#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, k;

struct Node{
    string id;
    int time, flag = 0;
};

bool cmp1(Node a, Node b){
    if (a.id != b.id)
        return a.id < b.id;
    else
        return a.time < b.time;
}

vector<Node> v;

int main(){
    scanf("%d%d", &n, &k);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        int h, m, s;
        string temp;
        cin >> v[i].id;
        scanf("%d:%d:%d", &h, &m, &s);
        v[i].time = h * 3600 + m * 60 + s;
        cin >> temp;

        if (temp == "in")
            v[i].flag = 1;
        else
            v[i].flag = -1;
    }

    sort(v.begin(), v.end(), cmp1);
    vector<Node> car;

    for (int i = 0; i < n - 1; ++i) {

    }



    return 0;
}


/*
int n, k;
int maxTime = 0, tempIndex = 0;

struct Node{
    string id;
    int time, flag = 0;
};

bool cmp1(Node a, Node b){
    if (a.id != b.id)
        return a.id < b.id;
    else
        return a.time < b.time;
}

bool cmp2(Node a, Node b){
    return a.time < b.time;
}

map<string, int> tree;

int main(){
    scanf("%d%d", &n, &k);
    vector<Node> v(n);
    vector<Node> car;

    for (int i = 0; i < n; ++i) {
        string temp;
        int h, m, s;
        cin >> v[i].id;
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> temp;
        v[i].time += h * 60 * 60 + m * 60 + s;
        if (temp == "in")
            v[i].flag = 1;
        else
            v[i].flag = -1;
    }

    sort(v.begin(), v.end(), cmp1);

    for (int i = 0; i < n - 1; ++i) {
        if (v[i].id == v[i + 1].id && v[i].flag == 1 && v[i + 1].flag == -1){
            car.push_back(v[i]);
            car.push_back(v[i + 1]);
            tree[v[i].id] += (v[i + 1].time - v[i].time);
            if (tree[v[i].id] > maxTime)
                maxTime = tree[v[i].id];
        }
    }

    sort(car.begin(), car.end(), cmp2);

    vector<int> cnt(n);

    for (int i = 0; i < car.size(); ++i) {
        if (i == 0)
            cnt[i] += car[i].flag;
        else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }

    while (k--){
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int tempTime = h * 3600 + m * 60 + s;
        int i;

        for (i = tempIndex; i < car.size(); ++i) {
            if (car[i].time > tempTime){
                printf("%d\n", cnt[i - 1]);
                break;
            } else if (i == car.size() - 1)
                printf("%d\n", cnt[i]);
        }

        tempIndex = i;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second == maxTime)
            printf("%s ", it->first.c_str());
    }

    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
    return 0;
}

 */

/*
int n, k;
int maxTime = 0, tempIndex = 0;

struct Node{
    string id;
    int time, flag = 0;
};

map<string, int> tree;
vector<Node> v;

bool cmp1(Node a, Node b){
    if (a.id != b.id)
        return a.id < b.id;
    else
        return a.time < b.time;
}

bool cmp2(Node a, Node b){
    return a.time < b.time;
}

int main(){
    scanf("%d%d", &n, &k);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        int h, m, s;
        string temp;
        cin >> v[i].id;
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> temp;
        v[i].time += h * 60 * 60 + m * 60 + s;
        if (temp == "in")
            v[i].flag = 1;
        else
            v[i].flag = -1;
    }

    sort(v.begin(), v.end(), cmp1);
    vector<Node> car;

    for (int i = 0; i < n - 1; ++i) {
        if (v[i].id == v[i + 1].id && v[i].flag == 1 && v[i + 1].flag == -1){
            car.push_back(v[i]);
            car.push_back(v[i + 1]);
            tree[v[i].id] += (v[i + 1].time - v[i].time);
            if (tree[v[i].id] > maxTime)
                maxTime = tree[v[i].id];
        }
    }

    sort(car.begin(), car.end(), cmp2);

    vector<int> cnt(n);

    for (int i = 0; i < car.size(); ++i) {
        if (i == 0)
            cnt[i] += car[i].flag;
        else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }

    for (int i = 0; i < k; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temptime = h * 3600 + m * 60 + s;
        int j;

        for (j = tempIndex; j < car.size(); ++j) {
            if (car[j].time > temptime){
                printf("%d\n", cnt[j - 1]);
                break;
            } else if (j == car.size() - 1){
                printf("%d\n", cnt[j]);
            }

        }

        tempIndex = j;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second == maxTime)
            printf("%s ", it->first.c_str());
    }

    printf("%02d:%02d:%02d", maxTime / 3600, (maxTime % 3600) / 60, maxTime %
                                                                    60);
    return 0;
}

 */

/*
int n, k;

struct Node{
    string id;
    int time, flag = 0;
};

bool cmp(Node a, Node b){
    if (a.id != b.id)
        return a.id < b.id;
    else
        return a.time < b.time;
}

bool cmp2(Node a, Node b){
    return a.time < b.time;
}

map<string, int> tree;

int main() {
    scanf("%d%d", &n, &k);
    vector<Node> v(n);
    int maxTime = -1, tempIndex = 0;

    for (int i = 0; i < n; ++i) {
        string temp;
        int h, m, s;
        cin >> v[i].id;
        scanf("%d:%d:%d", &h, &m, &s);
        cin >> temp;
        int temptime =  h * 3600 + m * 60 + s;
        v[i].time = temptime;
        if (temp == "in")
            v[i].flag = 1;
        else
            v[i].flag = -1;
    }

    sort(v.begin(), v.end(), cmp);
    vector<Node> car;

    for (int i = 0; i < n - 1; ++i) {
        if (v[i].id == v[i + 1].id && v[i].flag == 1 && v[i + 1].flag == -1){
            car.push_back(v[i]);
            car.push_back(v[i + 1]);
            tree[v[i].id] += (v[i + 1].time - v[i].time);
            if (tree[v[i].id] > maxTime){
                maxTime = tree[v[i].id];
            }
        }
    }

    sort(car.begin(), car.end(), cmp2);

    vector<int> cnt(n);

    for (int i = 0; i < car.size(); ++i) {
        if (i == 0)
            cnt[i] += car[i].flag;
        else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }

    for (int i = 0; i < k; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temptime = h * 3600 + m * 60 + s;
        int j;

        for (j = tempIndex; j < car.size(); ++j) {
            if (car[j].time > temptime){
                printf("%d\n", cnt[j - 1]);
                break;
            } else if (j == car.size() - 1){
                printf("%d\n", cnt[j]);
            }

        }

        tempIndex = j;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second == maxTime)
            printf("%s ", it->first.c_str());
    }

    printf("%02d:%02d:%02d", maxTime / 3600, (maxTime % 3600) / 60, maxTime %
                                                                    60);
    return 0;
}

 */


