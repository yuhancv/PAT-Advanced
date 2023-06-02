#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int p, m, n;

struct Node{
    string id;
    int oj, mid, final, sum;
};

bool cmp(Node a, Node b){
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else
        return a.id < b.id;
}

map<string, int> tree;
vector<Node> ans, v;
string  s;
int num;

int main(){
    scanf("%d%d%d", &p, &m, &n);
    int cur = 0;

    for (int i = 0; i < p; ++i) {
        cin >> s;
        scanf("%d", &num);
        if (num >= 200){
            tree[s] = cur++;
            v.push_back({s, num, -1, -1, 0});
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> s;
        scanf("%d", &num);

        if (tree.find(s) != tree.end()){
            v[tree[s]].mid = num;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> s;
        scanf("%d", &num);
        if (tree.find(s) != tree.end()){
            int index = tree[s];
            v[index].final = v[index].sum = num;
            if (v[index].mid > v[index].final){
                v[index].sum = (int )(0.4 * v[index].mid + 0.6 * v[index].final + 0.5);
            }
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].sum >= 60)
            ans.push_back(v[i]);
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].oj, ans[i].mid, ans[i].final, ans[i].sum);
    }

    return 0;
}





/*
int p, m, n;

struct Stu{
    string id;
    int oj, mid, final, sum;
};

map<string, int> tree;
vector<Stu> ans, v;

bool cmp(Stu a, Stu b){
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else
        return a.id < b.id;
}

int main(){
    scanf("%d%d%d", &p, &m, &n);
    string id;
    int num;
    int cur = 0;
    for (int i = 0; i < p; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (num >= 200){
            tree[id] = cur++;
            v.push_back({id, num, -1, -1, 0});
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (tree.find(id) != tree.end()){
            v[tree[id]].mid = num;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (tree.find(id) != tree.end()){
            int temp = tree[id];
            v[temp].final = v[temp].sum = num;
            if (v[temp].mid > v[temp].final)
                v[temp].sum = (int ) (0.4 * v[temp].mid + 0.6 * v[temp].final + 0.5);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].sum >= 60)
            ans.push_back(v[i]);
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].oj, ans[i].mid, ans[i].final, ans[i].sum);
    }
    return 0;
}

 */

/*
int p, m, n;

struct Stu{
    string id;
    int oj, mid, final, sum;
};

bool cmp(Stu a, Stu b){
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else
        return a.id < b.id;
}

vector<Stu> ans, v;
map<string, int> tree;

int main(){
    string id;
    int num;
    int cur = 1;
    scanf("%d%d%d", &p, &m, &n);

    for (int i = 0; i < p; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (num >= 200){
            tree[id] = cur++;
            v.push_back({id,  num, -1, -1, 0});
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (tree[id] != 0)
            v[tree[id] - 1].mid = num;
    }

    for (int i = 0; i < n; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (tree[id] != 0){
            v[tree[id] - 1].final =  v[tree[id] - 1].sum = num;
            if (v[tree[id] - 1].mid > v[tree[id] - 1].final)
                v[tree[id] - 1].sum = (int )(v[tree[id] - 1].mid * 0.4 + v[tree[id] - 1].final * 0.6 + 0.5);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].sum >= 60)
            ans.push_back(v[i]);
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].oj, ans[i].mid, ans[i].final, ans[i].sum);
    }

    return 0;
}

 */


/*
int p, m, n;
struct Stu{
    string id;
    int oj, mid, final, sum;
};

bool cmp(Stu a, Stu b){
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else
        return a.id < b.id;
}

vector<Stu> ans, v;
string id;
int num;
map<string, int> tree;
int main(){
    scanf("%d%d%d", &p, &m, &n);
    int cnt = 1;
    
    for (int i = 0; i < p; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (num >= 200){
            v.push_back({id, num, -1, -1, 0});
            tree[id] = cnt++;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (tree[id] != 0)
            v[tree[id] - 1].mid = num;
    }

    for (int i = 0; i < n; ++i) {
        cin >> id;
        scanf("%d", &num);
        if (tree[id] != 0){
            int cur = tree[id] - 1;
            v[cur].final = v[cur].sum = num;
            if (v[cur].mid > v[cur].final)
                v[cur].sum = (int )(0.4 * v[cur].mid + 0.6 * v[cur].final + 0.5);
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].sum >= 60)
            ans.push_back(v[i]);
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].id.c_str(),ans[i].oj  ,ans[i].mid, ans[i].final, ans[i].sum);
    }

    return 0;
}

 */









