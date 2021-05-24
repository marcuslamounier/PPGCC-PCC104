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
  return (treeNode);
};

int height(struct treeNode *T){
    if(T == NULL){
        return -1;
    }
    else{
        return max(height(T->left),height(T->right))+1;
    }
}

int main() {
    struct treeNode *noRaiz = newNode(10);
    noRaiz->left = newNode(20);
    noRaiz->left->left = newNode(40);
    noRaiz->left->right = newNode(28);
    noRaiz->right = newNode(30);
    noRaiz->right->left = newNode(27);
    noRaiz->right->left->right = newNode(29);
    noRaiz->right->right = newNode(50);
    int tamanho = height(noRaiz);
    cout << tamanho << endl;
    return 0;
}