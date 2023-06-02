#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

void judge(string s){
    string s1= s.substr(0, s.size() / 2), s2 = s.substr(s.size() / 2, s.size() / 2);
    int n1 = stoi(s1), n2 = stoi(s2);
    if (n1 != 0 && n2 != 0 && stoi(s) % (n1 * n2) == 0)
        printf("Yes\n");
    else
        printf("No\n");
}

int main(){
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        judge(s);
    }

    return 0;
}

/*
int n;

void judge(string s){
    string s1 = s.substr(0, s.size() / 2), s2 = s.substr(s.size() / 2, s.size() / 2);
    int n1 = stoi(s1), n2 = stoi(s2);

    if (n1 != 0 && n2 != 0 && stoi(s) % (n1 * n2) == 0)
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        judge(s);
    }

    return 0;
}

 */
