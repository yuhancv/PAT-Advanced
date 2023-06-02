#include <iostream>
#include "bits/stdc++.h"
using namespace std;

string s;

int main(){
    cin >> s;
    int res = 0, cntt = 0, cntp = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'T')
            cntt++;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'P')
            cntp++;
        if (s[i] == 'T')
            cntt--;
        if (s[i] == 'A'){
            res = (res + cntt * cntp % 1000000007) % 1000000007;
        }
    }

    printf("%d", res);

    return 0;
}

/*
string s;

int main(){
    cin >> s;
    int res = 0, cntp = 0, cntt = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'T')
            cntt++;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'P')
            cntp++;
        if (s[i] == 'T')
            cntt--;
        if (s[i] == 'A'){
            res += (cntt * cntp) % 1000000007;
            res %= 1000000007;
        }
    }

    printf("%d", res);
    return 0;
}

 */

/*
string s;

int main(){
    cin >> s;
    int cntp = 0, cntt = 0;
    int res = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'T')
            cntt++;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'P')
            cntp++;
        if (s[i] == 'T')
            cntt--;
        if (s[i] == 'A'){
            res += (cntt * cntp) % 1000000007;
            res %= 1000000007;
        }
    }

    printf("%d", res);
    return 0;
}

 */

/*
string s;

int main() {
    cin >> s;
    int cnt = 0;

    for (int i = 0; i < s.size(); ++i) {
        int cur1 = -1, cur2 = -1, cur3 = -1;
        bool flag = true;
        if (s[i] == 'P'){
            cur1 = i;
            for (int j = i + 1; j < s.size(); ++j) {
                if (s[j] == 'A'){
                    cur2 = j;
                    for (int k = j + 1; k < s.size(); ++k) {
                        if (s[k] == 'T'){
                            cur3 = k;
                            if (cur1 != -1 && cur2 != -1 && cur3 != -1){
                                cnt++;
                                flag = false;
                                break;
                            }
                        }
                    }

                    if (!flag)
                        break;
                }
            }
        }
    }

    printf("%d", cnt);

    return 0;
}

 */
