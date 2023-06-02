#include <iostream>
#include "bits/stdc++.h"
using namespace std;
vector<int> table(100010);
int msize, n;

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
            table[index] = 1;
            printf("%d", index);
            return;
        }
    }

    printf("-");
}


int main(){
    scanf("%d%d", &msize, &n);
    while (!isPrime(msize))
        msize++;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        if (i != 0)
            printf(" ");
        insert(val);
    }
    return 0;
}


/*
int msize, n;
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
        int index = (val + (int)pow(i, 2)) % msize;
        if (table[index] == 0){
            table[index] = 1;
            printf("%d", index);
            return;
        }
    }

    printf("-");
}

int main(){
    scanf("%d%d", &msize, &n);
    while (!isPrime(msize))
        msize++;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        if (i != 0)
            printf(" ");
        insert(val);
    }

    return 0;
}

*/



/*
int msize, n;
vector<int> table(10010, 0);
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
        int index = (val + i * i) % msize;
        if (table[index] == 0){
            table[index] = 1;
            printf("%d", index % msize);
            return;
        }
    }
    printf("-");
}

int main(){
    scanf("%d%d", &msize, &n);
    while (!isPrime(msize))
        msize++;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        if (i != 0)
            printf(" ");
        insert(val);
    }

    return 0;
}
 */

/*
int msize, n;
int hashTable[10100];

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
        int cur = (val + i * i) % msize;
        if (hashTable[cur] == 0){
            hashTable[cur] = 1;
            printf("%d", cur % msize);
            return;
        }
    }

    printf("-");
}

int main() {
    scanf("%d%d", &msize, &n);

    while (!isPrime(msize))
        msize++;
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        if (i != 0)
            printf(" ");
        insert(val);
    }
    return 0;
}

 */
