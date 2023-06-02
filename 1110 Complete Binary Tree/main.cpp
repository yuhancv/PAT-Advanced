#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
struct Node{
    int left, right;
    int index;
};

int visited[27] = {0};
vector<Node> tree;

int ans = -1;
int maxIndex = -INT_MAX;

void bfs(int root){
    queue<int> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            if (tree[cur].index > maxIndex){
                maxIndex = tree[cur].index;
                ans = cur;
            }

            if (tree[cur].left != -1){
                myQueue.push(tree[cur].left);
                tree[tree[cur].left].index = 2 * (tree[cur].index)  +1;
            }

            if (tree[cur].right != -1){
                myQueue.push(tree[cur].right);
                tree[tree[cur].right].index = 2 * (tree[cur].index)  + 2;
            }

        }
    }
}

int main(){
    scanf("%d", &n);
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;

        if (left != "-"){
            tree[i].left = stoi(left);
            visited[stoi(left)] = 1;
        } else{
            tree[i].left = -1;
        }

        if (right != "-"){
            tree[i].right = stoi(right);
            visited[stoi(right)] = 1;
        } else{
            tree[i].right = -1;
        }
    }

    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0){
            root = i;
            break;
        }
    }

    tree[root].index = 0;
    bfs(root);

    if (maxIndex == n - 1){
        printf("YES %d", ans);
    } else{
        printf("NO %d", root);
    }

    return 0;
}

/*
void bfs(int root){
    if (root == -1)
        return;

    queue<int> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            int cur = myQueue.front();
            myQueue.pop();
            int index = tree[cur].index;
            if (index > maxIndex){
                maxIndex = index;
                ans = cur;
            }

            if (tree[cur].left != -1){
                myQueue.push(tree[cur].left);
                int now = 2 * index + 1;
                tree[tree[cur].left].index = now;
                if (now > maxIndex){
                    maxIndex = now;
                    ans = tree[cur].left;
                }
            }

            if (tree[cur].right != -1){
                myQueue.push(tree[cur].right);
                int now = 2 * index + 2;
                tree[tree[cur].right].index = now;
                if (now > maxIndex){
                    maxIndex = now;
                    ans = tree[cur].right;
                }
            }
        }
    }
}
*/


/*
void bfs(int root){
    if (root < 0 || root > n - 1)
        return;

    queue<int> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            int index = tree[cur].index;

            if (tree[cur].left != -1){
                tree[tree[cur].left].index = 2 * index + 1;
                if (2 * index + 1 > maxIndex){
                    maxIndex = 2 * index + 1;
                    ans = tree[cur].left;
                }
                myQueue.push(tree[cur].left);
            }

            if (tree[cur].right != -1){
                tree[tree[cur].right].index = 2 * index + 2;
                if (2 * index + 2 > maxIndex){
                    maxIndex = 2 * index + 2;
                    ans = tree[cur].right;
                }

                myQueue.push(tree[cur].right);
            }
        }
    }
}

 */



/*
int n;
struct Node{
    int left, right;

};

int visited[27] = {0};
vector<Node> tree;

int ans = -1;
int maxIndex = -INT_MAX;

void dfs(int cur, int index){
    if (cur == -1)
        return;

    if (index > maxIndex){
        maxIndex = index;
        ans = cur;
    }

    dfs(tree[cur].left, 2 * index + 1);
    dfs(tree[cur].right, 2 * index + 2);
}

int main(){
    scanf("%d", &n);
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;

        if (left != "-"){
            tree[i].left = stoi(left);
            visited[stoi(left)] = 1;
        } else{
            tree[i].left = -1;
        }

        if (right != "-"){
            tree[i].right = stoi(right);
            visited[stoi(right)] = 1;
        } else{
            tree[i].right = -1;
        }
    }

    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0){
            root = i;
            break;
        }
    }

    dfs(root, 0);

    if (maxIndex == n - 1){
        printf("YES %d", ans);
    } else{
        printf("NO %d", root);
    }

    return 0;
}

 */




/*
int n;

struct Node{
    int left, right;
};

vector<Node> tree;
int visited[27] = {0};

int ans = 0;
int maxIndex = -INT_MAX;

int dfs(int cur, int index){
    if (cur == -1)
        return 0;
    else if (tree[cur].left == -1 && tree[cur].right == -1){
        if (index > maxIndex){
            maxIndex = index;
            ans = cur;
        }

        return index;
    }

    int now = index;
    int left = dfs(tree[cur].left, 2 * index + 1);
    int right = dfs(tree[cur].right, 2 * index + 2);
    now = max(max(left, right), now);
    return now;
}

int main(){
    scanf("%d", &n);
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;

        if (left != "-"){
            tree[i].left = stoi(left);
            visited[stoi(left)] = 1;
        } else{
            tree[i].left = -1;
        }

        if (right != "-"){
            tree[i].right = stoi(right);
            visited[stoi(right)] = 1;
        } else{
            tree[i].right = -1;
        }
    }

    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0){
            root = i;
            break;
        }
    }

    int index = dfs(root, 0);

    if (index == n - 1){
        printf("YES %d", ans);
    } else{
        printf("NO %d", root);
    }

    return 0;
}

 */

/*
int n;

struct Node{
    int left, right;
};

vector<Node> tree;
int visited[27] = {0};

int ans = 0;
int maxIndex = -INT_MAX;

int dfs(int cur, int index){
    if (cur == -1)
        return 0;

    if (index > maxIndex){
        ans = cur;
        maxIndex = index;
    }

    int left = dfs(tree[cur].left, 2 * index + 1);
    int right = dfs(tree[cur].right, 2 * index + 2);
    return max(max(left, right), index);
}

int main() {
    scanf("%d", &n);
    tree.resize(n);

    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;

        if (left != "-"){
            tree[i].left = stoi(left);
            visited[stoi(left)] = 1;
        } else{
            tree[i].left = -1;
        }

        if (right != "-"){
            tree[i].right = stoi(right);
            visited[stoi(right)] = 1;
        } else{
            tree[i].right = -1;
        }
    }

    int root = 0;

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0){
            root = i;
            break;
        }
    }

    int depth = dfs(root, 0);

    if (depth == n - 1){
        printf("YES %d", ans);
    } else{
        printf("NO %d", root);
    }

    return 0;
}


 */