#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int msize, n, m;
vector<int> table(100010);

bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i <= (int) sqrt(n) ; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void insert(int val){
    for (int i = 0; i < msize; ++i) {
        int index = (val + (int ) pow(i, 2)) % msize;
        if (table[index] == 0){
            table[index] = val;
            return;
        }
    }

    printf("%d cannot be inserted.\n", val);
}

int search(int val){
    int sum = 0;
    for (int i = 0; i < msize; ++i) {
        int index = (val + (int ) pow(i, 2)) % msize;
        sum++;

        if (table[index] == val)
            return sum;
        else if (table[index] == 0)
            return sum;
        else if (table[index] > 0)
            continue;
    }

    return sum + 1;
}

int main(){
    scanf("%d%d%d", &msize, &n, &m);
    while (!isPrime(msize))
        msize++;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        insert(val);
    }

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int val;
        scanf("%d", &val);
        sum += search(val);
    }

    printf("%.1f", (double )sum / m);
    return 0;
}






/*
int msize, n, m;
vector<int> table(100010);
bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i <= (int ) sqrt(n) ; ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void insert(int val){
    for (int i = 0; i < msize; ++i) {
        int index = (val + (int ) pow(i, 2)) % msize;
        if (table[index] == 0){
            table[index] = val;
            return;
        }
    }

    printf("%d cannot be inserted.\n", val);
}

int search(int val){
    int sum = 0;
    for (int i = 0; i < msize; ++i) {
        int index = (val + (int)pow(i, 2)) % msize;
        sum++;

        if (table[index] == val)
            return sum;
        else if (table[index] > 0)
            continue;
        else if (table[index] == 0)
            return sum;
    }

    return sum + 1;
}


int main(){
    scanf("%d%d%d", &msize, &n, &m);

    while (!isPrime(msize))
        msize++;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        insert(val);
    }

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int val;
        scanf("%d", &val);
        sum += search(val);
    }

    printf("%.1f", (double )sum / m);

    return 0;
}

 */


/*
int msize, n, m;
vector<int> table(100010);

bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i <= (int ) sqrt(n) ; ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

void insert(int val){
    for (int i = 0; i < msize; ++i) {
        int index = (val + (int ) pow(i, 2)) % msize;
        if (table[index] == 0){
            table[index] = val;
            return;
        }
    }

    printf("%d cannot be inserted.\n", val);
}

int search(int val){
    int times = 0;
    for (int i = 0; i <= msize; ++i) {
        times++;
        int index = (val + (int ) pow(i, 2)) % msize;
        if (table[index] == val){
            return times;
        } else if (table[index] == 0)
            break;
    }

    return times;
}

int main() {
    scanf("%d%d%d", &msize, &n, &m);
    while (!isPrime(msize))
        msize++;


    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        insert(val);
    }

    int sum = 0;

    for (int i = 0; i < m; ++i) {
        int val;
        scanf("%d", &val);
        sum += search(val);
    }

    printf("%.1f", (double )sum / m);
    return 0;
}

 */
