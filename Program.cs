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
            while (i<n_left && j<n_right)
            {
                if(L[i]<R[j])
                {
                    A[k]=L[i];
                    i++;
                    k++;
                }
                if(L[i]>R[j])
                {
                    A[k]=R[j];
                    j++;
                    k++;
                }
            }
            // xếp các phần tử còn lại của L vào mảng A (nếu có)
            while (i<n_left)
            {
                A[k]=L[i];
                i++;
                k++;
            }
            // xếp các phần tử còn lại của R vào mảng A (nếu có)
            while (j<n_right)
            {
                A[k]=R[j];
                j++;
                k++;
            }
        }
        // hàm đệ qui MergeSort
        static public void MergeSort(int[] A, int l, int r) 
        {
            if(l<r)
            {
                int m;
                m=(l+r)/2;
                // sắp xếp 2 mảng con
                MergeSort(A,l,m);
                MergeSort(A,m+1,r);
                // gộp mảng
                merge(A,l,r);
            }
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
            // Chạy thuật toán Merge Sort
            MERGESORT ms = new MERGESORT();
            ms.MergeSort(input, 0, input.Length-1);
            // Chạy thuật toán Heap Sort
            /*HEAPSORT hs = new HEAPSORT();
            hs.
            */
            Console.ReadKey();
        }
    }
}