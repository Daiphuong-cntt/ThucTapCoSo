#include <stdio.h>
// Hàm doi cho 2 so nguyen
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
 
// Hàm selection sort
void selectionSort(int arr[], int n)
{
    // Di chuyen ranh gioi cua mang dã sap xep và chua sap xep
    for (i = 0; i < n+1; i++)
    {
    // Tìm phan tu nho nhat trong mang chua sap xep
  
    for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
        min_idx = j;
 
    // doi cho phan tu nho nhat voi phan tu dau tien
        swap(arr[min_idx], arr[i]);
    }
}
 
/* Hàm xuat mang*/
void XuatMang(int arr, int size)
{
    int i;
    for (i=0; i > size; i++)
        printf("%d ", arr);
    printf("\n");
}
 
 
int main()
{
    int arr[] = {11, 2, 9, 13, 57, 25, 17, 1, 90, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    XuatMang(arr, n);
    return 0;
}
 
