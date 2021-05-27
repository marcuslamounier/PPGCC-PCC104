#include <iostream>

using namespace std;

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *newNode(int data) {
  struct treeNode *treeNode = (struct treeNode *)malloc(sizeof(struct treeNode));
  treeNode->val = data;
  treeNode->left = NULL;
  treeNode->right = NULL;
  return treeNode;
};

int height(struct treeNode *T){
    return (T == NULL) ? -1 : (max(height(T->left), height(T->right)) + 1);
}

void preorder(struct treeNode *T) {
    if (T != NULL) {
        cout << T->val << " ";
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(struct treeNode *T) {
    if (T != NULL) {
        inorder(T->left);
        cout << T->val << " ";
        inorder(T->right);
    }
}

void postorder(struct treeNode *T) {
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        cout << T->val << " ";
    }
}

int main() {
    struct treeNode *root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(40);
    root->left->right = newNode(28);
    root->right = newNode(30);
    root->right->left = newNode(27);
    root->right->left->right = newNode(29);
    root->right->right = newNode(50);

    cout << "PreOrder" << endl;
    preorder(root);
    cout << endl;

    cout << "InOrder" << endl;
    inorder(root);
    cout << endl;

    cout << "PostOrder" << endl;
    postorder(root);
    cout << endl;

    return 0;
}