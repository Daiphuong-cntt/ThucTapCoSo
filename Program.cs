using System;

namespace ThucTapCoSo 
{
    class MERGESORT
    {
        // xử lý từng mảng con
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
        // Tìm gtln(largest) và đưa lên làm max của Heap
        static void max_heap(int[] A, int n, int i) 
        { 
            int largest = i; 
            int left =  2*i + 1;
            int right = 2*i + 2; 
            // nếu gtln nằm bên trái
            if (left < n && A[left] > A[largest]) 
            {
                largest = left; // đưa hệ số lên
            }
            // nếu gtln nằm bên phải
            if (right < n && A[right] > A[largest]) 
            {
                largest = right; // đưa hệ số lên
            }
            // đưa giá trị lên vị trí max heap 
            if (largest != i) 
            { 
                int tam = A[i]; 
                A[i] = A[largest]; 
                A[largest] = tam; 
                max_heap(A, n, largest); 
            } 
        }
        // hàm sắp xếp chính của thuật toán
        static void HeapSort(int[] A, int n)
        {
            // tìm gt trị max đưa lên gốc Heap
            for (int i = n / 2 - 1; i >= 0; i--) 
            {
                max_heap(A, n, i); 
            }
            // đưa giá trị vừa tìm được xuống vị trí cuối của mảng đã sắp xếp
            for (int i = n-1; i>=0; i--)
            { 
                int temp = A[0]; 
                A[0] = A[i]; 
                A[i] = temp; 
                max_heap(A, i, 0); 
            } 
        } 
    }
    /*============================================================================*/
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
            Console.WriteLine("Mảng sau khi thực hiện Merge Sort: ");
            for (i = 0; i < input.Length; i++)
            {
                Console.Write("{0}\t",input[i]);
            }

            // Chạy thuật toán Heap Sort
            HEAPSORT hs = new HEAPSORT();
            hs.HeapSort(input, input.Length);
            Console.WriteLine("Mảng sau khi thực hiện Heap Sort: ");
            for (i = 0; i < input.Length; i++)
            {
                Console.Write("{0}\t",input[i]);
            }

            Console.ReadKey();
        }
    }
}