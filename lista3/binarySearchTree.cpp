#include <iostream>
#include <concepts>

using namespace std;

enum class InsertionInfo { Inserted, AlreadyIn };
enum class SearchInfo { Found, NotFound };

template <class T>

class BinarySearchTree {

	class BSTNode {
        public:
            T value;
            unique_ptr<BSTNode> left;
            unique_ptr<BSTNode> right;

            BSTNode(T v) { value = v; }
	};


    public:
        BinarySearchTree(){}

        InsertionInfo insert(T v) {
            return insert(v, root);
        }

        SearchInfo search(T v) {
            return search(v, root);
        }

        void print() {
            print(root);
        }

    private:
        unique_ptr<BSTNode> root;

        InsertionInfo insert(T v, unique_ptr<BSTNode>& node){
            
            if (!node) {
                node = make_unique<BSTNode>(v);
                return InsertionInfo::Inserted;
            }

            if (v == node->value) {
                return InsertionInfo::AlreadyIn;
            }

            return (v < node->value) ? insert(v, node->left) : insert(v, node->right);
        }

        
        SearchInfo search(T v, unique_ptr<BSTNode>& node) {

            if (!node) {
                return SearchInfo::NotFound;
            }

            if (v == node->value) {
                return SearchInfo::Found;
            }

            return (v < node->value) ? search(v, node->left) : search(v, node->right);
        }

        void print(unique_ptr<BSTNode>& node) {
            if (!node) {
                return;
            }
            else {
                print(node->left);
                cout << node->value << "\t";
                print(node->right);
            }
	    }
};

int main() {
    BinarySearchTree <int> bt;

    cout << (bt.insert(9) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
    cout << (bt.insert(10) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
    cout << (bt.insert(8) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
    cout << (bt.insert(3) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
    cout << (bt.insert(2) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
    cout << (bt.insert(4) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
    cout << (bt.insert(2) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
    cout << (bt.insert(11) == InsertionInfo::Inserted ? "Inserted" : "AlreadyIn") << endl;
 

    bt.print();

    cout << endl;

    cout << (bt.search(7) == SearchInfo::Found ? "found" : "not found") << endl;
    cout << (bt.search(8) == SearchInfo::Found ? "found" : "not found") << endl;

    return 0;
}