#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int first1, first2, n;

struct Node{
    int address, val, next;
};

Node a[100010];
vector<Node> list1, list2;

int main(){
    scanf("%d%d%d", &first1, &first2, &n);

    for (int i = 0; i < n; ++i) {
        int address, val, next;
        scanf("%d%d%d", &address, &val, &next);
        a[address].address = address;
        a[address].val = val;
        a[address].next = next;
    }

    for (int i = first1; i != -1 ; i = a[i].next) {
        list1.push_back({i, a[i].val, a[i].next});
    }

    for (int i = first2; i != -1 ; i = a[i].next) {
        list2.push_back({i, a[i].val, a[i].next});
    }

    if (list1.size() < list2.size())
        swap(list1, list2);

    reverse(list2.begin(), list2.end());

    int cur = 2;
    for (int i = 0; i < list2.size(); ++i) {
        list1.insert(list1.begin() + cur, list2[i]);
        cur += 3;
    }

    for (int i = 0; i < list1.size() - 1; ++i) {
        printf("%05d %d %05d\n", list1[i].address, list1[i].val, list1[i + 1].address);
    }

    printf("%05d %d -1", list1.back().address, list1.back().val);

    return 0;
}




/*
int first1, first2, n;

struct Node{
    int address;
    int val;
    int next;
};

Node a[100010];

vector<Node> list1, list2;

int main() {
    scanf("%d%d%d", &first1, &first2, &n);

    for (int i = 0; i < n; ++i) {
        int address, val, next;
        scanf("%d%d%d", &address, &val, &next);
        a[address].address = address;
        a[address].val = val;
        a[address].next = next;
    }

    for (int i = first1; i != -1 ; i = a[i].next) {
        list1.push_back({i, a[i].val, a[i].next});
    }

    for (int i = first2; i != -1 ; i = a[i].next) {
        list2.push_back({i, a[i].val, a[i].next});
    }

    if (list1.size() < list2.size())
        swap(list1, list2);

    reverse(list2.begin(), list2.end());

    int cur = 2;
    for (int i = 0; i < list2.size(); ++i) {
        list1.insert(list1.begin() + cur, list2[i]);
        cur += 3;
    }

    for (int i = 0; i < list1.size() - 1; ++i) {
        printf("%05d %d %05d\n", list1[i].address, list1[i].val, list1[i + 1].address);
    }

    printf("%05d %d -1", list1.back().address, list1.back().val);
    return 0;
}

 */
