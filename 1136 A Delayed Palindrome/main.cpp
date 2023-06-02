#include <iostream>
#include "bits/stdc++.h"
using namespace std;

string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

string  getSum(string s1, string s2){
    string  s = s1;
    int carry = 0;

    for (int i = s1.size() - 1; i >= 0 ; --i) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }

    if (carry > 0)
        s = "1" + s;
    return s;
}

int main(){
    string  s;
    cin >> s;

    if (s == rev(s)){
        printf("%s is a palindromic number.", s.c_str());
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        string sum = getSum(s, rev(s));
        printf("%s + %s = %s\n", s.c_str(), rev(s).c_str(), sum.c_str());
        if (sum == rev(sum)){
            printf("%s is a palindromic number.", sum.c_str());
            return 0;
        }

        s = sum;
    }

    printf("Not found in 10 iterations.");
    return 0;
}




/*
string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

string getSum(string s1, string s2){
    string s = s1;
    int carry = 0;

    for (int i = s1.size() - 1; i >= 0 ; --i) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }

    if (carry > 0)
        s = "1" + s;
    return s;
}

int main(){
    string s;
    cin >> s;

    if (s == rev(s)){
        printf("%s is a palindromic number.", s.c_str());
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        string sum = getSum(s, rev(s));
        printf("%s + %s = %s\n", s.c_str(), rev(s).c_str(), sum.c_str());
        if (sum == rev(sum)){
            printf("%s is a palindromic number.", sum.c_str());
            return 0;
        }

        s = sum;
    }

    printf("Not found in 10 iterations.");
    return 0;
}

 */

/*
string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

string getSum(string s1, string s2){
    string s = s1;
    int car = 0;
    for (int i = s1.size() - 1; i >= 0 ; --i) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + car) % 10 + '0';
        car = (s1[i] - '0' + s2[i] - '0' + car) / 10;
    }

    if (car > 0)
        s = "1" + s;
    return s;
}

int main(){
    string s;
    cin >> s;

    if (s == rev(s)){
        printf("%s is a palindromic number.", s.c_str());
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        string sum = getSum(s, rev(s));
        printf("%s + %s = %s\n", s.c_str(), rev(s).c_str(), sum.c_str());
        if (sum == rev(sum)){
            printf("%s is a palindromic number.", sum.c_str());
            return 0;
        }

        s = sum;
    }

    printf("Not found in 10 iterations.");
    return 0;
}

 */


/*
string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

string getSum(string s1, string s2){
    string s = s1;
    int car = 0;

    for (int i = s1.size() - 1; i >= 0 ; --i) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + car) % 10 + '0';
        car = (s1[i] - '0' + s2[i] - '0' + car) / 10;
    }

    if (car > 0)
        s = "1" + s;
    return s;
}

int main(){
    string s, sum;
    cin >> s;

    if (s == rev(s)){
        printf("%s is a palindromic number.", s.c_str());
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        sum = getSum(s, rev(s));
        printf("%s + %s = %s\n", s.c_str(), rev(s).c_str(), sum.c_str());

        if (sum == rev(sum)){
            printf("%s is a palindromic number.", sum.c_str());
            return 0;
        }

        s = sum;
    }

    printf("Not found in 10 iterations.");
    return 0;
}

 */


/*
string s;

bool judge(string s){
    if (s.size() == 1 || s.empty())
        return true;
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }

    return true;
}

int main(){
    cin >> s;
    if (judge(s)){
        printf("%s is a palindromic number.", s.c_str());
        return 0;
    }

    for (int i = 0; i < 10; ++i) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        string sum = to_string(stoi(s) + stoi(s2));
        printf("%s + %s = %s\n", s.c_str(), s2.c_str(), sum.c_str());
        if (judge(sum)){
            printf("%s is a palindromic number.\n", s.c_str());
            return 0;
        }
        s = sum;
    }

        printf("Not found in 10 iterations.");

    return 0;
}

 */

/*
    cin >> s;
    if (judge(s)){
        printf("%s is a palindromic number.", s.c_str());
        return 0;
    }

    for (int i = 0; i < 10 && !judge(s); ++i) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        printf("%s + %s = %s\n", s.c_str(), s2.c_str(), to_string(stoi(s) + stoi(s2)).c_str());
        s = to_string(stoi(s) + stoi(s2));
    }

    if (judge(s))
        printf("%s is a palindromic number.", s.c_str());
    else
        printf("Not found in 10 iterations.");
*/

/*
string s1;

bool judge(string s){
    if (s.size() == 1)
        return true;

    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }

    return true;
}

int main() {
    cin >> s1;
    int times = 0;

    if (judge(s1)){
        printf("%s is a palindromic number.\n", s1.c_str());
        return 0;
    }

    while (!judge(s1) && times < 10){
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        printf("%lld + %lld = %lld\n", stoll(s1), stoll(s2), stoll(s1) + stoll(s2));
        if (judge(to_string(stoll(s1) + stoll(s2)))){
            printf("%lld is a palindromic number.", stoll(s1) + stoll(s2));
            return 0;
        }

        times++;
        s1 = to_string(stoll(s1) + stoll(s2));
    }

    printf("Not found in 10 iterations.");
    return 0;
}


class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        if (s.empty() || s.size() == 1 || x == 0)
            return true;
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }

        return true;
    }
};

 */