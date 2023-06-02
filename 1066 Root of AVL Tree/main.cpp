#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int n;
struct Node{
    int val;
    int height;
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
    cur->height = max(getHeight(cur->left), getHeight(cur->right))  + 1;
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
    if (!cur){
        cur = new Node(val, 1, nullptr, nullptr);
        return cur;
    }

    if (val < cur->val){
        cur->left = insert(cur->left, val);
        updateHeight(cur);

        if (getBF(cur) == 2){
            if (getBF(cur->left) == 1)
                R(cur);
            else if (getBF(cur->left) == -1){
                L(cur->left);
                R(cur);
            }
        }
    } else{
        cur->right = insert(cur->right, val);
        updateHeight(cur);

        if (getBF(cur) == -2){
            if (getBF(cur->right) == -1)
                L(cur);
            else if (getBF(cur->right) == 1){
                R(cur->right);
                L(cur);
            }
        }
    }

    return cur;
}

int main(){
    scanf("%d", &n);
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("%d", root->val);
    return 0;
}

/*
int n;

struct Node{
    int val, height;
    Node *left, *right;
    Node(int val, int height, Node* left, Node* right){
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

    if (val <= cur->val){
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


int main() {
    scanf("%d", &n);
    Node* root = nullptr;

    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("%d", root->val);
    return 0;
}

 */