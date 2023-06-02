#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    long long sum = 0;
    double val;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &val);
        sum += (long long )(val * 1000) * i * (n - i + 1);
    }

    printf("%.2f", (double )sum / 1000);

    return 0;
}



/*
int n;

int main(){
    scanf("%d", &n);
    long long sum =  0;
    double val;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &val);
        sum += (long long)(val * 1000) * i * (n - i + 1);
    }

    printf("%.2f", (double )sum / 1000);

    return 0;
}

 */


/*
int n;

int main(){
    scanf("%d", &n);
    long long sum = 0;
    double val;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &val);
        sum += (long long)(val * 1000) * i * (n - i + 1);
    }

    printf("%.2f", sum / 1000.0);

    return 0;
}
 */

/*
int n;

int main(){
    scanf("%d", &n);
    long long sum = 0;
    double val;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &val);
        sum += (long long ) (val * 1000) * i * (n - i + 1);
    }

    printf("%.2f", sum / 1000.0);
    return 0;
}

 */

/*
int n;

int main(){
    scanf("%d", &n);
    long long sum = 0;
    double val;

    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &val);
        sum += (long long )(val * 1000) * i * (n - i + 1);
    }

    printf("%.2f", sum / 1000.0);
    return 0;
}

 */

/*
int n;

int main() {
    scanf("%d", &n);
    vector<double> v(n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &v[i]);
    }

    for (int i = 0; i < n; ++i) {
        double temp = v[i];
        sum += temp;
        for (int j = i + 1; j < n; ++j) {
            temp += v[j];
            sum += temp;
        }
    }

    printf("%.2f", sum);

    return 0;
}

 */