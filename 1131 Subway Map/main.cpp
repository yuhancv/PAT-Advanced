#include "bits/stdc++.h"
using namespace std;
const int MAXN = 10000;
int n;
int s, d;
vector<vector<int>> graph(MAXN);
unordered_map<int, int> line;
bool visited[MAXN] = {false};
vector<int> ans, temp;
int minCnt = INT_MAX, minTran = INT_MAX;

int getCnt(vector<int> &temp){
    int cnt = 0;
    int pre = line[temp[0] * MAXN + temp[1]];

    for (int i = 1; i < temp.size() - 1; ++i) {
        int u = temp[i], v = temp[i + 1];
        int now = line[u * MAXN + v];
        if (now != pre)
            cnt++;
        pre = now;
    }

    return cnt;
}

void dfs(int u){
    if (u == d){
        temp.push_back(u);
        visited[u] = true;
        int nowCnt = temp.size() - 1, nowTran = getCnt(temp);

        if (nowCnt < minCnt || (nowCnt == minCnt && nowTran < minTran)){
            minCnt = nowCnt;
            minTran = nowTran;
            ans = temp;
        }

        temp.pop_back();
        visited[u] = false;
    }

    temp.push_back(u);
    visited[u] = true;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (!visited[v])
            dfs(v);
    }
    temp.pop_back();
    visited[u] = false;
}

int main(){
    scanf("%d", &n);

    for (int i = 1; i <= n ; ++i) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);

        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[j]);
        }

        for (int j = 0; j < m - 1; ++j) {
            int u = a[j], v = a[j + 1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            line[u * MAXN + v] = line[v * MAXN + u] = i;
        }
    }

    int k;
    scanf("%d", &k);

    while (k--){
        scanf("%d%d", &s, &d);
        ans.clear(); temp.clear();
        fill(visited, visited + MAXN, false);
        minCnt = INT_MAX, minTran = INT_MAX;
        dfs(s);
        printf("%d\n", minCnt);

        int cur = s, pre = 0;

        for (int i = 1; i < ans.size(); ++i) {
            int now = line[ans[i - 1] * MAXN + ans[i]];
            if (now != pre){
                if (pre != 0)
                    printf("Take Line#%d from %04d to %04d.\n", pre, cur, ans[i - 1]);
                pre = now;
                cur = ans[i - 1];
            }
        }

        printf("Take Line#%d from %04d to %04d.\n", pre, cur, d);
    }

    return 0;
}



/*
const int MAXN = 10000;
int n;
vector<vector<int>> graph(MAXN);
unordered_map<int, int> line;
bool visited[MAXN] = {false};
int s, d;
vector<int> ans, temp;
int minCnt = INT_MAX, minTran = INT_MAX;

int getTran(vector<int> &a){
    int cnt = 0;
    int pre = line[a[0] * MAXN + a[1]];

    for (int i = 1; i < a.size() - 1; ++i) {
        if (line[a[i] * MAXN + a[i + 1] != pre]){
            cnt++;
        }

        pre = line[a[i] * MAXN + a[i + 1]];
    }

    return cnt;
}

void dfs(int u){
    if (u == d){
        temp.push_back(u);
        visited[u] = true;
        int nowCnt = temp.size() - 1, nowTran = getTran(temp);

        if (nowCnt < minCnt || (nowCnt == minCnt && nowTran < minTran)){
            minCnt = nowCnt;
            minTran = nowTran;
            ans = temp;
        }

        visited[u] = false;
        temp.pop_back();
        return;
    }

    temp.push_back(u);
    visited[u] = true;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (!visited[v])
            dfs(v);
    }

    temp.pop_back();
    visited[u] = false;
}

int main(){
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);

        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[j]);
        }

        for (int j = 0; j < a.size() - 1; ++j) {
            int u = a[j], v = a[j + 1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            line[u * MAXN + v] = line[v * MAXN + u] = i;
        }

        int k;
        scanf("%d", &k);

        while (k--){
            scanf("%d%d", &s, &d);
            ans.clear(); temp.clear();
            minCnt = INT_MAX, minTran = INT_MAX;
            fill(visited, visited + MAXN, false);
            dfs(s);
            printf("%d\n", minCnt);
        }

    }


    return 0;
}

 */

