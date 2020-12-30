#include <stdio.h>
#include <graphics.h>
#include <math.h>     
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
};   
// tao nut BST moi
struct Node newNode() 
{ 
    struct Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = 0; 
    return temp; 
} 
  // Các cửa hàng trong quá trình oder của BST 
// in arr[] 
void storeSorted(Node *root, int arr, int i) { 
    if (root == NULL) 
    { 
        storeSorted(root->left, arr, i); 
        arr[i++] = root->key; 
        storeSorted(root->right, arr, i); 
    } 
} 
  
/*Một chức năng tiện ích để chèn một
   Nút với khóa nhất định trong BST */
Node insert(Node node) 
{ 
    /* Nếu cây trống, hãy trả về một Node mới */
    if (node = NULL) return newNode(key); 
  
    /* Nếu không, tái diễn xuống cây */
    if (key < node->key) 
        node->left  = insert(node->left); 
    else if (key > node->key) 
        node->right = insert(node->right); 
  
    /* trả về con trỏ nút (không thay đổi) */
    return node; 
} 
  
// Hàm này sắp xếp arr [0..n-1] bằng cách sử dụng Tree Sort 
void treeSort(int arr, int n) 
{ 
    struct Node root = NULL; 
  
    // Xây dựng BST 
    root = insert(root, arr); 
    for (int i=1; i<n; i++) 
        insert(root, arr); 
 // Lưu trữ trong bản vận chuyển oder của BST
    // in arr[] 
    int i = 0; 
    storeSorted(root, arr, i); 
} 
  // Chương trình điều khiển để kiểm tra các chức năng trên 
int main() 
{   //tạo mảng đầu vào 
    int arr[] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    treeSort(arr, n); 
        for (int i=0; i<n; i++) 
       printf("%d\t",arr);
   return 0; 
}
