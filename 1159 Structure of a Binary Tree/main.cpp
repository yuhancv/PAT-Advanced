#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n;
vector<int> in, post;
struct Node{
    int val;
    Node* left, *right;
    Node(int val){
        this->val = val;
    }
};

Node* create(int root, int start, int end){
    if (start > end)
        return nullptr;
    int mid = start;
    while (mid <= end && in[mid] != post[root])
        mid++;

    Node* cur = new Node(in[mid]);
    cur->left = create(root - (end - mid) - 1, start, mid - 1);
    cur->right = create(root - 1, mid + 1, end);
    return cur;
}

Node* dfs(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;
    if (val == cur->val)
        return cur;
    Node *left = dfs(cur->left, val), *right = dfs(cur->right, val);
    return left ? left : right;
}

Node* dfsSibl(Node* cur, int val){
    if (cur == nullptr)
        return nullptr;

    if ( (cur->left && cur->left->val == val) || (cur->right && cur->right->val == val))
        return cur;
    Node* left = dfsSibl(cur->left, val), *right = dfsSibl(cur->right, val);
    return left ? left : right;
}

int dfsDepth(Node* cur, int val, int depth){
    if (cur == nullptr)
        return 0;
    if (val == cur->val)
        return depth;
    int left = dfsDepth(cur->left, val, depth + 1), right = dfsDepth(cur->right, val, depth + 1);
    return left ? left : right;
}

bool judge(Node* cur){
    if (cur == nullptr)
        return true;
    if (cur->left == nullptr && cur->right == nullptr)
        return true;

    if (!cur->left || !cur->right)
        return false;
    return judge(cur->left) && judge(cur->right);
}

int main() {
    scanf("%d", &n);
    in.resize(n);
    post.resize(n);

    for (int i = 0; i < post.size(); ++i) {
        scanf("%d", &post[i]);
    }

    for (int i = 0; i < in.size(); ++i) {
        scanf("%d", &in[i]);
    }

    Node* root = create(n - 1, 0, n - 1);

    int m;
    scanf("%d", &m);
    getchar();

    while (m--){
        string t;
        getline(cin, t);
        if (t.find("root") != string::npos){
            int val;
            sscanf(t.c_str(), "%d is the root", &val);
            if (root == dfs(root, val))
                printf("Yes\n");
            else
                printf("No\n");
        }

        if (t.find("siblings") != string::npos){
            int a,b;
            sscanf(t.c_str(),"%d and %d are siblings",&a,&b);
            Node* f1 = dfsSibl(root, a), *f2 = dfsSibl(root, b);
            if (f1 == f2)
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (t.find("parent") != string::npos){
            int a,b;
            sscanf(t.c_str(),"%d is the parent of %d",&a,&b);
            Node* f = dfsSibl(root, b);
            if (f == dfs(root, a))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (t.find("left") != string::npos){
            int a,b;
            sscanf(t.c_str(),"%d is the left child of %d",&a,&b);
            Node* u = dfs(root, a), *v = dfs(root, b);
            if (v->left && v->left->val == a)
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (t.find("right") != string::npos){
            int a,b;
            sscanf(t.c_str(),"%d is the right child of %d",&a,&b);
            Node* u = dfs(root, a), *v = dfs(root, b);
            if (v->right && v->right->val == a)
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (t.find("same") != string::npos){
            int a,b;
            sscanf(t.c_str(),"%d and %d are on the same level",&a,&b);
            if (dfsDepth(root, a, 1) == dfsDepth(root, b, 1))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

        if (t.find("full") != string::npos){
            if (judge(root))
                printf("Yes\n");
            else
                printf("No\n");
            continue;
        }

    }

    return 0;
}

/*
  getchar();
  while (m--){
      string t;
      cin >> t;

      if (w.find(t) != w.end()){
          cout << t << endl;
          continue;
      }

      cin >> t >> t >> t;
      if (w.find(t) != w.end()){
          if (t == "root"){
              cout << t << endl;
          } else if (t == "parent"){
              cout << t << endl;
          } else if (t == "left"){
              cout << t << endl;
          }
          continue;
      }

      cin >> t;

      if (t == "siblings"){
          cout << t << endl;
      } else if (t == "right"){
          cout << t << endl;
      } else if (t == "on"){
          cout << t << endl;
      }
  }
   */