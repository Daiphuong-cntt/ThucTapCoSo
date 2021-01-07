#include <iostream>
using namespace std;

class Sort {

public:
    Sort() {

    }
// Ham doi cho hai so nguyen
public: void swap(int* xp, int* yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
// Hàm selection sort
public: void selectionSort(int arr[], int n)
    {
        int i, j, min_idx;

        // di chuyen ranh gioi cua mang da sap xep va chua sap xep
        for (i = 0; i < n - 1; i++)
        {
            // tim phan tu nho nhat trong mang chua sap xep
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] > arr[min_idx])
                    min_idx = j;

            // doi cho phan tu nho nhat voi phan tu dau tien
            swap(&arr[min_idx], &arr[i]);
        }
    }

    /* ham xuat mang */
public:  void printArray(int arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Chuong trình dieu khien de kiem tra các chuc nang trên 
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Sort* sort = new Sort();
    sort->selectionSort(arr, n);
    cout << "Sorted array: \n";
    sort->printArray(arr, n);
    return 0;
}