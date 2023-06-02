#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n, m;
unordered_set<string> stu;
vector<string> a, b;

bool cmp(string a, string b){
    return a.substr(6, 8) < b.substr(6, 8);
}

int main(){
    scanf("%d", &n);
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        stu.insert(s);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        cin >> s;
        b.push_back(s);
    }

    for (int i = 0; i < b.size(); ++i) {
        if (stu.find(b[i]) != stu.end()){
            a.push_back(b[i]);
        }
    }

    printf("%d\n", a.size());

    if (!a.empty()){
        sort(a.begin(), a.end(), cmp);
        printf("%s", a.front().c_str());
    } else{
        sort(b.begin(), b.end(), cmp);
        printf("%s", b.front().c_str());
    }

    return 0;
}


/*
int n, m;
unordered_set<string> stu;
vector<string> v;
vector<string> a;

bool cmp(string a, string b){
    return a.substr(7, 8) < b.substr(7, 8);
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        stu.insert(s);
    }

    int cnt = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        if (stu.find(s) != stu.end()){
            cnt++;
            a.push_back(s);
        }
    }

    if (cnt == 0){
        printf("0\n");
        sort(v.begin(), v.end(), cmp);
        printf("%s", v.front().c_str());
    } else{
        printf("%d\n", cnt);
        sort(a.begin(), a.end(), cmp);
        printf("%s", a.front().c_str());
    }

    return 0;
}

 */