#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct e{
    int u, v;
};
vector<e> edge;

int number = 1;
const int MAXN = 2020;
int graph[MAXN][MAXN ] = {0};
bool visited[MAXN] = {false};
int weight[MAXN] = {0};
map<string, int> strToInt;
map<int, string> intToStr;
map<string, int> gang;
int n, k;
vector<int> father;

void init(){
    father.resize(MAXN);
    for (int i = 1; i < father.size(); ++i) {
        father[i] = i;
    }
}

int findFather(int x){
    int a = x;
    while (x != father[x]){
        x = father[x];
    }

    while (a != father[a]){
        int temp = a;
        a = father[a];
        father[temp] = x;
    }

    return x;
}

void Union(int a, int b){
    int fa = findFather(a), fb = findFather(b);
    if (fa != fb){
        if (weight[fa] > fb)
            father[fb] = fa;
        else
            father[fa] = fb;
    }
}

int getNumber(string s){
    if (strToInt.find(s) != strToInt.end()){
        return strToInt[s];
    } else{
        strToInt[s] = number;
        intToStr[number] = s;
        return number++;
    }
}

int main(){
    scanf("%d%d", &n, &k);
    init();
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        int len;
        cin >> s1 >> s2;
        scanf("%d", &len);

        int u = getNumber(s1), v = getNumber(s2);
        edge.push_back({u, v});
        graph[u][v] += len;
        graph[v][u] += len;
        weight[u] += len;
        weight[v] += len;
    }

    for (int i = 0; i < edge.size(); ++i) {
        int u = edge[i].u, v = edge[i].v;
        Union(u, v);
    }

    map<int, int> tree;
    set<int> ans;
    for (int i = 1; i < number; ++i) {
        ans.insert(findFather(i));
    }





    return 0;
}

/*
 #include <iostream>
#include "bits/stdc++.h"
using namespace std;
int number = 1;
const int MAXN = 2020;
int graph[MAXN][MAXN ] = {0};
bool visited[MAXN] = {false};
int weight[MAXN] = {0};
map<string, int> strToInt;
map<int, string> intToStr;
map<string, int> gang;
int n, k;

int getNumber(string s){
    if (strToInt.find(s) != strToInt.end()){
        return strToInt[s];
    } else{
        strToInt[s] = number;
        intToStr[number] = s;
        return number++;
    }
}

void dfs(int u, int &head, int &people, int &quan){
    visited[u] = true;
    if (weight[u] > weight[head])
        head = u;
    people++;

    for (int v = 1; v <= number - 1; ++v) {
        if (graph[u][v] > 0){
            quan += graph[u][v];
            graph[u][v] = graph[v][u] = 0;

            if (visited[v] == false)
                dfs(v, head, people, quan);
        }
    }
}

void dfsCnt(){
    for (int u = 1; u < number ; ++u) {
        if (visited[u] == false){
            int head = u, people = 0, quan = 0;
            dfs(u, head, people, quan);

            if (quan > k && people > 2)
                gang[intToStr[head]] = people;
        }
    }
}

int main(){
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        int len;
        cin >> s1 >> s2;
        scanf("%d", &len);

        int u = getNumber(s1), v = getNumber(s2);
        graph[u][v] += len;
        graph[v][u] += len;
        weight[u] += len;
        weight[v] += len;
    }

    dfsCnt();

    printf("%d\n", gang.size());;

    for (auto it = gang.begin(); it != gang.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    return 0;
}

 */




/*
const int MAXN = 2020;
int graph[MAXN][MAXN] = {0};
bool visited[MAXN] = {false};
int weight[MAXN] = {0};
int n, k;
int number;
map<int, string> intToStr;
map<string, int> strToInt;
map<string, int> gang;

int getNumber(string s){
    if (strToInt.find(s) != strToInt.end()){
        return strToInt[s];
    } else{
        strToInt[s] = number;
        intToStr[number] = s;
        return number++;
    }
}

void dfs(int cur, int &head, int &people, int &quan){
    visited[cur] = true;
    if (weight[cur] > weight[head])
        head = cur;
    people++;

    for (int v = 0; v < number; ++v) {
        if (graph[cur][v] > 0){
            quan += graph[cur][v];
            graph[cur][v] = graph[v][cur] = 0;

            if (visited[v] == false)
                dfs(v, head, people, quan);
        }
    }
}

void dfsCnt(){
    for (int u = 0; u < number; ++u) {
        if (visited[u] == false){
            int head = u, people = 0, quan = 0;
            dfs(u, head, people, quan);

            if (quan > k && people > 2)
                gang[intToStr[head]] = people;
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        string s1, s2;
        int len;
        cin >> s1 >> s2;
        scanf("%d", &len);
        int u = getNumber(s1), v = getNumber(s2);

        graph[u][v] += len;
        graph[v][u] += len;
        weight[u] += len;
        weight[v] += len;
    }

    dfsCnt();

    printf("%d\n", gang.size());

    for (auto it = gang.begin(); it != gang.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    return 0;
}


 */