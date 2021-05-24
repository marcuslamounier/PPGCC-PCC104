#include <iostream>
#include <vector>
using namespace std;

struct treeNode {
    int val;
    int left;
    int right;
};

void insertNode(int item, int level, vector <treeNode> &tree){
    if (tree.empty()) {
            treeNode newNode;
            newNode.val = item;
            newNode.left = NULL;
            newNode.right = NULL;

            tree.push_back(newNode);
    }
    else if (item < tree[level].val) {

        if (tree[level].left == NULL){
            treeNode newNode;
            newNode.val = item;
            newNode.right = NULL;
            newNode.left = NULL;

            tree[level].left = tree.size();
            tree.push_back(newNode);

        }
        else {
            level = tree[level].left;
            insertNode(item, level ,tree);
        }

    }
    else if (item > tree[level].val) {

        if (tree[level].right == NULL){
            treeNode newNode;
            newNode.val = item;
            newNode.right = NULL;
            newNode.left = NULL;

            tree[level].right = tree.size();
            tree.push_back(newNode);

        }
        else {
            level = tree[level].right;
            insertNode(item, level ,tree);
        }

    }
    else {
        cout << "O elemento ja existe na arvore." << endl;
    }

}

void findNode (vector <treeNode> tree, int level, int key){
    if (tree.empty()) {
        cout << "Arvore vazia." << endl;
    }

    if (key < tree[level].val) {
        level = tree[level].left;
        findNode(tree, level, key); 

    }
    else if (key > tree[level].val) {
        level = tree[level].right; 
        findNode(tree, level, key);

    }
    else if (key == tree[level].val) {
        cout << "O item esta na posicao " << level << endl;
    }
    else {
        cout << "Nao existe o item na arvora" << endl;
    }
}

void printTree(vector <treeNode> tree) {
    for(int i = 0; i < tree.size(); i++){
        cout << "\t" << tree[i].val << endl;
        cout << "|\t\t" << "|" << endl;
        if (tree[i].right == 0){
            cout << "-\t\t-" << endl;
        }
        else {
            cout << tree[i].left << "\t\t" << tree[i].right << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Digite o numero de nos da arvore: ";
    cin >> n;
    
    vector <treeNode> tree;

    if (n >= 1) {
        for (int i = 0; i < n; i++) {
            int newItem;
            cout << "Digite o " << i + 1 << "o valor: ";
            cin >> newItem;
            cout << endl;

            insertNode(newItem, 0, tree);
        }
    }

    printTree(tree);

    cout << "Quantos numeros deseja buscar? ";
    cin >> n;

    if (n >= 1) {
        for (int i = 0; i < n; i++) {
            int findItem;
            cout << "Digite o " << i + 1 << "o valor: ";
            cin >> findItem;
            cout << endl;

            findNode(tree, 0, findItem);
        }
    }
    
    printTree(tree);
    return 0;
}