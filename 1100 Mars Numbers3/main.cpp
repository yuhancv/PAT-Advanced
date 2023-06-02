#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int len = 0, first = 0;
    int maxn = (int ) sqrt(n) + 1;

    for (int i = 2; i <= maxn; ++i) {
        int cur;
        int temp = 1;

        for (cur = i; cur <= maxn && n % (temp *= cur) == 0; ++cur) {
            ;
        }

        if (cur - i > len){
            len = cur - i;
            first = i;
        }
    }

    if (first == 0)
        printf("1\n%d", n);
    else{
        printf("%d\n", len);
        for (int i = 0; i < len; ++i) {
            if (i != 0)
                printf("*");
            printf("%d", first + i);
        }
    }

    return 0;
}






/*
int main(){
    int n;
    scanf("%d", &n);

    int first = 0, len = 0;
    int maxn = (int ) sqrt(n) + 1;

    for (int i = 2; i <= maxn; ++i) {
        int cur;
        int temp = 1;

        for (cur = i; cur <= maxn ; ++cur) {
            temp *= cur;
            if (n % temp != 0)
                break;
        }

        if (cur - i > len){
            len = cur - i;
            first = i;
        }
    }

    if (first == 0)
        printf("1\n%d", n);
    else{
        printf("%d\n", len);
        for (int i = 0; i < len; ++i) {
            if (i != 0)
                printf("*");
            printf("%d", first + i);
        }
    }

    return 0;
}

 */











/*
int n;

int main(){
    int first = 0;

    scanf("%d", &n);
    int maxn = (int ) sqrt(n) + 1;
    int len = 0;

    for (int i = 2; i <= maxn ; ++i) {
        int cur;
        int temp = 1;

        for (cur = i; cur <= maxn; ++cur) {
            temp *= cur;
            if (n % temp != 0)
                break;
        }

        if (cur - i > len){
            len = cur - i;
            first = i;
        }
    }

    if (first == 0)
        printf("1\n%d", n);
    else{
        printf("%d\n", len);
        for (int i = 0; i < len; ++i) {
            if (i != 0)
                printf("*");
            printf("%d", first + i);
        }
    }
    return 0;
}

 */



/*
int n;

int main(){
    scanf("%d", &n);
    int first = 0;
    int temp;
    int len = 0;

    for (int i = 2; i < (int ) sqrt(n) + 1; ++i) {
        int j;
        temp = 1;

        for (j = i; j <= (int ) sqrt(n) + 1 ; ++j) {
            temp *= j;
            if (n % temp != 0)
                break;
        }

        if (j - i > len){
            len = j - i;
            first = i;
        }
    }

    if (first == 0)
        printf("1\n%d", n);
    else{
        printf("%d\n", len);
        for (int i = 0; i < len; ++i) {
            if (i != 0)
                printf("*");
            printf("%d", first + i);
        }
    }
    return 0;
}

 */

/*
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
                "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
                "elo", "syy", "lok", "mer", "jou"};

string s;
int n;

void func1(int n){
    if (n / 13)
        printf("%s", b[n / 13].c_str());
    if (n / 13 && n % 13)
        printf(" ");
    if (n % 13 || n == 0)
        printf("%s", a[n % 13].c_str());
    printf("\n");
}

void func2(string s){
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (s.size() > 4)
        s2 = s.substr(4, 3);

    for (int i = 1; i <= 12; ++i) {
        if (s1 == a[i] || s2 == a[i])
            t2 = i;
        if (s1 == b[i])
            t1 = i;
    }

    printf("%d\n", t1 * 13 + t2);
}

int main(){
    scanf("%d", &n);
    getchar();

    while (n--){
        s.clear();
        getline(cin, s);
        if (isdigit(s.front()))
            func1(stoi(s));
        else
            func2(s);
    }

    return 0;
}

 */



/*
string s;

void func1(int n){
    if (n / 13 != 0)
        printf("%s", b[n / 13].c_str());
    if (n / 13 && n % 13)
        printf(" ");
    if (n % 13 || n == 0)
        printf("%s", a[n % 13].c_str());
    printf("\n");
}

void func2(string s){
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (s.size() > 4)
        s2 = s.substr(4, 3);
    for (int i = 1; i <= 12; ++i) {
        if (s1 == a[i] || s2 == a[i])
            t2 = i;
        if (s1 == b[i])
            t1 = i;
    }

    printf("%d\n", t1 * 13 + t2);
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    while (n--){
        string s;
        getline(cin, s);
        if (isdigit(s.front()))
            func1(stoi(s));
        else
            func2(s);
    }

    return 0;
}

 */

















/*
string s;
int len;
void func1(int t) {
    if (t / 13) cout << b[t / 13];
    if ((t / 13) && (t % 13)) cout << " ";
    if (t % 13 || t == 0) cout << a[t % 13];
}
void func2() {
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (len > 4) s2 = s.substr(4, 3);
    for (int j = 1; j <= 12; j++) {
        if (s1 == a[j] || s2 == a[j]) t2 = j;
        if (s1 == b[j]) t1 = j;
    }
    cout << t1 * 13 + t2;
}
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        len = s.length();
        if (s[0] >= '0' && s[0] <= '9')
            func1(stoi(s));
        else
            func2();
        cout << endl;
    }
    return 0;
}

 */

/*
int n;
string s;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
                "aug", "sep", "oct", "nov", "dec"};

string b[13] = {"0000", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
                "elo", "syy", "lok", "mer", "jou"};

void func1(int t){
    if (t / 13)
        printf("%s", b[t / 13].c_str());
    if ((t / 13) && (t % 13))
        printf(" ");
    if (t % 13 || t == 0)
        printf("%s", a[t % 13].c_str());
}

void func2(string s){
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if (s.size() > 4)
        s2 = s.substr(4, 3);

    for (int i = 1; i <= 12; ++i) {

    }
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        if (isdigit(s.front()))
            func1(stoi(s));
        else
            func2(s);
        printf("\n");
    }
    return 0;
}

 */