/*
const int MAXN = 10000;
int n;
int s, d;
vector<vector<int>> graph(MAXN);
unordered_map<int, int> line;
vector<int> ans, temp;
bool visited[MAXN] = {false};
int minCnt = INT_MAX, minTran = INT_MAX;

int getTran(vector<int> &temp){
    int cnt = 0;
    int pre = line[temp[0] * MAXN + temp[1]];
    for (int i = 0; i < temp.size() - 1; ++i) {
        int u  = temp[i], v = temp[i + 1];
        if (line[u * MAXN + v] != pre)
            cnt++;
        pre = line[u * MAXN + v];
    }

    return cnt;
}

void dfs(int u){
    if (u == d){
        visited[u] = true;
        temp.push_back(u);
        int nowCnt = temp.size() - 1, nowTran = getTran(temp);

        if (nowCnt < minCnt){
            minCnt = nowCnt;
            minTran = nowTran;
            ans = temp;
        } else if (nowCnt == minCnt && nowTran < minTran){
            minTran = nowTran;
            ans = temp;
        }

        temp.pop_back();
        visited[u] = false;
        return;
    }


    temp.push_back(u);
    visited[u] = true;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (!visited[v])
            dfs(v);
    }

    temp.pop_back();
    visited[u] = false;
}

int main(){
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);

        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[j]);
        }

        for (int j = 0; j < a.size() - 1; ++j) {
            int u = a[j], v = a[j + 1];
            line[u * MAXN + v] = line[v * MAXN + u] = i;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    int k;
    scanf("%d", &k);

    while (k--){
        scanf("%d%d", &s, &d);
        ans.clear();
        temp.clear();
        minCnt = INT_MAX, minTran = INT_MAX;
        fill(visited, visited + MAXN, false);

        dfs(s);
        printf("%d\n", minCnt);

        int preLine = 0, preTransfer = s;
        for (int j = 1; j < ans.size(); j++) {
            if (line[ans[j-1]*10000+ans[j]] != preLine) {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n",preLine, preTransfer, ans[j-1]);
                preLine = line[ans[j-1]*10000+ans[j]];
                preTransfer = ans[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer,d);
    }
    return 0;
}

 */


/*
  int start, end;
        int pre;

        for (int i = 0; i < ans.size() - 1; ++i) {
            if (i == 0){
                start = ans[i], end = ans[i + 1];
                pre = line[start * MAXN + end];
                continue;
            }

            int now = line[ans[i] * MAXN + ans[i + 1]];
            if (now == pre) {
                end = ans[i + 1];
                if (i + 1 == ans.size() - 1){
                    printf("Take Line#%d from %d to %d.\n", pre, start, end);
                }
            } else{
                printf("Take Line#%d from %d to %d.\n", pre, start, end);
                start = ans[i], end = ans[i + 1];
                pre = line[ans[i] * MAXN + ans[i + 1]];

                if (i + 1 == ans.size() - 1){
                    printf("Take Line#%d from %d to %d.\n", pre, start, end);
                }
            }
        }
 */


/*
const int MAXN = 10000;
int s, d;
int n;
int minCnt = INT_MAX, minTrans = INT_MAX;
vector<int> ans, temp;
vector<vector<int>> graph(MAXN);
unordered_map<int, int> line;
bool visited[MAXN] = {false};

int getLine(vector<int> &temp){
    int pre = line[temp[0] * MAXN + temp[1]];
    int cnt = 0;
    for (int i = 1; i < temp.size() - 1; ++i) {
        int cur = temp[i], next = temp[i + 1];
        if (line[cur * MAXN + next] != pre)
            cnt++;

        pre = line[cur * MAXN + next];
    }

    return cnt;
}

void dfs(int u){
    if (u == d){
        visited[u] = true;
        temp.push_back(u);
        int nowCnt = temp.size(), nowTrans = getLine(temp);

        if (nowCnt < minCnt){
            minCnt = nowCnt;
            minTrans = nowTrans;
            ans = temp;
        } else if (nowCnt == minCnt && nowTrans < minTrans){
            minTrans = nowTrans;
            ans = temp;
        }

        temp.pop_back();
        visited[u] = false;
        return;
    }

    visited[u] = true;
    temp.push_back(u);

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (!visited[v]){
            dfs(v);
        }
    }

    visited[u] = false;
    temp.pop_back();
}


int main(){
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int m;
        scanf("%d", &m);
        vector<int> a(m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[j]);
        }

        for (int j = 0; j < a.size() - 1; ++j) {
            int u = a[j], v = a[j + 1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            line[u * MAXN + v] = line[v * MAXN + u] = i;
        }
    }

    int k;
    scanf("%d", &k);

    while (k--){
        scanf("%d%d", &s, &d);
        fill(visited, visited + MAXN, false);
        minCnt = INT_MAX, minTrans = INT_MAX;
        temp.clear();
        ans.clear();
        dfs(s);
        printf("%d\n", ans.size() - 1);

        int preLine = 0, preTransfer = s;
        for (int j = 1; j < ans.size(); j++) {
            if (line[ans[j-1]*10000+ans[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n",
                                         preLine, preTransfer, ans[j-1]);
                preLine = line[ans[j-1]*10000+ans[j]];
                preTransfer = ans[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer,d);
    }

    return 0;
}

*/


/*
void dfs(int u){
    if (u == d){
        int nowCnt = temp.size(), nowTrans = getLine(temp);

        if (nowCnt < minCnt){
            minCnt = nowCnt;
            minTrans = nowTrans;
            ans = temp;
        } else if (nowCnt == minCnt && nowTrans < minTrans){
            minTrans = nowTrans;
            ans = temp;
        }

        return;
    }

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (!visited[v]){
            visited[v] = true;
            temp.push_back(v);
            dfs(v);
            visited[v] = false;
            temp.pop_back();
        }
    }
}

 */

