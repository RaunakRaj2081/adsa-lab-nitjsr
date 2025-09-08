#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) 
{
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
     n->left = n->right = NULL;
    return n;
}

void preorder(struct Node* root) 
{
    if (!root) return;
    struct Node* st[100]; 
    int top = -1;
    st[++top] = root;
    while (top >= 0) 
    {
        struct Node* cur = st[top--];
        printf("%d ", cur->data);
        if (cur->right) st[++top] = cur->right;
        if (cur->left)  st[++top] = cur->left;
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    preorder(root);
}
