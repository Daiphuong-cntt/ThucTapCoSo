
#include <iostream>

using namespace std;

class Node {

private: int key;
       Node* left, * right;

public: Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
public:
    Node() {

    }

public: void storeSorted(Node* root, int arr[], int& i) {
          if (root != NULL) {
              storeSorted(root->left, arr, i);
              arr[i++] = root->key;
              storeSorted(root->right, arr, i);
          }
      }

//	Mot chuc nang tien ích de chèn mot
//      Nút voi khóa nhat dinh
public: Node* insert(Node* node, int key) {
          /* Neu cây trong == null, tra ve mot Node moi */
          if (node == NULL) return newNode(key);

          
          if (key < node->key)
              node->left = insert(node->left, key);
          else if (key > node->key)
              node->right = insert(node->right, key);

          
          return node;
      }

      // Hàm này sap xep arr [0..n-1] bang cách su dung Tree Sort
public:  void treeSort(int arr[], int n) {
          struct Node* root = NULL;

          // xay dung
          root = insert(root, arr[0]);
          for (int i = 1; i < n; i++)
              root = insert(root, arr[i]);

          // luu tru truyen tai
          int i = 0;
          storeSorted(root, arr, i);
      }
};

int main() {
    // tao mang dau vào
    int arr[] = { 5, 4, 7, 2, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* node = new Node();
    node->treeSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

}
