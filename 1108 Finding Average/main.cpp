#include <iostream>
#include "bits/stdc++.h"
using namespace std;



/*
int n, cnt = 0;
double sum = 0;

bool judge(string s){
    int dian = 0, dian_number = 0, first = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s[i]))
            return false;

        if (s[i] == '.' && first == 0){
            first = 1;
            dian++;
            continue;
        }

        if (isdigit(s[i]) && first == 1)
            dian_number++;

        if (s[i] == '.' && first == 1)
            dian++;
    }

    if (dian > 1 || dian_number > 2 || stod(s) < -1000 || stod(s) > 1000)
        return false;
    return true;
}

int main(){
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        getchar();
        if (judge(s)){
            cnt++;
            sum += stod(s);
        } else
            printf("ERROR: %s is not a legal number\n", s.c_str());
    }

    if (cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);
    else
        printf("The average of %d numbers is %.2f", cnt, sum / cnt);

    return 0;
}

 */



/*
int n;
double sum = 0;
vector<double> v;

bool judge(string s){
    int first= 0;
    int dian = 0, c = 0, dian_number = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (isalpha(s[i])){
            return false;
        }

        if (s[i] == '.' && first == 0){
            dian++;
            first++;
            continue;
        }

        if (s[i] == '.' && first == 1){
            dian++;
        }

        if (isdigit(s[i]) && first == 1)
            dian_number++;
    }

    if (dian > 1 || dian_number > 2 || stod(s) < -1000 || stod(s) > 1000)
        return false;
    else
        return true;
}

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
       // getchar();

        if (judge(s)){
            sum += stod(s);
            cnt++;
        }else
            printf("ERROR: %s is not a legal number\n", s.c_str());
    }

    if (cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else if (cnt > 1)
        printf("The average of %d numbers is %.2f", cnt ,sum / cnt);
    else if (cnt == 1)
        printf("The average of 1 number is %.2f", sum);

    return 0;
}

 */