/*
int p, m, n;
struct Stu{
    string id;
    int oj = -1, mid = -1, final = -1, sum;
};

map<string, Stu> tree;
vector<Stu> v;

int main(){
    string id;
    int num;

    scanf("%d%d%d", &p, &m, &n);

    for (int i = 0; i < p; ++i) {
        cin >> id;
        scanf("%d", &num);
        tree[id].oj = num;
    }

    for (int i = 0; i < m; ++i) {
        cin >> id;
        scanf("%d", &num);
        tree[id].mid = num;
    }

    for (int i = 0; i < n; ++i) {
        cin >> id;
        scanf("%d", &num);
        tree[id].final = num;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second.oj < 200)
            continue;
        if (it->second.final == -1)
            continue;
    }
    return 0;
}

 */







/*
int p, m, n;

struct Stu{
    string id;
    int oj, mid, final;
    int  sum;
};

map<string, Stu> tree;
vector<Stu> v;

bool cmp(Stu a, Stu b){
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else
        return a.id < b.id;
}

int main(){
    scanf("%d%d%d", &p, &m, &n);

    for (int i = 0; i < p; ++i) {
        string id;
        int num;
        cin >> id;
        scanf("%d", &num);
        if (num == 0)
            tree[id].oj = -2;
        else
            tree[id].oj = num;
    }

    for (int i = 0; i < m; ++i) {
        string id;
        int num;
        cin >> id;
        scanf("%d", &num);
        if (num == 0)
            tree[id].mid = -2;
        else
            tree[id].mid = num;
    }

    for (int i = 0; i < n; ++i) {
        string id;
        int num;
        cin >> id;
        scanf("%d", &num);
        if (num == 0)
            tree[id].final = -2;
        else
            tree[id].final = num;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second.oj == -2)
            it->second.oj = 0;
        else if (it->second.oj == 0)
            it->second.oj == -1;

        if (it->second.mid == -2)
            it->second.mid = 0;
        else if (it->second.mid == 0)
            it->second.mid == -1;

        if (it->second.final == -2)
            it->second.final = 0;
        else if (it->second.final == 0)
            it->second.final == -1;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second.oj < 200)
            continue;

        double sum = 0;
        if (it->second.mid > it->second.final) {
            it->second.sum = (int) (0.4 * (double) it->second.mid + 0.6 * (double) it->second.final + 0.5);
            sum = (0.4 * (double) it->second.mid + 0.6 * (double) it->second.final + 0.5);
        }else{
            it->second.sum = (int) ((double )it->second.final + 0.5);
            sum = ((double )it->second.final + 0.5);
        }


        if (sum >= 59.5)
            v.push_back({it->first, it->second.oj, it->second.mid, it->second.final, it->second.sum});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); ++i) {
        printf("%s %d %d %d %d\n", v[i].id.c_str(), v[i].oj, (v[i].mid >= 0) ? v[i].mid : -1, v[i].final >= 0 ? v[i].final : -1, v[i].sum);
    }

    return 0;
}

 */

/*
int p, m, n;

struct Stu{
    string id;
    int oj, mid, final;
    int sum;
};

vector<Stu> ans;

map<string, Stu> tree;

bool cmp(Stu a, Stu b){
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else
        return a.id < b.id;
}

int main() {
    scanf("%d%d%d", &p, &m, &n);

    for (int i = 0; i < p; ++i) {
        string id;
        int num;
        cin >> id;
        scanf("%d", &num);
        tree[id].oj = num;
    }

    for (int i = 0; i < m; ++i) {
        string id;
        int num;
        cin >> id;
        scanf("%d", &num);
        tree[id].mid = num;
    }

    for (int i = 0; i < n; ++i) {
        string id;
        int num;
        cin >> id;
        scanf("%d", &num);
        tree[id].final = num;
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        printf("%s %d %d %d\n", it->first.c_str(), it->second.oj, it->second.mid, it->second.final);
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->second.oj < 200)
            continue;
        if (it->second.mid > it->second.final)
            it->second.sum = (int)(0.4 * (double )it->second.mid + 0.6 * (double ) it->second.final + 0.1);
        else
            it->second.sum = it->second.final;

        if (it->second.sum < 60)
            continue;

        ans.push_back({it->first, it->second.oj, it->second.mid, it->second.final, it->second.sum});
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); ++i) {
        printf("%s %d %d %d %d\n", ans[i].id.c_str(), ans[i].oj, (ans[i].mid > 0) ? ans[i].mid : -1, ans[i].final > 0 ? ans[i].final : -1, ans[i].sum);
    }

    return 0;
}

 */

/*
    for (auto it = tree.begin(); it != tree.end(); it++) {
        printf("%s %d %d %d\n", it->first.c_str(), it->second.oj, it->second.mid, it->second.final);
    }
     */