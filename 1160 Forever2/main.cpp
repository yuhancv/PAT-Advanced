#include <iostream>
#include "bits/stdc++.h"
using namespace std;



int n;
int k, m;
bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i <= (int ) sqrt(n) ; ++i) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a);
}

int getSum(int n){
    int sum = 0;
    while (n > 0){
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

struct Node{
    int n, a;
};

vector<Node> ans;

bool cmp(Node a, Node b){
    if (a.n != b.n)
        return a.n < b.n;
    else
        return a.a < b.a;
}

void dfs(int sum, int val, int left, int target){
    if (left == 0 && sum == target){
        int n = getSum(val + 1), g = gcd(sum, n);
        if (g > 2 && isPrime(g))
            ans.push_back({n, val});
    } else if (left > 0){
        for (int i = 0; i <= 9; ++i) {
            if (sum )
        }
    }
}


int main(){
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        printf("Case %d\n", i);
        ans.clear();
        scanf("%d%d", &k, &m);


        
        
        

    }

    return 0;
}






/*
int n;
int k, m;

struct Node{
    int n, a;
};


int getSum(string s){
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
    }

    return sum;
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool cmp(Node a, Node b){
    if (a.n != b.n)
        return a.n < b.n;
    else
        return a.a < b.a;
}

bool isPrime(int n){
    if (n < 2)
        return false;
    for (int i = 2; i <= (int ) sqrt(n) ; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n ; ++i) {
        printf("Case %d\n", i);
        scanf("%d%d", &k, &m);
        vector<Node> ans;

        for (int j = (int ) pow(10, k - 1); j < (int ) pow(10, k); ++j) {
            string s1 = to_string(j);
            int sum1 = getSum(s1);
            if (sum1 != m)
                continue;

            string s2 = to_string(j + 1);
            int n = getSum(s2);
            int yue = gcd(m, n);
            if (isPrime(yue) && yue > 2)
                ans.push_back({n, j});
        }

        if (ans.empty()){
            printf("No Solution\n");
            continue;
        }

        sort(ans.begin(), ans.end(), cmp);

        for (int j = 0; j < ans.size(); ++j) {
            printf("%d %d\n", ans[j].n, ans[j].a);
        }
    }

    return 0;
}

 */
