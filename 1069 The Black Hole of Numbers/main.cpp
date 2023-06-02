#include <iostream>
#include "bits/stdc++.h"
using namespace std;

string s;

int main(){
    cin >> s;
    s.insert(0, 4 - s.size(), '0');

    do {
        string a = s, b = s;
        sort(a.begin(), a.end(), greater<int> ());
        sort(b.begin(), b.end());
        int res = stoi(a) - stoi(b);
        s = to_string(res);
        s.insert(0, 4 - s.size(), '0');
        printf("%s - %s = %s\n", a.c_str(), b.c_str(), s.c_str());
    } while (s != "0000" && s != "6174");
    return 0;
}


/*
string s;

int main(){
    cin >> s;
    int n = s.size();

    if (n < 4){
        for (int i = 0; i < 4 - n; ++i) {
            s.insert(0, "0");
        }
    }


    do {
        string a = s, b = s;
        sort(a.begin(), a.end(), greater<char> ());
        sort(b.begin(), b.end(), less<int> ());
        int res = stoi(a) - stoi(b);
        s = to_string(res);
        s.insert(0, 4 - s.size(), '0');
        printf("%s - %s = %s\n", a.c_str(), b.c_str(), s.c_str());

    } while (s != "0000" && s != "6174");

    return 0;
}
 */

/*
string s;

bool cmp(char a, char b){
    return a >= b;
}

int main() {
    cin >> s;
    s.insert(0, 4 - s.size(), '0');

    do {
        string s1 = s, s2 = s;
        sort(s1.begin(), s1.end(), greater<char>());
        sort(s2.begin(), s2.end());

        int res = stoi(s1) - stoi(s2);
        s = to_string(res);
        s.insert(0, 4 - s.size(), '0');
        printf("%s - %s = %s\n", s1.c_str(), s2.c_str(), s.c_str());
    } while (s != "0000" && s != "6174");

    return 0;
}

 */
