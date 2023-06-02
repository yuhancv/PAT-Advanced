#include <iostream>
#include "bits/stdc++.h"
using namespace std;

map<char, vector<string>> tree;
int graph[510][510] = {'\0'};

int main(){
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 7; ++j) {
            string s;
            cin >> s;
            getchar();
            tree['A' + i].push_back(s);
        }
    }

    string s;
    getline(cin, s);

    for (auto it = tree.begin(); it != tree.end(); it++) {
        char cur = it->first;
        if (!isalpha(cur))
    }




    return 0;
}




/*
char a[26][7][5] = {'\0'}, out[7][100];

int main() {

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 5; ++k) {
                scanf("%c", &a[i][j][k]);
            }
            getchar();
        }
    }

    string s;
    getline(cin, s);

    for (int i = 0, j, flag = 0; i < s.size(); i++) {
        j = i;
        while (j < s.size() && s[j] >= 'A' && s[j] <= 'Z') j++;
        if (i == j) continue;
        for (int k = i; k < j; k++)
            for (int l = 0; l < 7; l++)
                for (int m = 0; m < 5; m++)
                    out[l][m + (k - i) * 6] = a[s[k] - 'A'][l][m];
        if (flag) cout << '\n';
        for (int k = 0; k < 7; k++) {
            flag = 1;
            for (int l = 0; l < 6 * (j - i) - 1; l++) cout << out[k][l];
            cout << '\n';
        }
        i = j;
    }

    return 0;
}
 */


/*
    printf("\n");

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 5; ++k) {
                printf("%c", a[i][j][k]);
            }
            printf("\n");
        }
    }
     */