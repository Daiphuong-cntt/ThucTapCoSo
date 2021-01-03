using System;

namespace ThucTapCoSo 
{
    class MERGESORT
    {
        static public void merge(int[] A, int l,int r,int m) 
        {
            int i, j, k;
            // tạo 2 mảng con
            int n_left = m+1-l;
            int n_right = r-m;
            int[] L = new int [n_left];
            int[] R = new int [n_right];
            
            // sao chép dữ liệu mảng A vào 2 mảng con L,R
            for(i=0;i<n_left;i++)
            {
                L[i]=A[l+i];
            }
            for(j=0;j<n_right;j++)
            {
                R[j]=A[m+1+j];
            }
            
            i=0;    // khởi tạo chỉ số bắt đầu của mảng L
            j=0;    // khởi tạo chỉ số bắt đầu của mảng R
            k=l;    // khởi tạo chỉ số bắt dầu của mảng kết quả
            
            // sắp xếp trộn
            
            
            // xếp các phần tử còn lại của L vào mảng A (nếu có)
            
            // xếp các phần tử còn lại của R vào mảng A (nếu có)
            
        }
        // hàm đệ qui MergeSort
        static public void MergeSort(int[] A, int l, int r) 
        {

        }   
    }
    class HEAPSORT
    {

    }
    class Program
    {
        // Hàm chính
        static void Main(string[] args)
        {
            int[] input = {23, 1, 32, 68, 89, 200, 55, 78, 99, 12};
            int i;
            Console.WriteLine("Mảng đầu vào: ");   
            for (i = 0; i < input.Length; i++)
            {
                Console.Write("{0}\t",input[i]);
            }
            // Chạy code Merge Sort
            MERGESORT ms =new MERGESORT();
            ms.MergeSort();

            Console.ReadKey();
        }
    }
}