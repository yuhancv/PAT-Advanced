#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n;

bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i <= (int ) sqrt(n) ; ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main(){
    scanf("%d", &n);

    if (isPrime(n) && isPrime(n - 6))
        printf("Yes\n%d", n - 6);
    else if (isPrime(n) && isPrime(n + 6))
        printf("Yes\n%d", n + 6);
    else{
        int cur;
        for (cur = n + 1;; ++cur) {
            if (isPrime(cur) && isPrime(cur - 6))
                break;
            if (isPrime(cur) && isPrime(cur + 6))
                break;
        }

        printf("No\n%d", cur);
    }
    return 0;
}

/*
int n;

bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i <= (int ) sqrt(n) ; ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main(){
    scanf("%d", &n);

    if (isPrime(n) && isPrime(n - 6))
        printf("Yes\n%d", n - 6);
    else if (isPrime(n) && isPrime(n + 6))
        printf("Yes\n%d", n + 6);
    else{
        int cur;
        for (cur = n + 1;; ++cur) {
            if (isPrime(cur) && isPrime(cur - 6))
                break;
            if (isPrime(cur) && isPrime(cur + 6))
                break;
        }

        printf("No\n%d", cur);
    }
    return 0;
}

 */

/*
int n;

bool isPrime(int n){

    if (n < 2)
        return false;
    for (int i = 2; i  <= (int )sqrt(n) ; i++) {
        if (n % i == 0)
            return false;
    }
    return true;



    if (n< 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;



}

int main() {
    scanf("%d", &n);

    if (isPrime(n) && isPrime(n - 6))
        printf("Yes\n%d", n - 6);
    else if (isPrime(n) && isPrime(n + 6))
        printf("Yes\n%d", n + 6);
    else{
        int cur = n + 1;
        while (true){
            if (isPrime(cur) && isPrime(cur - 6))
                break;
            if (isPrime(cur) && isPrime(cur + 6))
                break;
            cur++;
        }
        printf("No\n%d", cur);
    }

    return 0;
}

 */

/*
scanf("%d", &n);

if ((isPrime(n) && isPrime(n - 6)) || (isPrime(n) && isPrime(n + 6))){
    printf("Yes\n");
    vector<int> ans;
    if (isPrime(n - 6))
        ans.push_back(n - 6);
    if (isPrime(n + 6))
        ans.push_back(n + 6);
    sort(ans.begin(), ans.end());
    printf("%d", ans.front());
    return 0;
}

printf("No\n");
int i = n + 1;

while (true){
    if ((isPrime(i) && isPrime(i - 6)) || (isPrime(i) && isPrime(i + 6)))
        break;
    i++;
}
printf("%d", i);

 */