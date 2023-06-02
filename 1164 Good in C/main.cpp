#include <iostream>
#include "bits/stdc++.h"
using namespace std;

map<char, vector<string>> tree;

int main(){
    string s;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 7; ++j) {
            cin >> s;
            tree['A' + i].push_back(s);
        }
   }

    getchar();
    getline(cin, s);

    vector<string> ans;
    for (int i = 0; i < s.size(); ++i) {

    }

    /*
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < tree[s[i]].size(); ++j) {
            cout << tree[s[i]][j] << endl;
        }
        printf("\t");
    }
     */


    return 0;
}

/*
struct ch{
    char a[7][5];
};
vector<ch> v(26);
map<char, ch> tree;

int main() {
    char a[7][5] = {0};

    for (int times = 0; times < 26; ++times) {
        ch c;
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 5; ++j) {
                //scanf("%c", &c.a[i][j]);
                cin >> c.a[i][j];
            }
        }

        tree['A' + times] = c;
    }

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i]) && isalpha(s[i])){
            for (int i = 0; i < 7; ++i) {
                for (int j = 0; j < 5; ++j) {
                    printf("%c", tree[s[i]].a[i][j]);
                }
                printf("\n");
            }
        } else
            printf("\n");

    }








    return 0;
}

 */


/*
   for (auto it = tree.begin(); it != tree.end(); it++) {
       for (int i = 0; i < 7; ++i) {
           for (int j = 0; j < 5; ++j) {
               printf("%c", it->second.a[i][j]);
           }
           printf("\n");
       }
   }
    */