#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

struct Node{
    int left, right;
};

int visited[15] ={0};
vector<Node> v;

vector<int> in, level;

void inorder(int cur){
    if (cur == -1)
        return;
    inorder(v[cur].right);
    in.push_back(cur);
    inorder(v[cur].left);
}

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
            level.push_back(cur);

            if (v[cur].right != -1)
                myQueue.push(v[cur].right);
            if (v[cur].left != -1)
                myQueue.push(v[cur].left);
        }
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i < n; ++i) {
        string left, right;
        cin >> left >> right;

        if (left != "-"){
            v[i].left = stoi(left);
            visited[stoi(left)] = 1;
        } else{
            v[i].left = -1;
        }

        if (right != "-"){
            v[i].right = stoi(right);
            visited[stoi(right)] = 1;
        } else{
            v[i].right = -1;
        }
    }

    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0){
            root = i;
            break;
        }
    }

    inorder(root);
    bfs(root);

    for (int i = 0; i < level.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", level[i]);
    }

    printf("\n");

    for (int i = 0; i < in.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", in[i]);
    }

    return 0;
}
