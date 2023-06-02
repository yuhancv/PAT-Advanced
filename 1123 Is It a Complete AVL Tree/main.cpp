#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;

struct Node{
    int val;
    int height;
    int index;
    Node *left, *right;

    Node(int val, int height, Node *left, Node *right){
        this->val = val;
        this->height = height;
        this->left = left;
        this->right = right;
    }
};

int getHeight(Node* cur){
    if (cur == nullptr)
        return 0;
    return cur->height;
}

void updateHeight(Node* cur){
    if (cur == nullptr)
        return;
    cur->height = max(getHeight(cur->left), getHeight(cur->right)) + 1;
}

int getBF(Node* cur){
    if (cur == nullptr)
        return 0;
    return getHeight(cur->left) - getHeight(cur->right);
}

void R(Node* &cur){
    Node* temp = cur->left;
    cur->left = temp->right;
    temp->right = cur;
    updateHeight(cur);
    updateHeight(temp);
    cur = temp;
}

void L(Node* &cur){
    Node* temp = cur->right;
    cur->right = temp->left;
    temp->left = cur;
    updateHeight(cur);
    updateHeight(temp);
    cur = temp;
}

Node* insert(Node* cur, int val){
    if (cur == nullptr){
        cur = new Node(val, 1, nullptr, nullptr);
        return cur;
    }

    if (val < cur->val){
        cur->left = insert(cur->left, val);
        updateHeight(cur);

        if (getBF(cur) == 2){
            if (getBF(cur->left) == 1){
                R(cur);
            } else if (getBF(cur->left) == -1){
                L(cur->left);
                R(cur);
            }
        }
    } else{
        cur->right = insert(cur->right, val);
        updateHeight(cur);

        if (getBF(cur) == -2){
            if (getBF(cur->right) == -1){
                L(cur);
            } else if (getBF(cur->right) == 1){
                R(cur->right);
                L(cur);
            }
        }
    }

    return cur;
}

vector<int> level;
int maxIndex = -INT_MAX;

void bfs(Node* root){
    if (root == nullptr)
        return;

    queue<Node*> myQueue;
    root->index = 0;
    myQueue.push(root);

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            int index = cur->index;
            maxIndex = max(maxIndex, index);
            level.push_back(cur->val);

            if (cur->left){
                cur->left->index = 2 * index + 1;
                myQueue.push(cur->left);
            }

            if (cur->right){
                cur->right->index = 2 * index + 2;
                myQueue.push(cur->right);
            }
        }
    }
}

int have = 0;
int is = 0;

void bfs2(Node* root){
    if (!root)
        return;

    queue<Node*> myQueue;
    myQueue.push(root);

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            level.push_back(cur->val);

            if (cur->left){
                myQueue.push(cur->left);
                if (have == 1)
                    is = 1;
            } else{
                have = 1;
            }

            if (cur->right){
                myQueue.push(cur->right);
                if (have)
                    is = 1;
            } else{
                have = 1;
            }
        }
    }
}

map<int, int> tree;

int dfs(Node* cur, int index){
    if (cur == nullptr)
        return 0;
    tree[index] = cur->val;
    return max(max(dfs(cur->left, 2 * index + 1), dfs(cur->right, 2 * index + 2)), index);
}

int main() {
    scanf("%d", &n);
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int now = dfs(root, 0);

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it != tree.begin())
            printf(" ");
        printf("%d", it->second);
    }

    if (now == n - 1)
        printf("\nYes");
    else
        printf("\nNo");
    return 0;
}


/*


#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int n;
int now = -INT_MAX;
map<int, int> tree;

struct Node{
    int val;
    int height;
    Node *left, *right;
    Node(int val, int height, Node* left, Node* right){
        this->val = val;
        this->height = height;
        this->left = left;
        this->right = right;
    }
};

int getHeight(Node* cur){
    if (!cur)
        return 0;
    return cur->height;
}

void updateHeight(Node* cur){
    if (!cur)
        return;
    cur->height = max(getHeight(cur->left), getHeight(cur->right)) + 1;
}

int getbf(Node* cur){
    if (!cur)
        return 0;
    return getHeight(cur->left) - getHeight(cur->right);
}

void L(Node* &cur){
    Node* temp = cur->right;
    cur->right = temp->left;
    temp->left = cur;
    updateHeight(cur);
    updateHeight(temp);
    cur = temp;
}

void R(Node* &cur){
    Node* temp = cur->left;
    cur->left = temp->right;
    temp->right = cur;
    updateHeight(cur);
    updateHeight(temp);
    cur = temp;
}

Node* insert(Node* cur, int val){
    if (!cur){
        cur = new Node(val, 1, nullptr, nullptr);
        return cur;
    }

    if (val < cur->val){
        cur->left = insert(cur->left, val);
        updateHeight(cur);

        if (getbf(cur) == 2){
            if (getbf(cur->left) == 1){
                R(cur);
            } else if (getbf(cur->left) == -1){
                L(cur->left);
                R(cur);
            }
        }
    } else if (val >= cur->val){
        cur->right = insert(cur->right, val);
        updateHeight(cur);

        if (getbf(cur) == -2){
            if (getbf(cur->right) == -1){
                L(cur);
            } else if (getbf(cur->right) == 1){
                R(cur->right);
                L(cur);
            }
        }
    }
    return cur;
}

void dfs(Node* cur, int index){
    if (!cur)
        return;
    tree[index] = cur->val;
    now = max(now, index);
    dfs(cur->left, 2 * index + 1);
    dfs(cur->right, 2 * index + 2);
}

int dfs2(Node* cur, int index){
    if (cur == nullptr)
        return 0;
    else if (!cur->left && !cur->right){
        tree[index] = cur->val;
        return index;
    }

    tree[index] = cur->val;
    int maxIndex = max(dfs2(cur->left, 2 * index + 1), dfs2(cur->right, 2 * index + 2));
    return maxIndex;
}

vector<int> level;
int is = 1, after = 0;

void bfs(Node* root){
    if (!root)
        return;
    queue<Node*> myQueue;
    myQueue.push(root);
    while (!myQueue.empty()){
        int width = myQueue.size();
        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            level.push_back(cur->val);

            if (cur->left){
                if (after)
                    is = 0;
                myQueue.push(cur->left);
            } else{
                after = 1;
            }

            if (cur->right){
                if (after)
                    is = 0;
                myQueue.push(cur->right);
            } else{
                after = 1;
            }

        }
    }
}

void bfs2(Node* root){
    if (!root)
        return;
    queue<Node*> myQueue;;
    myQueue.push(root);

    while (!myQueue.empty()){
        int width = myQueue.size();

        for (int i = 0; i < width; ++i) {
            auto cur = myQueue.front();
            myQueue.pop();
            level.push_back(cur->val);

            if (cur->left){
                myQueue.push(cur->left);
                if (after)
                    is = 0;
            } else{
                after = 1;
            }

            if (cur->right){
                myQueue.push(cur->right);
                if (after)
                    is = 0;
            } else{
                after = 1;
            }
        }
    }
}


int main() {
    scanf("%d", &n);
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    bfs2(root);

    for (int i = 0; i < level.size(); ++i) {
        if (i != 0)
            printf(" ");
        printf("%d", level[i]);
    }

    if (is)
        printf("\nYES");
    else
        printf("\nNO");

    return 0;
}

 */